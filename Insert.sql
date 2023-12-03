INSERT INTO body_styles(name) VALUES ('Седан');
INSERT INTO body_styles(name) VALUES ('Универсал');
INSERT INTO body_styles(name) VALUES ('Хэтчбек');
INSERT INTO body_styles(name) VALUES ('Лифтбек');
INSERT INTO body_styles(name) VALUES ('Купе');
INSERT INTO body_styles(name) VALUES ('Лимузин');
INSERT INTO body_styles(name) VALUES ('Кабриолет');
INSERT INTO body_styles(name) VALUES ('Внедорожник');
INSERT INTO body_styles(name) VALUES ('Микроавтобус');
INSERT INTO body_styles(name) VALUES ('Минивэн');
INSERT INTO body_styles(name) VALUES ('Родстер');
INSERT INTO body_styles(name) VALUES ('Пикап');
INSERT INTO body_styles(name) VALUES ('Фургон');
	
INSERT INTO brands(name) VALUES ('Acura');
INSERT INTO brands(name) VALUES ('Alfa Romeo');
INSERT INTO brands(name) VALUES ('Alpine');
INSERT INTO brands(name) VALUES ('Land Rover');
INSERT INTO brands(name) VALUES ('Lexus');
INSERT INTO brands(name) VALUES ('Lifan');
INSERT INTO brands(name) VALUES ('Aston Martin');
INSERT INTO brands(name) VALUES ('Audi');
INSERT INTO brands(name) VALUES ('Bentley');
INSERT INTO brands(name) VALUES ('BMW');
INSERT INTO brands(name) VALUES ('Bugatti');
INSERT INTO brands(name) VALUES ('Cadillac');
INSERT INTO brands(name) VALUES ('Chevrolet');
INSERT INTO brands(name) VALUES ('Chrysler');
INSERT INTO brands(name) VALUES ('Citroen');
INSERT INTO brands(name) VALUES ('Dodge');
INSERT INTO brands(name) VALUES ('Ferrari');
INSERT INTO brands(name) VALUES ('Fiat');
INSERT INTO brands(name) VALUES ('Ford');
INSERT INTO brands(name) VALUES ('Geely');
INSERT INTO brands(name) VALUES ('Honda');
INSERT INTO brands(name) VALUES ('Hyundai');
INSERT INTO brands(name) VALUES ('Infiniti');
INSERT INTO brands(name) VALUES ('Jaguar');
INSERT INTO brands(name) VALUES ('Jeep');
INSERT INTO brands(name) VALUES ('KIA');
INSERT INTO brands(name) VALUES ('Koenigsegg');
INSERT INTO brands(name) VALUES ('Lada');
INSERT INTO brands(name) VALUES ('Lamborghini');
INSERT INTO brands(name) VALUES ('УАЗ');
INSERT INTO brands(name) VALUES ('ВАЗ');
INSERT INTO brands(name) VALUES ('Volvo');
INSERT INTO brands(name) VALUES ('Volkswagen');
INSERT INTO brands(name) VALUES ('Toyota');
INSERT INTO brands(name) VALUES ('Tesla');
INSERT INTO brands(name) VALUES ('Suzuki');
INSERT INTO brands(name) VALUES ('Subaru');
INSERT INTO brands(name) VALUES ('smart');
INSERT INTO brands(name) VALUES ('Skoda');
INSERT INTO brands(name) VALUES ('SEAT');
INSERT INTO brands(name) VALUES ('Rolls-Royce');
INSERT INTO brands(name) VALUES ('Renault');
INSERT INTO brands(name) VALUES ('Range Rover');
INSERT INTO brands(name) VALUES ('Porsche');
INSERT INTO brands(name) VALUES ('Opel');
INSERT INTO brands(name) VALUES ('Nissan');
INSERT INTO brands(name) VALUES ('Mitsubishi');
INSERT INTO brands(name) VALUES ('Mercedes-Benz');
INSERT INTO brands(name) VALUES ('MCLaren');
INSERT INTO brands(name) VALUES ('Mazda');
INSERT INTO brands(name) VALUES ('Maybach');
INSERT INTO brands(name) VALUES ('Maserati');
INSERT INTO brands(name) VALUES ('Lotus');

INSERT INTO roles(name) VALUES ('Админ');
INSERT INTO roles(name) VALUES ('Менеджер');
INSERT INTO roles(name) VALUES ('Рабочий');
INSERT INTO roles(name) VALUES ('Клиент');

INSERT INTO persons(full_name, phone, email, login, password, role)
	VALUES 
	(
		'Леонов Александр Михайлович', 
		'+375298608283',
		'PunchBubbaFalling@gmail.com',
		'worker1',
		'worker1',
		3
	);
INSERT INTO persons(full_name, phone, email, login, password, role)
	VALUES 
	(
		'Фролов Пётр Ярославович', 
		'+375296142155',
		'CrackedGlow@gmail.com',
		'worker2',
		'worker2',
		3
	);
INSERT INTO persons(full_name, phone, email, login, password, role)
	VALUES 
	(
		'Кулешов Роман Егорович', 
		'+375295469723',
		'GermCliffTwig@gmail.com',
		'worker3',
		'worker3',
		3
	);
