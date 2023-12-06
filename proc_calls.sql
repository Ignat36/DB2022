call add_model('Игнат', 'Игнат', 'Игнат');

CALL add_job(
    'John Doe', -- p_client_full_name
    '123-456-7890', -- p_client_phone
    'john.doe@example.com', -- p_client_email
	'client', -- login
	'client', -- password
    'Toyota Camry', -- p_model_name
    'Toyota', -- p_brand_name
    'Седан', -- p_body_style_name
    ARRAY[1, 2, 3], -- p_services_ids
    'Contract for John Doe', -- p_contract
    '2023-01-01'::date, -- p_start_at
    '2023-01-10'::date -- p_end_at
);
CALL add_job(
    'Alice Smith', -- p_client_full_name
    '987-654-3210', -- p_client_phone
    'alice.smith@example.com', -- p_client_email
	'client', -- login
	'client', -- password
    'Honda Accord', -- p_model_name
    'Honda', -- p_brand_name
    'Sedan', -- p_body_style_name
    ARRAY[4, 5], -- p_services_ids
    'Contract for Alice Smith', -- p_contract
    '2023-02-15'::date, -- p_start_at
    '2023-02-28'::date -- p_end_at
);
CALL add_job(
    'Bob Johnson', -- p_client_full_name
    '555-123-4567', -- p_client_phone
    'bob.johnson@example.com', -- p_client_email
	'client', -- login
	'client', -- password
    'Ford Mustang', -- p_model_name
    'Ford', -- p_brand_name
    'Coupe', -- p_body_style_name
    ARRAY[6, 7, 8], -- p_services_ids
    'Contract for Bob Johnson', -- p_contract
    '2023-03-10'::date, -- p_start_at
    '2023-03-20'::date -- p_end_at
);


CALL add_worker(
    'John Doe',
    '+123456789',
    'john.doe@example.com',
    'johndoe',
    'password123',
    30.00,
    '2023-01-15',
    'Hardworking and dedicated',
    ARRAY['Mechanic', 'Electrical Repairs']
);
CALL add_worker(
    'Alice Smith',
    '+987654321',
    'alice.smith@example.com',
    'alicesmith',
    'securepass',
    35.00,
    '2023-02-01',
    'Experienced in diagnostics',
    ARRAY['Diagnostic Specialist', 'Engine Tuning']
);
CALL add_worker(
    'Bob Johnson',
    '+111222333',
    'bob.johnson@example.com',
    'bobjohnson',
    'secretword',
    28.00,
    '2023-03-10',
    'Attention to detail',
    ARRAY['Oil Change', 'Tire Rotation']
);

call pay_salary(1);
call pay_salary(2);
call pay_salary(3);

update shifts
set worker = 1
where id = 2;

SELECT calculate_total_cost(1);
SELECT * FROM get_document_info(1);
SELECT * FROM get_document_costs(1);

SELECT add_component_to_document(1, 'CPU', 300.00, '2023-01-15', 'Intel', 'SN12345');
SELECT add_component_to_document(2, 'RAM', 80.00, '2023-02-20', 'Corsair', 'SN67890');
SELECT add_component_to_document(3, 'GPU', 500.00, '2023-03-25', 'NVIDIA', 'SNABCDE');



