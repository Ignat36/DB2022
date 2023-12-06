CREATE OR REPLACE PROCEDURE add_model(
    IN p_brand_name character varying(45),
    IN p_body_style_name character varying(45),
    IN p_model_name character varying(45)
)
LANGUAGE plpgsql
AS $$
DECLARE
    v_brand_id integer;
    v_body_style_id integer;
    v_model_id integer;
BEGIN
    -- Проверка и добавление бренда
    SELECT id INTO v_brand_id FROM brands WHERE name = p_brand_name;
    IF v_brand_id IS NULL THEN
        INSERT INTO brands (name) VALUES (p_brand_name) RETURNING id INTO v_brand_id;
    END IF;

    -- Проверка и добавление типа кузова
    SELECT id INTO v_body_style_id FROM body_styles WHERE name = p_body_style_name;
    IF v_body_style_id IS NULL THEN
        INSERT INTO body_styles (name) VALUES (p_body_style_name) RETURNING id INTO v_body_style_id;
    END IF;

    -- Проверка и добавление модели
    SELECT id INTO v_model_id FROM models WHERE name = p_model_name AND brand = v_brand_id AND body_style = v_body_style_id;
    IF v_model_id IS NULL THEN
        INSERT INTO models (name, brand, body_style) VALUES (p_model_name, v_brand_id, v_body_style_id) RETURNING id INTO v_model_id;
    END IF;
END;
$$;

CREATE OR REPLACE PROCEDURE add_job(
    IN p_client_full_name character varying(45),
    IN p_client_phone character varying(20),
    IN p_client_email character varying(45),
	IN p_login character varying(45),
    IN p_password character varying(60),
    IN p_model_name character varying(45),
    IN p_brand_name character varying(45),
    IN p_body_style_name character varying(45),
    IN p_services_ids integer[],
    IN p_contract character varying(1000),
    IN p_start_at date,
    IN p_end_at date
)
LANGUAGE plpgsql
AS $$
DECLARE
    v_client_id integer;
    v_car_id integer;
	v_model_id integer;
    v_document_id integer;
    v_service_id integer;
BEGIN
    -- Проверка и добавление клиента в persons
    SELECT id INTO v_client_id FROM persons WHERE phone = p_client_phone;

    IF v_client_id IS NULL THEN
        -- Создание нового клиента, если его еще нет
        INSERT INTO persons (full_name, phone, email, login, password, role) 
        VALUES (p_client_full_name, p_client_phone, p_client_email, p_login, p_password, (SELECT id FROM roles WHERE name = 'Клиент')) 
        RETURNING id INTO v_client_id;
    END IF;

    -- Проверка и добавление клиента в clients
    INSERT INTO clients (id, last_visit) VALUES (v_client_id, CURRENT_DATE) ON CONFLICT (id) DO NOTHING;

    -- Проверка и добавление машины
    SELECT cars.id INTO v_car_id FROM cars
    JOIN models ON cars.model = models.id
    JOIN brands ON models.brand = brands.id
    JOIN body_styles ON models.body_style = body_styles.id
    WHERE brands.name = p_brand_name AND models.name = p_model_name AND body_styles.name = p_body_style_name AND cars.client = v_client_id;

    IF v_car_id IS NULL THEN
        -- Создание новой машины, если ее еще нет
		call add_model(p_brand_name, p_body_style_name, p_model_name);
		SELECT models.id INTO v_model_id FROM models
			JOIN brands ON models.brand = brands.id
			JOIN body_styles ON models.body_style = body_styles.id
			WHERE brands.name = p_brand_name AND models.name = p_model_name AND body_styles.name = p_body_style_name;
        INSERT INTO cars (client, model) VALUES (v_client_id, v_model_id) RETURNING id INTO v_car_id;
    END IF;

    -- Добавление записи о работе в documents
    INSERT INTO documents (contract, start_at, end_at, car) VALUES (p_contract, p_start_at, p_end_at, v_car_id) RETURNING id INTO v_document_id;

    -- Проверка и добавление услуг
    FOREACH v_service_id IN ARRAY p_services_ids
    LOOP
        -- Связываем услугу с документом
        INSERT INTO document_service (document, service) VALUES (v_document_id, v_service_id);
    END LOOP;