INSERT INTO persons(full_name, phone, email, login, password, role)
	VALUES 
	(
		'Кузнецова Злата Макаровна', 
		'+375292562129',
		'SadColt@gmail.com',
		'worker4',
		'worker4',
		3
	);
INSERT INTO persons(full_name, phone, email, login, password, role)
	VALUES 
	(
		'Николаев Всеволод Кириллович', 
		'+375298329036',
		'YarnReady@gmail.com',
		'worker5',
		'worker5',
		3
	);
INSERT INTO persons(full_name, phone, email, login, password, role)
	VALUES 
	(
		'Петрова Дария Борисовна', 
		'+375295359150',
		'MagnumCrowdEcho@gmail.com',
		'client1',
		'client1',
		4
	);
INSERT INTO persons(full_name, phone, email, login, password, role)
	VALUES 
	(
		'Коновалова Арина Мироновна', 
		'+375293243738',
		'CultistSelection@gmail.com',
		'client2',
		'client2',
		4
	);
INSERT INTO persons(full_name, phone, email, login, password, role)
	VALUES 
	(
		'Петров Кирилл Матвеевич', 
		'+375293594264',
		'EraserGunGame@gmail.com',
		'client3',
		'client3',
		4
	);
INSERT INTO persons(full_name, phone, email, login, password, role)
	VALUES 
	(
		'Павлов Всеволод Владиславович', 
		'+375296654715',
		'GeoTouch@gmail.com',
		'client4',
		'client4',
		4
	);
INSERT INTO persons(full_name, phone, email, login, password, role)
	VALUES 
	(
		'Аксенов Данила Русланович', 
		'+375295808266',
		'GirlHawkCamel@gmail.com',
		'client5',
		'client5',
		4
	);
	
INSERT INTO persons(full_name, phone, email, login, password, role)
	VALUES 
	(
		'Аксенов Данила Русланович Кезик', 
		'+375295808265',
		'GirlHawkCamelTozik@gmail.com',
		'admin',
		'admin',
		1
	);
	
INSERT INTO persons(full_name, phone, email, login, password, role)
	VALUES 
	(
		'Аксенов Данила Русланович Шаргородский', 
		'+375295808265',
		'GirlHawkCamelShar@gmail.com',
		'manager',
		'manager',
		2
	);
	
INSERT INTO services(description, price, workload, name)
	VALUES 
	(
		'Данный вид слесарного ремонта рассчитан на диагностику и, в случае выявления мелких неполадок, их устранение. При таком подходе выполняют замену поршневых колец, элементов системы амортизации, деталей тормозной системы и прочее.',
		'1000',
		'100',
		'Текущий слесарный ремонт'
	);	
INSERT INTO services(description, price, workload, name)
	VALUES 
	(
		'При таком ремонте автомобиль разбирается и определяется степень износа каждой детали. Комплектующие, имеющие степень износа выше рекомендованной производителем, подлежат замене.',
		'2000',
		'300',
		'Капитальный слесарный ремонт'
	);	
INSERT INTO services(description, price, workload, name)
	VALUES 
	(
		'Появление незначительных вмятин исправляется даже без покрасочных работ при условии, что лакокрасочное покрытие не разрушено. Для этого используют резиновый молоток в легкодоступных местах или специальные крючки, рычаги и клюшки на труднодоступных участках кузова.',
		'500',
		'100',
		'Удаление вмятин и рихтовка'
	);	
INSERT INTO services(description, price, workload, name)
	VALUES 
	(
		'Нарушение целостности кузова исправляется посредством сварочных работ. Для этого используются два типа оборудования: электродный сварочный аппарат и плазменная резка. При использовании этих приборов, вдоль сварочного шва железо не деформируется.',
		'600',
		'200',
		'Сварочные работы'
	);	
INSERT INTO services(description, price, workload, name)
	VALUES 
	(
		'Под покраской подразумевается несколько этапов: работа с кузовом на специальном посте подготовки; обработка лакокрасочным материалом в покрасочной камере; сушка в сушильной камере. В покрасочной камере создаются такие условия, где даже в воздухе отсутствуют загрязнения.',
		'300',
		'100',
		'Покраска'
	);	
INSERT INTO services(description, price, workload, name)
	VALUES 
	(
		'Речь идет не только об автосигнализации, но и о механической защите. Данная услуга может быть как бюджетной, что характеризуется простой установкой иммобилайзера, так и дорогой, когда создается комплексная защита автомобиля.',
		'700',
		'100',
		'Установка охранных систем'
	);	
INSERT INTO services(description, price, workload, name)
	VALUES 
	(
		'Заводские сетки радиатора изготавливаются из пластика с минимальным расстоянием между ребрами в 2 сантиметра. Чтобы исключить попадание в радиатор постороннего мусора, имеющего меньший размер, рекомендуется установка защитной сетки.',
		'50',
		'24',
		'Сетка для защиты радиатора'
	);	
INSERT INTO services(description, price, workload, name)
	VALUES 
	(
		'После проведения мероприятий по шумоизоляции, заметно снижается уровень шума, поступающего в салон автомобиля с улицы. Кроме того, такие явления, как дребезжание отдельных элементов кузова, посторонние скрипы и стуки полностью устраняются.',
		'500',
		'100',
		'Шумоизоляция авто'
	);	
