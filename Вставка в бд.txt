INSERT INTO bodystyle(stylename) VALUES ('Седан');
INSERT INTO bodystyle(stylename) VALUES ('Универсал');
INSERT INTO bodystyle(stylename) VALUES ('Хэтчбек');
INSERT INTO bodystyle(stylename) VALUES ('Лифтбек');
INSERT INTO bodystyle(stylename) VALUES ('Купе');
INSERT INTO bodystyle(stylename) VALUES ('Лимузин');
INSERT INTO bodystyle(stylename) VALUES ('Кабриолет');
INSERT INTO bodystyle(stylename) VALUES ('Внедорожник');
INSERT INTO bodystyle(stylename) VALUES ('Микроавтобус');
INSERT INTO bodystyle(stylename) VALUES ('Минивэн');
INSERT INTO bodystyle(stylename) VALUES ('Родстер');
INSERT INTO bodystyle(stylename) VALUES ('Пикап');
INSERT INTO bodystyle(stylename) VALUES ('Фургон');
	
INSERT INTO brand(name) VALUES ('Acura');
INSERT INTO brand(name) VALUES ('Alfa Romeo');
INSERT INTO brand(name) VALUES ('Alpine');
INSERT INTO brand(name) VALUES ('Land Rover');
INSERT INTO brand(name) VALUES ('Lexus');
INSERT INTO brand(name) VALUES ('Lifan');
INSERT INTO brand(name) VALUES ('Aston Martin');
INSERT INTO brand(name) VALUES ('Audi');
INSERT INTO brand(name) VALUES ('Bentley');
INSERT INTO brand(name) VALUES ('BMW');
INSERT INTO brand(name) VALUES ('Bugatti');
INSERT INTO brand(name) VALUES ('Cadillac');
INSERT INTO brand(name) VALUES ('Chevrolet');
INSERT INTO brand(name) VALUES ('Chrysler');
INSERT INTO brand(name) VALUES ('Citroen');
INSERT INTO brand(name) VALUES ('Dodge');
INSERT INTO brand(name) VALUES ('Ferrari');
INSERT INTO brand(name) VALUES ('Fiat');
INSERT INTO brand(name) VALUES ('Ford');
INSERT INTO brand(name) VALUES ('Geely');
INSERT INTO brand(name) VALUES ('Honda');
INSERT INTO brand(name) VALUES ('Hyundai');
INSERT INTO brand(name) VALUES ('Infiniti');
INSERT INTO brand(name) VALUES ('Jaguar');
INSERT INTO brand(name) VALUES ('Jeep');
INSERT INTO brand(name) VALUES ('KIA');
INSERT INTO brand(name) VALUES ('Koenigsegg');
INSERT INTO brand(name) VALUES ('Lada');
INSERT INTO brand(name) VALUES ('Lamborghini');
INSERT INTO brand(name) VALUES ('УАЗ');
INSERT INTO brand(name) VALUES ('ВАЗ');
INSERT INTO brand(name) VALUES ('Volvo');
INSERT INTO brand(name) VALUES ('Volkswagen');
INSERT INTO brand(name) VALUES ('Toyota');
INSERT INTO brand(name) VALUES ('Tesla');
INSERT INTO brand(name) VALUES ('Suzuki');
INSERT INTO brand(name) VALUES ('Subaru');
INSERT INTO brand(name) VALUES ('smart');
INSERT INTO brand(name) VALUES ('Skoda');
INSERT INTO brand(name) VALUES ('SEAT');
INSERT INTO brand(name) VALUES ('Rolls-Royce');
INSERT INTO brand(name) VALUES ('Renault');
INSERT INTO brand(name) VALUES ('Range Rover');
INSERT INTO brand(name) VALUES ('Porsche');
INSERT INTO brand(name) VALUES ('Opel');
INSERT INTO brand(name) VALUES ('Nissan');
INSERT INTO brand(name) VALUES ('Mitsubishi');
INSERT INTO brand(name) VALUES ('Mercedes-Benz');
INSERT INTO brand(name) VALUES ('MCLaren');
INSERT INTO brand(name) VALUES ('Mazda');
INSERT INTO brand(name) VALUES ('Maybach');
INSERT INTO brand(name) VALUES ('Maserati');
INSERT INTO brand(name) VALUES ('Lotus');
	
INSERT INTO person(fio, phonenumber, mailadres)
	VALUES 
	(
		'Леонов Александр Михайлович', 
		'+375298608283',
		'PunchBubbaFalling@gmail.com'
	);
