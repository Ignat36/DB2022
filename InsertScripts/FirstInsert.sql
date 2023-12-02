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