INSERT INTO services(description, price, workload, name)
	VALUES 
	(
		'Данное предложение автосервисов подразумевает нанесение на лобовое стекло тончайшего покрытия с высокими водоотталкивающими свойствами. Благодаря такому покрытию, на скорости свыше 60 км/ч дождевая вода будет эффективнее стекать по стеклу, практически без помощи дворников. ',
		'100',
		'48',
		'Антидождь'
	);	
INSERT INTO services(description, price, workload, name)
	VALUES 
	(
		'Благодаря тонировочной пленке можно не только улучшить внешний вид экстерьера автомобиля, но и сделать пребывание в салоне более комфортным. Это обусловлено поглощением части солнечных лучей пленкой. Чем она темнее, тем больше световых лучей поглощается.',
		'200',
		'100',
		'Тонировка стекол'
	);	
INSERT INTO services(description, price, workload, name)
	VALUES 
	(
		'Установка данного приспособления позволяет предотвратить запотевание лобового стекла в салоне, а потому видимость не ухудшается при разности температур внешней и внутренней стороны стекла. Эксплуатационный срок антизапотевателя составляет примерно 4 месяца.',
		'50',
		'48',
		'Антизапотеватель'
	);	
	
INSERT INTO models(name, brand, body_style)
	VALUES 
	(
		'M8 Coupe',
		10,
		5
	);	
INSERT INTO models(name, brand, body_style)
	VALUES 
	(
		'E34',
		10,
		1
	);	
INSERT INTO models(name, brand, body_style)
	VALUES 
	(
		'Vesta',
		28,
		1
	);	
INSERT INTO models(name, brand, body_style)
	VALUES 
	(
		'Granta',
		28,
		1
	);	
INSERT INTO models(name, brand, body_style)
	VALUES 
	(
		'Rio',
		26,
		1
	);
	
INSERT INTO cash_accounts(number, person)
	VALUES 
	(
		'17409488245517115276',
		1
	);	
INSERT INTO cash_accounts(number, person)
	VALUES 
	(
		'31233411387427793198',
		3
	);	
INSERT INTO cash_accounts(number, person)
	VALUES 
	(
		'14232216857618927954',
		2
	);	
INSERT INTO cash_accounts(number, person)
	VALUES 
	(
		'65028602486509006138',
		4
	);	
INSERT INTO cash_accounts(number, person)
	VALUES 
	(
		'93446066184963788291',
		5
	);	
INSERT INTO cash_accounts(number, person)
	VALUES 
	(
		'35984076361542097372',
		6
	);	
INSERT INTO cash_accounts(number, person)
	VALUES 
	(
		'60165754120014607177',
		7
	);	
INSERT INTO cash_accounts(number, person)
	VALUES 
	(
		'77335998182660380125',
		8
	);	
INSERT INTO cash_accounts(number, person)
	VALUES 
	(
		'09478351201640618984',
		9
	);	
INSERT INTO cash_accounts(number, person)
	VALUES 
	(
		'14398808778383710734',
		10
	);
	
INSERT INTO clients(id, last_visit)
	VALUES 
	(
		6,
		'2022-06-23'
	);	
INSERT INTO clients(id, last_visit)
	VALUES 
	(
		7,
		'2022-01-10'
	);	
INSERT INTO clients(id, last_visit)
	VALUES 
	(
		8,
		'2022-09-01'
	);	
INSERT INTO clients(id, last_visit)
	VALUES 
	(
		9,
		'2022-10-19'
	);	
INSERT INTO clients(id, last_visit)
	VALUES 
	(
		10,
		'2022-11-21'
	);

INSERT INTO workers(salary, hire_date, unpaid_hours, paid_hours, personal_qualities, id)
	VALUES 
	(
		'15', 
		'2016-06-23', 
		'0', 
		'19545', 
		'Норм чел', 
		'1'
	);	
INSERT INTO workers(salary, hire_date, unpaid_hours, paid_hours, personal_qualities, id)
	VALUES 
	(
		'14', 
		'2017-06-23', 
		'0', 
		'16545', 
		'Норм чел, играет в доту', 
		'2'
	);	
INSERT INTO workers(salary, hire_date, unpaid_hours, paid_hours, personal_qualities, id)
	VALUES 
	(
		'20', 
		'2018-06-23', 
		'0', 
		'13545', 
		'Характер не оч. но свое дело знает.', 
		'3'
	);	
INSERT INTO workers(salary, hire_date, unpaid_hours, paid_hours, personal_qualities, id)
	VALUES 
	(
		'10', 
		'2020-06-23', 
		'10', 
		'4545', 
		'Душа коллектива', 
		'4'
	);	
INSERT INTO workers(salary, hire_date, unpaid_hours, paid_hours, personal_qualities, id)
	VALUES 
	(
		'9', 
		'2021-06-23', 
		'10', 
		'1545', 
		'Тихий, спокойный', 
		'5'
	);

INSERT INTO cash_transfers(amount, account, date, type)
	VALUES 
	(
		'1000',
		6, 
		TO_TIMESTAMP('2023-12-01 15:30:00', 'YYYY-MM-DD HH24:MI:SS'),
		'Client'
	);	
INSERT INTO cash_transfers(amount, account, date, type)
	VALUES 
	(
		'1500',
		7, 
		TO_TIMESTAMP('2023-12-02 15:30:00', 'YYYY-MM-DD HH24:MI:SS'),
		'Client'
	);	
