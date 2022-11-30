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
		
INSERT INTO model(name, brand_idbrand, bodystyle_idbodystyle)
		VALUES 
		(
			'M8 Coupe',
			10,
			5
		);	
	INSERT INTO model(name, brand_idbrand, bodystyle_idbodystyle)
		VALUES 
		(
			'E34',
			10,
			1
		);	
	INSERT INTO model(name, brand_idbrand, bodystyle_idbodystyle)
		VALUES 
		(
			'Vesta',
			28,
			1
		);	
	INSERT INTO model(name, brand_idbrand, bodystyle_idbodystyle)
		VALUES 
		(
			'Granta',
			28,
			1
		);	
	INSERT INTO model(name, brand_idbrand, bodystyle_idbodystyle)
		VALUES 
		(
			'Rio',
			26,
			1
		);
		
	INSERT INTO cashaccount(cardnumber, person_idperson)
		VALUES 
		(
			'17409488245517115276',
			1
		);	
	INSERT INTO cashaccount(cardnumber, person_idperson)
		VALUES 
		(
			'31233411387427793198',
			3
		);	
	INSERT INTO cashaccount(cardnumber, person_idperson)
		VALUES 
		(
			'14232216857618927954',
			2
		);	
	INSERT INTO cashaccount(cardnumber, person_idperson)
		VALUES 
		(
			'65028602486509006138',
			4
		);	
	INSERT INTO cashaccount(cardnumber, person_idperson)
		VALUES 
		(
			'93446066184963788291',
			5
		);	
	INSERT INTO cashaccount(cardnumber, person_idperson)
		VALUES 
		(
			'35984076361542097372',
			6
		);	
	INSERT INTO cashaccount(cardnumber, person_idperson)
		VALUES 
		(
			'60165754120014607177',
			7
		);	
	INSERT INTO cashaccount(cardnumber, person_idperson)
		VALUES 
		(
			'77335998182660380125',
			8
		);	
	INSERT INTO cashaccount(cardnumber, person_idperson)
		VALUES 
		(
			'09478351201640618984',
			9
		);	
	INSERT INTO cashaccount(cardnumber, person_idperson)
		VALUES 
		(
			'14398808778383710734',
			10
		);
		
	INSERT INTO client(person_idperson, lastvisit)
		VALUES 
		(
			6,
			'2022-06-23'
		);	
	INSERT INTO client(person_idperson, lastvisit)
		VALUES 
		(
			7,
			'2022-01-10'
		);	
	INSERT INTO client(person_idperson, lastvisit)
		VALUES 
		(
			8,
			'2022-09-01'
		);	
	INSERT INTO client(person_idperson, lastvisit)
		VALUES 
		(
			9,
			'2022-10-19'
		);	
	INSERT INTO client(person_idperson, lastvisit)
		VALUES 
		(
			10,
			'2022-11-21'
		);
		
	INSERT INTO worker(salary, hiredate, unpaidhours, paidhours, qualification, personalqualities, person_idperson)
		VALUES 
		(
			'15', 
			'2016-06-23', 
			'0', 
			'19545', 
			'Автослесарь', 
			'Норм чел', 
			'1'
		);	
	INSERT INTO worker(salary, hiredate, unpaidhours, paidhours, qualification, personalqualities, person_idperson)
		VALUES 
		(
			'14', 
			'2017-06-23', 
			'0', 
			'16545', 
			'Автослесарь', 
			'Норм чел, играет в доту', 
			'2'
		);	
	INSERT INTO worker(salary, hiredate, unpaidhours, paidhours, qualification, personalqualities, person_idperson)
		VALUES 
		(
			'20', 
			'2018-06-23', 
			'0', 
			'13545', 
			'Автослесарь', 
			'Характер не оч. но свое дело знает.', 
			'3'
		);	
	INSERT INTO worker(salary, hiredate, unpaidhours, paidhours, qualification, personalqualities, person_idperson)
		VALUES 
		(
			'10', 
			'2020-06-23', 
			'10', 
			'4545', 
			'Автослесарь', 
			'Душа коллектива', 
			'4'
		);	
	INSERT INTO worker(salary, hiredate, unpaidhours, paidhours, qualification, personalqualities, person_idperson)
		VALUES 
		(
			'9', 
			'2021-06-23', 
			'10', 
			'1545', 
			'Автослесарь', 
			'Тихий, спокойный', 
			'5'
		);
		
	