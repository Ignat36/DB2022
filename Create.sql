DROP SCHEMA public CASCADE;
CREATE SCHEMA public;

CREATE TABLE IF NOT EXISTS body_styles
(
    id serial PRIMARY KEY,
    name character varying(45) NOT NULL
);

CREATE TABLE IF NOT EXISTS roles
(
    id serial PRIMARY KEY,
    name character varying(20) NOT NULL
);

CREATE TABLE IF NOT EXISTS brands
(
    id serial PRIMARY KEY,
    name character varying(45) NOT NULL
);

CREATE TABLE IF NOT EXISTS models
(
    id serial PRIMARY KEY,
    name character varying(45) NOT NULL,
    brand integer NOT NULL,
    body_style integer NOT NULL,
	FOREIGN KEY (brand)
    	REFERENCES brands (id)
    	ON DELETE CASCADE,
	
	FOREIGN KEY (body_style)
    	REFERENCES body_styles (id)
    	ON DELETE CASCADE
);

CREATE TABLE IF NOT EXISTS persons
(
    id serial PRIMARY KEY,
    full_name character varying(45) NOT NULL,
    phone character varying(20) NOT NULL,
    email character varying(45) NOT NULL,
	login character varying(45) NOT NULL,
	password character varying(60) NOT NULL, 
	role integer NOT NULL,
	
	FOREIGN KEY (role)
    	REFERENCES roles (id)
    	ON DELETE CASCADE
);



CREATE TABLE IF NOT EXISTS providers
(
    id serial PRIMARY KEY,
    name character varying(45) NOT NULL,
    phone character varying(20),
    email character varying(45)
);

CREATE TABLE IF NOT EXISTS clients
(
    id integer PRIMARY KEY NOT NULL,
    last_visit date NOT NULL,
	
	FOREIGN KEY (id)
    	REFERENCES persons (id)
    	ON DELETE CASCADE
);

CREATE TABLE IF NOT EXISTS qualifications
(
    id serial PRIMARY KEY NOT NULL,
    description character varying(60)
);

CREATE TABLE IF NOT EXISTS workers
(
    salary real NOT NULL,
    hire_date date NOT NULL,
    unpaid_hours integer NOT NULL,
    paid_hours integer NOT NULL,
    personal_qualities character varying(300),
    id integer PRIMARY KEY NOT NULL,
	
	FOREIGN KEY (id)
    	REFERENCES persons (id)
    	ON DELETE CASCADE
);

CREATE TABLE IF NOT EXISTS shifts
(
    id serial PRIMARY KEY NOT NULL,
    starts_at timestamp NOT NULL,
	ends_at timestamp NOT NULL,
	required_qualification integer NOT NULL,
	worker integer,
	
	
	FOREIGN KEY (required_qualification)
    	REFERENCES qualifications (id)
    	ON DELETE CASCADE,
	
	FOREIGN KEY (worker)
    	REFERENCES workers (id)
    	ON DELETE CASCADE
);

CREATE TABLE IF NOT EXISTS equipment
(
    id serial PRIMARY KEY,
    name character varying(45) NOT NULL,
    description character varying(300) NOT NULL,
    last_used timestamp NOT NULL,
	expiery_date date NOT NULL,
    price real NOT NULL,
	required_qualification integer NOT NULL,
	
	
	FOREIGN KEY (required_qualification)
    	REFERENCES qualifications (id)
    	ON DELETE CASCADE
);

CREATE TABLE IF NOT EXISTS services
(
    id serial PRIMARY KEY,
    description character varying(300) NOT NULL,
    price real NOT NULL,
    workload integer NOT NULL,
    name character varying(45) NOT NULL
);

CREATE TABLE IF NOT EXISTS cars
(
    id serial PRIMARY KEY,
    client integer NOT NULL,
    model integer NOT NULL,
	
	FOREIGN KEY (client)
    	REFERENCES clients (id)
    	ON DELETE CASCADE,

	FOREIGN KEY (model)
    	REFERENCES models (id)
    	ON DELETE CASCADE
);

CREATE TABLE IF NOT EXISTS cash_accounts
(
    id serial PRIMARY KEY,
    number character varying(30) NOT NULL,
    person integer,
	FOREIGN KEY (person)
    	REFERENCES persons (id)
    	ON DELETE CASCADE
);

CREATE TABLE IF NOT EXISTS cash_transfers
(
    id serial PRIMARY KEY,
    amount real NOT NULL,
    account integer NOT NULL,
	date timestamp NOT NULL,
    type character varying(10) NOT NULL,
	
	FOREIGN KEY (account)
    	REFERENCES cash_accounts (id)
    	ON DELETE CASCADE
);

CREATE TABLE IF NOT EXISTS taxes
(
	id serial PRIMARY KEY,
	description character varying(300) NOT NULL,
	amount real NOT NULL,
	transfer integer NOT NULL,
	
	FOREIGN KEY (transfer)
    	REFERENCES cash_transfers (id)
    	ON DELETE CASCADE
);