INSERT INTO cash_transfers(amount, account, date, type)
	VALUES 
	(
		'50',
		8,
		TO_TIMESTAMP('2023-12-03 15:30:00', 'YYYY-MM-DD HH24:MI:SS'),
		'Client'
	);	
INSERT INTO cash_transfers(amount, account, date, type)
	VALUES 
	(
		'100',
		9,
		TO_TIMESTAMP('2023-12-04 15:30:00', 'YYYY-MM-DD HH24:MI:SS'),
		'Client'
	);	
INSERT INTO cash_transfers(amount, account, date, type)
	VALUES 
	(
		'2900',
		10,
		TO_TIMESTAMP('2023-12-05 15:30:00', 'YYYY-MM-DD HH24:MI:SS'), 
		'Client'
	);
INSERT INTO cars(client, model)
	VALUES 
	( 
		'6', 
		'1'
	);	
INSERT INTO cars(client, model)
	VALUES 
	( 
		'7', 
		'2'
	);	
INSERT INTO cars(client, model)
	VALUES 
	( 
		'8', 
		'3'
	);	
INSERT INTO cars(client, model)
	VALUES 
	( 
		'9', 
		'4'
	);	
INSERT INTO cars(client, model)
	VALUES 
	( 
		'10', 
		'5'
	);
	
INSERT INTO documents(contract, start_at, end_at, car)
	VALUES 
	(
		'', 
		'2022-01-01', 
		'2022-06-23', 
		'1'
	);	
INSERT INTO documents(contract, start_at, end_at, car)
	VALUES 
	(
		'', 
		'2022-01-01', 
		'2022-01-10', 
		'2'
	);	
INSERT INTO documents(contract, start_at, end_at, car)
	VALUES 
	(
		'', 
		'2022-01-01', 
		'2022-09-01', 
		'3'
	);	
INSERT INTO documents(contract, start_at, end_at, car)
	VALUES 
	(
		'', 
		'2022-01-01', 
		'2022-10-19', 
		'4'
	);	
INSERT INTO documents(contract, start_at, end_at, car)
	VALUES 
	(
		'', 
		'2022-01-01', 
		'2022-11-21', 
		'5'
	);
	
INSERT INTO document_service(document, service)
	VALUES 
	(
		1, 
		1
	);	
INSERT INTO document_service(document, service)
	VALUES 
	(
		2, 
		1
	);	
INSERT INTO document_service(document, service)
	VALUES 
	(
		2, 
		3
	);	
INSERT INTO document_service(document, service)
	VALUES 
	(
		3, 
		7
	);	
INSERT INTO document_service(document, service)
	VALUES 
	(
		4, 
		7
	);	
INSERT INTO document_service(document, service)
	VALUES 
	(
		4, 
		11
	);	
INSERT INTO document_service(document, service)
	VALUES 
	(
		5, 
		2
	);	
INSERT INTO document_service(document, service)
	VALUES 
	(
		5, 
		5
	);	
INSERT INTO document_service(document, service)
	VALUES 
	(
		5, 
		4
	);
	
INSERT INTO worker_document(worker, document)
	VALUES 
	(
		1, 
		1
	);	
INSERT INTO worker_document(worker, document)
	VALUES 
	(
		1, 
		2
	);	
INSERT INTO worker_document(worker, document)
	VALUES 
	(
		2, 
		3
	);	
INSERT INTO worker_document(worker, document)
	VALUES 
	(
		2, 
		4
	);	
INSERT INTO worker_document(worker, document)
	VALUES 
	(
		3, 
		4
	);	
INSERT INTO worker_document(worker, document)
	VALUES 
	(
		3, 
		1
	);	
INSERT INTO worker_document(worker, document)
	VALUES 
	(
		4, 
		1
	);	
INSERT INTO worker_document(worker, document)
	VALUES 
	(
		4, 
		2
	);	
INSERT INTO worker_document(worker, document)
	VALUES 
	(
		4, 
		4
	);	
INSERT INTO worker_document(worker, document)
	VALUES 
	(
		4, 
		5
	);	
INSERT INTO worker_document(worker, document)
	VALUES 
	(
		5, 
		5
	);	
INSERT INTO worker_document(worker, document)
	VALUES 
	(
		5, 
		4
	);	
INSERT INTO worker_document(worker, document)
	VALUES 
	(
		5, 
		3
	);	
INSERT INTO worker_document(worker, document)
	VALUES 
	(
		5, 
		2
	);	
INSERT INTO worker_document(worker, document)
	VALUES 
	(
		5, 
		1
	);	
INSERT INTO worker_document(worker, document)
	VALUES 
	(
		1, 
		5
	);	
INSERT INTO worker_document(worker, document)
	VALUES 
	(
		2, 
		5
	);
	
-- Вставка данных в таблицу qualifications
INSERT INTO qualifications (description) VALUES
    ('Специалист по диагностике'),
    ('Слесарь-ремонтник'),
    ('Автомаляр'),
    ('Сварщик'),
    ('Мастер по кузовному ремонту'),
    ('Электрик'),
    ('Монтажник охранных систем'),
    ('Технолог по покраске'),
    ('Шумоизолятор'),
    ('Техник по тонировке стекол'),
    ('Электромеханик');

