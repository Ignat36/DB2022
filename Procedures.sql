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