END;
$$;

CREATE OR REPLACE PROCEDURE add_worker(
    IN p_full_name character varying(45),
    IN p_phone character varying(20),
    IN p_email character varying(45),
    IN p_login character varying(45),
    IN p_password character varying(60),
    IN p_salary real,
    IN p_hire_date date,
    IN p_personal_qualities character varying(300),
    IN p_qualifications character varying[]
)
LANGUAGE plpgsql
AS $$
DECLARE
    v_worker_id integer;
	v_qualification_name character varying(60);
BEGIN
    -- Проверка существования телефона в persons
    SELECT id INTO v_worker_id FROM persons WHERE phone = p_phone;

    -- Если не существует, добавляем рабочего
    IF v_worker_id IS NULL THEN
        -- Добавление информации о рабочем
        INSERT INTO persons (full_name, phone, email, login, password, role) 
        VALUES (p_full_name, p_phone, p_email, p_login, p_password, (SELECT id FROM roles WHERE name = 'Рабочий')) 
        RETURNING id INTO v_worker_id;
		
		-- Добавление информации о рабочем
        INSERT INTO workers (id, salary, hire_date, unpaid_hours, paid_hours, personal_qualities) 
        VALUES (v_worker_id, p_salary, p_hire_date, 0, 0, p_personal_qualities);

		
        -- Добавление квалификаций
        FOREACH v_qualification_name IN ARRAY p_qualifications
        LOOP
            -- Проверка существования квалификации
            IF NOT EXISTS (SELECT 1 FROM qualifications WHERE description = v_qualification_name) THEN
                -- Добавление новой квалификации
                INSERT INTO qualifications (description) VALUES (v_qualification_name);
            END IF;

            -- Связываем квалификацию с рабочим
            INSERT INTO worker_qualification (worker, qualification) 
            VALUES (v_worker_id, (SELECT id FROM qualifications WHERE description = v_qualification_name));
        END LOOP;
    END IF;
END;
$$;

CREATE OR REPLACE PROCEDURE pay_salary(IN p_worker_id integer)
LANGUAGE plpgsql
AS $$
DECLARE
    v_unpaid_hours integer;
    v_hourly_rate real;
    v_amount real;
BEGIN
    -- Get the unpaid hours and hourly rate for the worker
    SELECT unpaid_hours, salary INTO v_unpaid_hours, v_hourly_rate
    FROM workers
    WHERE id = p_worker_id;

    -- Calculate the amount to be paid
    v_amount := v_unpaid_hours * v_hourly_rate;

    -- Insert a cash transfer record for the payment
    INSERT INTO cash_transfers (amount, account, date, type)
    VALUES (v_amount, (SELECT id FROM cash_accounts WHERE person = p_worker_id), NOW(), 'Salary');

    -- Update the worker's paid and unpaid hours
    UPDATE workers
    SET paid_hours = paid_hours + v_unpaid_hours, unpaid_hours = 0
    WHERE id = p_worker_id;
END;
$$;

CREATE OR REPLACE FUNCTION calculate_total_cost(p_document_id INTEGER)
RETURNS REAL AS $$
DECLARE
    v_total_cost REAL := 0;
	v_tmp REAL := 0;
BEGIN
    -- Calculate total cost from document_service
    SELECT COALESCE(SUM(services.price), 0)
    INTO v_tmp
    FROM document_service
    JOIN services ON document_service.service = services.id
    WHERE document_service.document = p_document_id;
	v_total_cost := v_total_cost + v_tmp;
	
    -- Add cost from breakdowns
    SELECT COALESCE(SUM(price), 0)
    INTO v_tmp
    FROM breakdowns
    WHERE document = p_document_id;
	v_total_cost := v_total_cost + v_tmp;
	
    -- Add cost from surcharges
    SELECT COALESCE(SUM(amount), 0)
    INTO v_tmp
    FROM surcharges
    WHERE document = p_document_id;
	v_total_cost := v_total_cost + v_tmp;
	
    -- Add cost from transportation_costs
    SELECT COALESCE(SUM(price), 0)
    INTO v_tmp
    FROM transportation_costs
    WHERE document = p_document_id;
	v_total_cost := v_total_cost + v_tmp;
	
    -- Add cost from components
    SELECT COALESCE(SUM(price), 0)
    INTO v_tmp
    FROM components
    WHERE document = p_document_id;
	v_total_cost := v_total_cost + v_tmp;
	
    RETURN v_total_cost;