-- Вставка данных в таблицу equipment
INSERT INTO equipment (name, description, last_used, expiery_date, price, required_qualification) VALUES
    ('Диагностический сканер', 'Современный сканер для диагностики автомобиля', '2023-12-01 10:30:00', '2025-01-01', 5000.00, 1),
    ('Набор инструментов для ремонта', 'Профессиональный инструмент для проведения слесарных работ', '2023-11-15 14:45:00', '2024-12-31', 3000.00, 2),
    ('Покрасочная камера', 'Специализированная камера для покраски автомобилей', '2023-10-20 16:00:00', '2024-11-30', 10000.00, 8),
    ('Сварочный аппарат', 'Электродный сварочный аппарат для проведения сварочных работ', '2023-11-05 12:00:00', '2024-10-31', 8000.00, 4),
    ('Монтажный стол', 'Стол для проведения монтажных работ на кузове', '2023-12-02 09:30:00', '2025-02-28', 6000.00, 5),
    ('Электрический тестер', 'Тестер для проверки электрических систем автомобиля', '2023-12-03 08:00:00', '2024-09-30', 2000.00, 6),
    ('Оборудование для установки охранных систем', 'Набор инструментов для установки сигнализаций', '2023-11-25 11:15:00', '2024-08-31', 3000.00, 7),
    ('Шумоизоляционный материал', 'Материал для проведения работ по шумоизоляции автомобиля', '2023-10-15 13:45:00', '2024-09-30', 1000.00, 9),
    ('Оборудование для тонировки стекол', 'Специализированное оборудование для тонировки стекол', '2023-12-02 10:30:00', '2024-11-30', 4000.00, 10),
    ('Антизапотеватель', 'Устройство для предотвращения запотевания стекол', '2023-11-10 09:00:00', '2024-10-31', 800.00, 11),
    ('Электронный мультиметр', 'Измерительный прибор для работы с электрическими системами', '2023-10-05 15:30:00', '2024-12-31', 1500.00, 6),
    ('Диагностический осциллограф', 'Осциллограф для детальной диагностики электронных систем', '2023-11-20 11:30:00', '2024-11-30', 7000.00, 1),
    ('Рихтовочный молоток', 'Профессиональный молоток для рихтовки кузова', '2023-10-10 14:15:00', '2024-09-30', 500.00, 2),
    ('Пневматический пистолет для покраски', 'Инструмент для равномерного нанесения краски', '2023-10-25 16:30:00', '2024-12-31', 2000.00, 8),
    ('Плазменная резка', 'Оборудование для точной плазменной резки', '2023-12-01 09:00:00', '2025-01-31', 10000.00, 4),
    ('Плита для выправки деталей', 'Специализированная плита для выправки деформаций', '2023-11-15 13:00:00', '2024-10-31', 3000.00, 5),
    ('Индукционный обогреватель', 'Оборудование для быстрого обогрева и выправки деталей', '2023-12-05 10:45:00', '2025-02-28', 4000.00, 5),
    ('Оптический выравниватель', 'Прибор для точного выравнивания кузовных элементов', '2023-10-30 15:15:00', '2024-11-30', 6000.00, 5),
    ('Электронный сварочный аппарат', 'Аппарат для точной электронной сварки', '2023-11-10 12:30:00', '2024-10-31', 6000.00, 4),
    ('Автомобильный подъемник', 'Подъемник для поднятия автомобиля', '2023-10-18 14:00:00', '2024-09-30', 7000.00, 2),
    ('Лазерный регулировщик фар', 'Прибор для точной настройки автомобильных фар', '2023-11-05 11:30:00', '2024-12-31', 2500.00, 6),
    ('Инструмент для тонировки стекол', 'Специальный инструмент для проведения работ по тонировке стекол', '2023-12-02 15:30:00', '2024-11-30', 3000.00, 10);

INSERT INTO service_equipment (service, equipment) VALUES
    (1, 1), -- Диагностика и текущий слесарный ремонт -> Диагностический сканер
    (1, 2), -- Диагностика и текущий слесарный ремонт -> Набор инструментов для ремонта
    (2, 3), -- Капитальный слесарный ремонт -> Покрасочная камера
    (2, 4), -- Капитальный слесарный ремонт -> Сварочный аппарат
    (3, 5), -- Удаление вмятин и рихтовка -> Монтажный стол
    (3, 6), -- Удаление вмятин и рихтовка -> Электрический тестер
    (4, 7), -- Сварочные работы -> Оборудование для установки охранных систем
    (5, 8), -- Покраска -> Шумоизоляционный материал
    (6, 9), -- Установка охранных систем -> Сетка для защиты радиатора
    (7, 10), -- Шумоизоляция авто -> Оборудование для тонировки стекол
    (8, 11), -- Антидождь -> Антизапотеватель
    (9, 12), -- Тонировка стекол -> Электронный мультиметр
    (10, 13), -- Антизапотеватель -> Диагностический осциллограф
    (11, 14), -- Продолжение вставки данных в таблицу equipment -> Рихтовочный молоток
    (4, 15), -- Сварочные работы -> Плита для выправки деталей
    (5, 16), -- Покраска -> Индукционный обогреватель
    (6, 17), -- Установка охранных систем -> Оптический выравниватель
    (7, 18), -- Шумоизоляция авто -> Электронный сварочный аппарат
    (8, 19), -- Антидождь -> Автомобильный подъемник
    (9, 20), -- Тонировка стекол -> Лазерный регулировщик фар
    (10, 21), -- Антизапотеватель -> Инструмент для тонировки стекол
    (11, 22); -- Продолжение вставки данных в таблицу equipment -> Антизапотеватель
	