INSERT INTO person(fio, phonenumber, mailadres)
	VALUES 
	(
		'Фролов Пётр Ярославович', 
		'+375296142155',
		'CrackedGlow@gmail.com'
	);
INSERT INTO person(fio, phonenumber, mailadres)
	VALUES 
	(
		'Кулешов Роман Егорович', 
		'+375295469723',
		'GermCliffTwig@gmail.com'
	);
INSERT INTO person(fio, phonenumber, mailadres)
	VALUES 
	(
		'Кузнецова Злата Макаровна', 
		'+375292562129',
		'SadColt@gmail.com'
	);
INSERT INTO person(fio, phonenumber, mailadres)
	VALUES 
	(
		'Николаев Всеволод Кириллович', 
		'+375298329036',
		'YarnReady@gmail.com'
	);
INSERT INTO person(fio, phonenumber, mailadres)
	VALUES 
	(
		'Петрова Дария Борисовна', 
		'+375295359150',
		'MagnumCrowdEcho@gmail.com'
	);
INSERT INTO person(fio, phonenumber, mailadres)
	VALUES 
	(
		'Коновалова Арина Мироновна', 
		'+375293243738',
		'CultistSelection@gmail.com'
	);
INSERT INTO person(fio, phonenumber, mailadres)
	VALUES 
	(
		'Петров Кирилл Матвеевич', 
		'+375293594264',
		'EraserGunGame@gmail.com'
	);
INSERT INTO person(fio, phonenumber, mailadres)
	VALUES 
	(
		'Павлов Всеволод Владиславович', 
		'+375296654715',
		'GeoTouch@gmail.com'
	);
INSERT INTO person(fio, phonenumber, mailadres)
	VALUES 
	(
		'Аксенов Данила Русланович', 
		'+375295808266',
		'GirlHawkCamel@gmail.com'
	);

	
INSERT INTO role(name) VALUES ('Админ');
INSERT INTO role(name) VALUES ('Менеджер');
INSERT INTO role(name) VALUES ('Рабочий');
	
INSERT INTO users(login, password, role_idrole) 
	VALUES 
	(
		'admin', 
		'admin',
		1
	);		
INSERT INTO users(login, password, role_idrole) 
	VALUES 
	(
		'manager', 
		'manager',
		2
	);
INSERT INTO users(login, password, role_idrole) 
	VALUES 
	(
		'worker', 
		'worker',
		3
	);
	
INSERT INTO workingequipment(name, assignmentofuse, lasttimeused, price)
	VALUES 
	(
		'Домкрат', 
		'Машину поднимать',
		'2022-10-08',
		'30'
	);	
INSERT INTO workingequipment(name, assignmentofuse, lasttimeused, price)
	VALUES 
	(
		'Подъемник', 
		'Машину поднимать',
		'2022-10-08',
		'15000'
	);	
INSERT INTO workingequipment(name, assignmentofuse, lasttimeused, price)
	VALUES 
	(
		'Распылитель', 
		'Что-то красить',
		'2022-10-08',
		'20'
	);	
INSERT INTO workingequipment(name, assignmentofuse, lasttimeused, price)
	VALUES 
	(
		'Балгарка', 
		'Что-то пилить',
		'2022-10-08',
		'5000'
	);	
INSERT INTO workingequipment(name, assignmentofuse, lasttimeused, price)
	VALUES 
	(
		'Сварочный аппарат', 
		'Что-то варить',
		'2022-10-08',
		'1500'
	);	
INSERT INTO workingequipment(name, assignmentofuse, lasttimeused, price)
	VALUES 
	(
		'Набор инструментов', 
		'Что-то откручивать\закручивать',
		'2022-10-08',
		'20'
	);
	
INSERT INTO service(description, price, requiredtimeh, name)
	VALUES 
	(
		'Данный вид слесарного ремонта рассчитан на диагностику и, в случае выявления мелких неполадок, их устранение. При таком подходе выполняют замену поршневых колец, элементов системы амортизации, деталей тормозной системы и прочее.',
		'1000',
		'100',
		'Текущий слесарный ремонт'
	);	
INSERT INTO service(description, price, requiredtimeh, name)
	VALUES 
	(
		'При таком ремонте автомобиль разбирается и определяется степень износа каждой детали. Комплектующие, имеющие степень износа выше рекомендованной производителем, подлежат замене.',
		'2000',
		'300',
		'Капитальный слесарный ремонт'
	);	
INSERT INTO service(description, price, requiredtimeh, name)
	VALUES 
	(
		'Появление незначительных вмятин исправляется даже без покрасочных работ при условии, что лакокрасочное покрытие не разрушено. Для этого используют резиновый молоток в легкодоступных местах или специальные крючки, рычаги и клюшки на труднодоступных участках кузова.',
		'500',
		'100',
		'Удаление вмятин и рихтовка'
	);	