END;
$$ LANGUAGE plpgsql;

CREATE OR REPLACE FUNCTION get_document_info(p_document_id INTEGER)
RETURNS TABLE (
    document_id INTEGER,
    contract VARCHAR(1000),
    start_at DATE,
    end_at DATE,
    car_id INTEGER,
    client_id INTEGER,
    client_name VARCHAR(45),
    client_phone VARCHAR(20),
    client_email VARCHAR(45),
    model_name VARCHAR(45),
    brand_name VARCHAR(45),
    body_style_name VARCHAR(45),
    total_cost REAL
) AS $$
BEGIN
    RETURN QUERY
    SELECT
        d.id AS document_id,
        d.contract,
        d.start_at,
        d.end_at,
        d.car AS car_id,
        c.client,
        p.full_name AS client_name,
        p.phone AS client_phone,
        p.email AS client_email,
        m.name AS model_name,
        b.name AS brand_name,
        bs.name AS body_style_name,
        calculate_total_cost(d.id) AS total_cost
    FROM documents d
    JOIN cars c ON d.car = c.id
    JOIN persons p ON c.client = p.id
    JOIN models m ON c.model = m.id
    JOIN brands b ON m.brand = b.id
    JOIN body_styles bs ON m.body_style = bs.id
    WHERE d.id = p_document_id;

END;
$$ LANGUAGE plpgsql;

CREATE OR REPLACE FUNCTION get_document_costs(p_document_id INTEGER)
RETURNS TABLE (
    description VARCHAR(300),
    amount REAL
) AS $$
BEGIN
    RETURN QUERY
    SELECT
        s.name AS description,
        s.price AS amount
    FROM document_service ds
    JOIN services s ON ds.service = s.id
    WHERE ds.document = p_document_id

    UNION

    SELECT
        b.description AS description,
        b.price AS amount
    FROM breakdowns b
    WHERE b.document = p_document_id

    UNION

    SELECT
        su.description AS description,
        su.amount AS amount
    FROM surcharges su
    WHERE su.document = p_document_id

    UNION

    SELECT
        tc.description AS description,
        tc.price AS amount
    FROM transportation_costs tc
    WHERE tc.document = p_document_id

    UNION

    SELECT
        co.name AS description,
        co.price AS amount
    FROM components co
    WHERE co.document = p_document_id;

END;
$$ LANGUAGE plpgsql;

CREATE OR REPLACE FUNCTION add_component_to_document(
    p_document_id INTEGER,
    p_name VARCHAR(60),
    p_price REAL,
    p_date_of_manufacture DATE,
    p_provider_name VARCHAR(45),
    p_serial_number VARCHAR(60)
)
RETURNS INTEGER AS $$
DECLARE
    v_provider_id INTEGER;
    v_component_id INTEGER;
BEGIN

	IF p_provider_name != '' THEN
        -- Check if the provider exists, and insert if not
		SELECT id INTO v_provider_id
		FROM providers
		WHERE name = p_provider_name;

		IF v_provider_id IS NULL THEN
			INSERT INTO providers (name) VALUES (p_provider_name) RETURNING id INTO v_provider_id;
		END IF;
    END IF;
    

    -- Insert the component
    INSERT INTO components (name, price, date_of_manufacture, provider, document, serial_number)
    VALUES (p_name, p_price, p_date_of_manufacture, v_provider_id, p_document_id, p_serial_number)
    RETURNING id INTO v_component_id;

    RETURN v_component_id;
END;
$$ LANGUAGE plpgsql;