-- Вставка данных в таблицу providers
INSERT INTO providers (name, phone, email) VALUES
    ('ООО "АвтоЗапчасти"', '+7 (123) 456-7890', 'info@avtozapchasti.ru'),
    ('ИП "Автоаксессуары"', '+7 (987) 654-3210', 'info@autoaksessuary.ru'),
    ('ТОО "АвтоСервис"', '+7 (111) 222-3333', 'info@autoservice.kz'),
    ('Группа компаний "Авто-Тех"', '+7 (555) 777-8888', 'info@auto-tech.com'),
    ('ООО "Автоэлектроника"', '+7 (999) 888-7777', 'info@autoelektronika.ru'),
	('ООО "Запчасти-Люкс"', '+7 (777) 555-4444', 'info@zapchasti-lyux.ru'),
    ('ИП "АвтоРезерв"', '+7 (333) 222-1111', 'info@autoreserve.ru'),
    ('ТОО "АвтоМагазин"', '+7 (888) 999-0000', 'info@automagazin.kz'),
    ('Группа компаний "Авто-Мастер"', '+7 (111) 333-5555', 'info@auto-master.com'),
    ('ООО "АвтоПром"', '+7 (666) 555-4444', 'info@autoprom.ru');

-- Вставка данных в таблицу shifts
INSERT INTO shifts (starts_at, ends_at, required_qualification, worker) VALUES
    ('2023-12-01 08:00:00', '2023-12-01 16:00:00', 2, 1),
    ('2023-12-02 12:00:00', '2023-12-02 20:00:00', 3, NULL),
    ('2023-12-03 09:00:00', '2023-12-03 17:00:00', 1, 2),
    ('2023-12-04 10:00:00', '2023-12-04 18:00:00', 4, NULL),
    ('2023-12-05 08:00:00', '2023-12-05 16:00:00', 2, 3),
    ('2023-12-06 14:00:00', '2023-12-06 22:00:00', 5, NULL),
    ('2023-12-07 11:00:00', '2023-12-07 19:00:00', 3, 4),
    ('2023-12-08 09:00:00', '2023-12-08 17:00:00', 1, NULL),
    ('2023-12-09 08:00:00', '2023-12-09 16:00:00', 2, 5),
    ('2023-12-10 12:00:00', '2023-12-10 20:00:00', 4, NULL),
	('2023-12-11 08:00:00', '2023-12-11 16:00:00', 1, NULL),
    ('2023-12-12 14:00:00', '2023-12-12 22:00:00', 2, NULL),
    ('2023-12-13 09:00:00', '2023-12-13 17:00:00', 3, NULL),
    ('2023-12-14 11:00:00', '2023-12-14 19:00:00', 4, 1),
    ('2023-12-15 10:00:00', '2023-12-15 18:00:00', 5, NULL),
    ('2023-12-16 08:00:00', '2023-12-16 16:00:00', 1, 2),
    ('2023-12-17 12:00:00', '2023-12-17 20:00:00', 2, NULL),
    ('2023-12-18 09:00:00', '2023-12-18 17:00:00', 3, 3),
    ('2023-12-19 08:00:00', '2023-12-19 16:00:00', 4, NULL),
    ('2023-12-20 14:00:00', '2023-12-20 22:00:00', 5, NULL),
    ('2023-12-21 11:00:00', '2023-12-21 19:00:00', 1, 4),
    ('2023-12-22 10:00:00', '2023-12-22 18:00:00', 2, NULL),
    ('2023-12-23 08:00:00', '2023-12-23 16:00:00', 3, 5),
    ('2023-12-24 12:00:00', '2023-12-24 20:00:00', 4, NULL),
    ('2023-12-25 09:00:00', '2023-12-25 17:00:00', 5, 1),
    ('2023-12-26 08:00:00', '2023-12-26 16:00:00', 1, NULL),
    ('2023-12-27 14:00:00', '2023-12-27 22:00:00', 2, NULL),
    ('2023-12-28 09:00:00', '2023-12-28 17:00:00', 3, NULL),
    ('2023-12-29 11:00:00', '2023-12-29 19:00:00', 4, 2),
    ('2023-12-30 10:00:00', '2023-12-30 18:00:00', 5, NULL),
    ('2023-12-31 08:00:00', '2023-12-31 16:00:00', 1, 3),
    ('2024-01-01 12:00:00', '2024-01-01 20:00:00', 2, NULL),
    ('2024-01-02 09:00:00', '2024-01-02 17:00:00', 3, NULL),
    ('2024-01-03 08:00:00', '2024-01-03 16:00:00', 4, 4),
    ('2024-01-04 14:00:00', '2024-01-04 22:00:00', 5, NULL),
    ('2024-01-05 11:00:00', '2024-01-05 19:00:00', 1, NULL),
    ('2024-01-06 10:00:00', '2024-01-06 18:00:00', 2, 5),
    ('2024-01-07 08:00:00', '2024-01-07 16:00:00', 3, NULL),
    ('2024-01-08 12:00:00', '2024-01-08 20:00:00', 4, NULL),
    ('2024-01-09 09:00:00', '2024-01-09 17:00:00', 5, NULL);
	