INSERT INTO service(description, price, requiredtimeh, name)
	VALUES 
	(
		'Нарушение целостности кузова исправляется посредством сварочных работ. Для этого используются два типа оборудования: электродный сварочный аппарат и плазменная резка. При использовании этих приборов, вдоль сварочного шва железо не деформируется.',
		'600',
		'200',
		'Сварочные работы'
	);	
INSERT INTO service(description, price, requiredtimeh, name)
	VALUES 
	(
		'Под покраской подразумевается несколько этапов: работа с кузовом на специальном посте подготовки; обработка лакокрасочным материалом в покрасочной камере; сушка в сушильной камере. В покрасочной камере создаются такие условия, где даже в воздухе отсутствуют загрязнения.',
		'300',
		'100',
		'Покраска'
	);	
INSERT INTO service(description, price, requiredtimeh, name)
	VALUES 
	(
		'Речь идет не только об автосигнализации, но и о механической защите. Данная услуга может быть как бюджетной, что характеризуется простой установкой иммобилайзера, так и дорогой, когда создается комплексная защита автомобиля.',
		'700',
		'100',
		'Установка охранных систем'
	);	
INSERT INTO service(description, price, requiredtimeh, name)
	VALUES 
	(
		'Заводские сетки радиатора изготавливаются из пластика с минимальным расстоянием между ребрами в 2 сантиметра. Чтобы исключить попадание в радиатор постороннего мусора, имеющего меньший размер, рекомендуется установка защитной сетки.',
		'50',
		'24',
		'Сетка для защиты радиатора'
	);	
INSERT INTO service(description, price, requiredtimeh, name)
	VALUES 
	(
		'После проведения мероприятий по шумоизоляции, заметно снижается уровень шума, поступающего в салон автомобиля с улицы. Кроме того, такие явления, как дребезжание отдельных элементов кузова, посторонние скрипы и стуки полностью устраняются.',
		'500',
		'100',
		'Шумоизоляция авто'
	);	
INSERT INTO service(description, price, requiredtimeh, name)
	VALUES 
	(
		'Данное предложение автосервисов подразумевает нанесение на лобовое стекло тончайшего покрытия с высокими водоотталкивающими свойствами. Благодаря такому покрытию, на скорости свыше 60 км/ч дождевая вода будет эффективнее стекать по стеклу, практически без помощи дворников. ',
		'100',
		'48',
		'Антидождь'
	);	
INSERT INTO service(description, price, requiredtimeh, name)
	VALUES 
	(
		'Благодаря тонировочной пленке можно не только улучшить внешний вид экстерьера автомобиля, но и сделать пребывание в салоне более комфортным. Это обусловлено поглощением части солнечных лучей пленкой. Чем она темнее, тем больше световых лучей поглощается.',
		'200',
		'100',
		'Тонировка стекол'
	);	
INSERT INTO service(description, price, requiredtimeh, name)
	VALUES 
	(
		'Установка данного приспособления позволяет предотвратить запотевание лобового стекла в салоне, а потому видимость не ухудшается при разности температур внешней и внутренней стороны стекла. Эксплуатационный срок антизапотевателя составляет примерно 4 месяца.',
		'50',
		'48',
		'Антизапотеватель'
	);
	
INSERT INTO public.model(
	name, brand_idbrand, bodystyle_idbodystyle)
	VALUES (?, ?, ?, ?);
	
INSERT INTO public.cashaccount(
	cardnumber, person_idperson)
	VALUES (?, ?, ?);
	
INSERT INTO public.cashtransfer(
	cash, cashaccount_idcashaccount, type)
	VALUES (?, ?, ?, ?);
	
INSERT INTO public.client(
	person_idperson, lastvisit)
	VALUES (?, ?);
	
INSERT INTO public.worker(
	salary, hiredate, unpaidhours, paidhours, qualification, personalqualities, person_idperson)
	VALUES (?, ?, ?, ?, ?, ?, ?);
	
INSERT INTO public.document(
	text, workedhours, cashtransfer_idcashtransfer, workacceptdate, workdonedate, car_idcar, price)
	VALUES (?, ?, ?, ?, ?, ?, ?, ?);
	
INSERT INTO public.car(
	defects, client_person_idperson, model_idmodel)
	VALUES (?, ?, ?, ?);
	
INSERT INTO public.component(
	name, price, dateofmanufacture)
	VALUES (?, ?, ?, ?);