CREATE TABLE IF NOT EXISTS discounts
(
	id serial PRIMARY KEY,
	service integer NOT NULL,
	factor real NOT NULL,
	
	FOREIGN KEY (service)
    	REFERENCES services (id)
    	ON DELETE CASCADE
);

CREATE TABLE IF NOT EXISTS reviews
(
	id serial PRIMARY KEY,
	review character varying(300) NOT NULL,
	person integer,
	
	FOREIGN KEY (person)
    	REFERENCES persons (id)
    	ON DELETE CASCADE
);

-- Штрафы работникам
CREATE TABLE IF NOT EXISTS penalties
(
	id serial PRIMARY KEY,
	worker integer NOT NULL,
	description character varying(300) NOT NULL,
	date date NOT NULL,
	amount real NOT NULL,
	
	FOREIGN KEY (worker)
    	REFERENCES workers (id)
    	ON DELETE CASCADE
);

-- Расходы на аренду, комуналку и т.д.
CREATE TABLE IF NOT EXISTS expenses
(
	id serial PRIMARY KEY,
	description character varying(300) NOT NULL,
	transfer integer NOT NULL,
	
	FOREIGN KEY (transfer)
    	REFERENCES cash_transfers (id)
    	ON DELETE CASCADE
);

CREATE TABLE IF NOT EXISTS documents
(
    id serial PRIMARY KEY,
    contract character varying(1000),
    start_at date,
    end_at date,
    car integer NOT NULL,
	
	FOREIGN KEY (car)
    	REFERENCES cars (id)
    	ON DELETE CASCADE
);

-- Доплаты клиентами
CREATE TABLE IF NOT EXISTS surcharges
(
	id serial PRIMARY KEY,
	description character varying(300) NOT NULL,
	document integer NOT NULL,
	amount real NOT NULL,
	
	FOREIGN KEY (document)
    	REFERENCES documents (id)
    	ON DELETE CASCADE
);

-- В услугах будет устранение найденных дефектов
CREATE TABLE IF NOT EXISTS breakdowns
(
    id serial PRIMARY KEY,
    price real NOT NULL,
    workload integer NOT NULL,
	document integer NOT NULL,
	description character varying(300) NOT NULL,
	
	FOREIGN KEY (document)
    	REFERENCES documents (id)
    	ON DELETE CASCADE
);

-- внешние дефекты и неисправности, не требующие починки, но за которые потом чел предъявит
CREATE TABLE IF NOT EXISTS defects
(
    id serial PRIMARY KEY,
    description character varying(100) NOT NULL,
	document integer NOT NULL,
	
	FOREIGN KEY (document)
    	REFERENCES documents (id)
    	ON DELETE CASCADE
);

CREATE TABLE IF NOT EXISTS transportation_costs
(
	id serial PRIMARY KEY,
	document integer NOT NULL,
	description character varying(300) NOT NULL,
	price real NOT NULL,
	
	FOREIGN KEY (document)
    	REFERENCES documents (id)
    	ON DELETE NO ACTION
);

CREATE TABLE IF NOT EXISTS document_service
(
    document integer NOT NULL,
    service integer NOT NULL,
	
	FOREIGN KEY (document)
    	REFERENCES documents (id)
    	ON DELETE NO ACTION,
	
	FOREIGN KEY (service)
    	REFERENCES services (id)
    	ON DELETE NO ACTION
);

CREATE TABLE IF NOT EXISTS service_equipment
(
    service integer NOT NULL,
    equipment integer NOT NULL,
	
	FOREIGN KEY (service)
    	REFERENCES services (id)
    	ON DELETE NO ACTION,
	
	FOREIGN KEY (equipment)
    	REFERENCES equipment (id)
    	ON DELETE NO ACTION
);

CREATE TABLE IF NOT EXISTS worker_document
(
    worker integer NOT NULL,
    document integer NOT NULL,
	
	FOREIGN KEY (worker)
    	REFERENCES workers (id)
    	ON DELETE NO ACTION,
	
	FOREIGN KEY (document)
    	REFERENCES documents (id)
    	ON DELETE NO ACTION
);

CREATE TABLE IF NOT EXISTS worker_qualification
(
    worker integer NOT NULL,
    qualification integer NOT NULL,
	
	FOREIGN KEY (worker)
    	REFERENCES workers (id)
    	ON DELETE NO ACTION,
	
	FOREIGN KEY (qualification)
    	REFERENCES qualifications (id)
    	ON DELETE NO ACTION
);

CREATE TABLE IF NOT EXISTS components
(
    id serial PRIMARY KEY,
    name character varying(60) NOT NULL,
    price real NOT NULL,
    date_of_manufacture date NOT NULL,
	provider integer,
	document integer NOT NULL,
	serial_number character varying(60) NOT NULL,
	
	FOREIGN KEY (provider)
    	REFERENCES providers (id)
    	ON DELETE CASCADE,
	
	FOREIGN KEY (document)
    	REFERENCES documents (id)
    	ON DELETE CASCADE
);