-- Вставка данных в таблицу cash_accounts
INSERT INTO cash_accounts (number) VALUES
    ('123456789012345'),
    ('234567890123456'),
    ('345678901234567'),
    ('456789012345678'),
	('456789012345673'),
	('456789012345672'),
	('456789012345671'),
	('456789012345670'),
	('456789012345679'),
    ('567890123456789');

-- Вставка данных в таблицу cash_transfers
INSERT INTO cash_transfers (amount, account, date, type) VALUES
    (1000.00, 11, '2023-12-01 10:00:00', 'Taxes'),
    (500.00, 12, '2023-12-02 12:30:00', 'Taxes'),
    (2000.00, 13, '2023-12-03 15:45:00', 'Taxes'),
    (1500.00, 14, '2023-12-04 09:20:00', 'Taxes'),
    (800.00, 15, '2023-12-05 14:00:00', 'Taxes'),
	(200.00, 11, '2023-12-06 09:30:00', 'Taxes'),
    (350.00, 12, '2023-12-07 13:15:00', 'Taxes'),
    (180.00, 13, '2023-12-08 16:45:00', 'Taxes'),
    (450.00, 14, '2023-12-09 10:30:00', 'Taxes'),
    (250.00, 15, '2023-12-10 12:00:00', 'Taxes'),
	(200.00, 11, '2023-12-11 09:30:00', 'Taxes'),
    (350.00, 12, '2023-12-12 13:15:00', 'Taxes'),
    (180.00, 13, '2023-12-13 16:45:00', 'Taxes'),
    (450.00, 14, '2023-12-14 10:30:00', 'Taxes'),
    (250.00, 15, '2023-12-15 12:00:00', 'Taxes'),
    (300.00, 11, '2023-12-16 14:30:00', 'Taxes'),
    (180.00, 12, '2023-12-17 17:15:00', 'Taxes'),
    (90.00, 13, '2023-12-18 09:45:00', 'Taxes'),
    (100.00, 14, '2023-12-19 11:20:00', 'Taxes'),
    (250.00, 15, '2023-12-20 14:00:00', 'Taxes'),
    (300.00, 11, '2023-12-21 16:30:00', 'Taxes'),
    (70.00, 12, '2023-12-22 19:15:00', 'Taxes'),
    (130.00, 13, '2023-12-23 10:45:00', 'Taxes'),
    (110.00, 14, '2023-12-24 12:20:00', 'Taxes'),
    (90.00, 15, '2023-12-25 14:50:00', 'Taxes'),
    (220.00, 11, '2023-12-26 17:30:00', 'Taxes'),
    (200.00, 12, '2023-12-27 20:15:00', 'Taxes'),
    (40.00, 13, '2023-12-28 09:00:00', 'Taxes'),
    (120.00, 14, '2023-12-29 11:30:00', 'Taxes'),
    (70.00, 15, '2023-12-30 14:00:00', 'Taxes'),
    (60.00, 15, '2023-12-31 16:30:00', 'Taxes'),
    (140.00, 11, '2024-01-01 19:15:00', 'Taxes'),
    (80.00, 13, '2024-01-02 10:45:00', 'Taxes'),
    (180.00, 12, '2024-01-03 12:20:00', 'Taxes'),
    (150.00, 11, '2024-01-04 14:50:00', 'Taxes'),
    (110.00, 11, '2024-01-05 17:30:00', 'Taxes'),
    (120.00, 12, '2024-01-06 20:15:00', 'Taxes'),
    (100.00, 13, '2024-01-07 09:00:00', 'Taxes'),
    (50.00, 14, '2024-01-08 11:30:00', 'Taxes'),
    (75.00, 15, '2024-01-09 14:00:00', 'Taxes');

-- Вставка данных в таблицу taxes
INSERT INTO taxes (description, amount, transfer) VALUES
    ('Налог на доходы', 150.00, 6),
    ('Налог на имущество', 75.00, 7),
    ('Налог на продажи', 300.00, 8),
    ('Налог на прибыль', 200.00, 9),
    ('Налог на транспорт', 100.00, 10),
	('Земельный налог', 50.00, 11),
    ('Налог на добавленную стоимость (НДС)', 120.00, 12),
    ('Акцизный налог', 80.00, 13),
    ('Налог на прибыль организаций', 300.00, 14),
    ('Транспортный налог', 90.00, 15),
	('Налог на недвижимость', 80.00, 16),
    ('Налог на прибыль физических лиц', 120.00, 17),
    ('Торговый сбор', 50.00, 18),
    ('Акциз на алкогольные напитки', 200.00, 19),
    ('Страховые взносы', 150.00, 20),
    ('Земельный налог', 60.00, 21),
    ('Налог на добавленную стоимость (НДС)', 180.00, 22),
    ('Транспортный налог', 90.00, 23),
    ('Налог на природопользование', 100.00, 24),
    ('Акциз на табачные изделия', 250.00, 25),
    ('Налог на игорный бизнес', 300.00, 26),
    ('Налог на использование водных объектов', 70.00, 27),
    ('Единый социальный налог', 130.00, 28),
    ('Налог на транспортные средства', 110.00, 29),
    ('Налог на профессиональный доход', 90.00, 30),
    ('Акциз на автотранспорт', 220.00, 31),
    ('Налог на добычу полезных ископаемых', 200.00, 32),
    ('Загрязнение окружающей среды', 40.00, 33),
    ('Налог на игровые автоматы', 120.00, 34),
    ('Страхование от несчастных случаев', 70.00, 35),
    ('Налог на хранение отходов', 60.00, 36),
    ('Единый налог на вмененный доход', 140.00, 37),
    ('Налог на вывоз отходов', 80.00, 38),
    ('Акциз на пиво', 180.00, 39),
    ('Налог на имущество предприятий', 150.00, 40),
    ('Транзитный налог', 110.00, 41),
    ('Налог на легковые автомобили', 120.00, 42),
    ('Единый налог на водные объекты', 100.00, 43),
    ('Налог на рекламу', 50.00, 44),
    ('Налог на использование объектов животного мира', 75.00, 45);

