CREATE FUNCTION recount_document() RETURNS trigger AS $$
	DECLARE
		rec record;
		i record;
		pric int := 0;
    BEGIN
	
		for i in (select * from service where service.idservice = NEW.service_idservice)
		loop
			pric := i.price;
		end loop;
		
		UPDATE document 
		SET price = price + pric
		WHERE iddocument = NEW.document_iddocument;
		
        RETURN NEW;
    END;
$$ LANGUAGE plpgsql;

CREATE TRIGGER recount_document BEFORE INSERT ON document_service
    FOR EACH ROW EXECUTE PROCEDURE recount_document();