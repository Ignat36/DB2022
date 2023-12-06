-- Trigger function to update unpaid_hours on shift insert or update
CREATE OR REPLACE FUNCTION update_unpaid_hours()
RETURNS TRIGGER AS $$
BEGIN
    IF TG_OP = 'INSERT' THEN
        -- Add shift hours to the new worker's unpaid_hours if not null
        IF NEW.worker IS NOT NULL THEN
            UPDATE workers
            SET unpaid_hours = unpaid_hours + EXTRACT(HOUR FROM NEW.ends_at - NEW.starts_at)
            WHERE id = NEW.worker;
        END IF;
    ELSIF TG_OP = 'UPDATE' THEN
        -- Subtract hours from the old worker's unpaid_hours if not null
        IF OLD.worker IS NOT NULL THEN
            UPDATE workers
            SET unpaid_hours = unpaid_hours - EXTRACT(HOUR FROM OLD.ends_at - OLD.starts_at)
            WHERE id = OLD.worker;
        END IF;

        -- Add shift hours to the new worker's unpaid_hours if not null
        IF NEW.worker IS NOT NULL THEN
            UPDATE workers
            SET unpaid_hours = unpaid_hours + EXTRACT(HOUR FROM NEW.ends_at - NEW.starts_at)
            WHERE id = NEW.worker;
        END IF;
    END IF;

    RETURN NEW;
END;
$$ LANGUAGE plpgsql;

-- Trigger to call the trigger function on shift insert or update
CREATE TRIGGER shift_update_unpaid_hours
AFTER INSERT OR UPDATE ON shifts
FOR EACH ROW
EXECUTE FUNCTION update_unpaid_hours();


CREATE FUNCTION no_delete() RETURNS trigger AS $$
    BEGIN
        RETURN NULL;
    END;
$$ LANGUAGE plpgsql;
	

CREATE TRIGGER no_delete_role BEFORE DELETE OR UPDATE ON roles
    FOR EACH ROW EXECUTE PROCEDURE no_delete();