-- Вставка данных в таблицу discounts
INSERT INTO discounts (service, factor) VALUES
    (1, 0.9),
    (3, 0.8),
    (5, 0.95),
    (2, 0.85);
	
INSERT INTO reviews (review, person) VALUES
    ('Отличный сервис, всё сделали быстро и качественно!', 6),
    ('Немного задержались с ремонтом, но результат порадовал.', 7),
    ('Профессиональный подход, всё рассказали и показали.', 8),
    ('Цены не самые низкие, но качество работ заслуживает.', 9),
    ('Вежливый персонал, хороший сервис, рекомендую.', 10);
	
-- Вставка данных в таблицу penalties
INSERT INTO penalties (worker, description, date, amount) VALUES
    (1, 'Опоздание на работу', '2023-12-01', 50.00),
    (2, 'Невыполнение задания', '2023-12-02', 100.00),
    (3, 'Использование ненадлежащего оборудования', '2023-12-03', 75.00),
    (4, 'Нарушение техники безопасности', '2023-12-04', 120.00),
    (5, 'Небрежное обращение с инструментами', '2023-12-05', 80.00);
	
INSERT INTO cash_transfers (amount, account, date, type) VALUES
    (1500.00, 16, '2023-12-10 10:00:00', 'Expense'),
    (500.00, 17, '2023-12-11 12:30:00', 'Expense'),
    (800.00, 18, '2023-12-12 15:45:00', 'Expense'),
    (1200.00, 19, '2023-12-13 09:20:00', 'Expense'),
    (1000.00, 20, '2023-12-14 14:00:00', 'Expense');
	
INSERT INTO expenses (description, transfer) VALUES
    ('Аренда офиса', 46),
    ('Коммунальные платежи', 47),
    ('Офисное оборудование', 48),
    ('Реклама и маркетинг', 49),
	('Печеньки с чаем', 50);
	
-- Вставка данных в таблицу surcharges
INSERT INTO surcharges (description, document, amount) VALUES
    ('Доплата за ускоренное обслуживание', 1, 50.00),
    ('Доплата за использование оригинальных запчастей', 2, 100.00),
    ('Доплата за экспресс-доставку деталей', 3, 75.00),
    ('Доплата за дополнительные услуги', 4, 120.00),
    ('Доплата за гарантированный срок ремонта', 5, 80.00);
	
INSERT INTO breakdowns (price, workload, document, description) VALUES
    (200.00, 10, 1, 'Замена поршневых колец и амортизаторов'),
    (300.00, 15, 2, 'Замена тормозной системы и деталей'),
    (150.00, 8, 3, 'Диагностика и устранение мелких неполадок'),
    (400.00, 20, 4, 'Замена изношенных деталей'),
    (250.00, 12, 5, 'Устранение вмятин и рихтовка кузова');
	
-- Вставка данных в таблицу defects
INSERT INTO defects (description, document) VALUES
    ('Мелкие царапины на кузове', 1),
    ('Незначительные потертости на лобовом стекле', 2),
    ('Легкие сколы краски', 3),
    ('Минимальные дефекты на бампере', 4),
    ('Мелкие царапины на двери', 5);

-- Вставка данных в таблицу transportation_costs
INSERT INTO transportation_costs (document, description, price) VALUES
    (1, 'Транспортировка до сервиса', 50.00),
    (2, 'Доставка запчастей', 30.00),
    (3, 'Транспортировка автомобиля клиента', 40.00),
    (4, 'Доставка деталей для ремонта', 35.00),
    (5, 'Транспортировка до покрасочной мастерской', 60.00);

-- Вставка данных в таблицу components
INSERT INTO components (name, price, date_of_manufacture, provider, document, serial_number) VALUES
    ('Двигатель', 3000.00, '2023-01-15', 1, 1, 'ENG123'),
    ('Тормозные колодки', 100.00, '2023-02-20', 2, 2, 'BRK456'),
    ('Фильтр масляный', 20.00, '2023-03-10', 3, 3, 'OIL789'),
    ('Аккумулятор', 150.00, '2023-04-05', 4, 4, 'BAT101'),
    ('Свечи зажигания', 15.00, '2023-05-12', 5, 5, 'SPK202');