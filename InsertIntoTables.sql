INSERT INTO public.bodystyle(
	idbodystyle, stylename)
	VALUES (?, ?);
	
INSERT INTO public.brand(
	idbrand, name)
	VALUES (?, ?);
	
INSERT INTO public.person(
	idperson, fio, phonenumber, mailadres)
	VALUES (?, ?, ?, ?);
	
INSERT INTO public.role(
	idrole, name)
	VALUES (?, ?);
	
INSERT INTO public.users(
	iduser, login, password, role_idrole)
	VALUES (?, ?, ?, ?);
	
INSERT INTO public.workingequipment(
	idworkingequipment, name, assignmentofuse, lasttimeused, price)
	VALUES (?, ?, ?, ?, ?);
	
INSERT INTO public.service(
	idservice, description, price, requiredtimeh, name)
	VALUES (?, ?, ?, ?, ?);
	
INSERT INTO public.model(
	idmodel, name, brand_idbrand, bodystyle_idbodystyle)
	VALUES (?, ?, ?, ?);
	
INSERT INTO public.cashaccount(
	idcashaccount, cardnumber, person_idperson)
	VALUES (?, ?, ?);
	
INSERT INTO public.cashtransfer(
	idcashtransfer, cash, cashaccount_idcashaccount, type)
	VALUES (?, ?, ?, ?);
	
INSERT INTO public.client(
	person_idperson, lastvisit)
	VALUES (?, ?);
	
INSERT INTO public.worker(
	salary, hiredate, unpaidhours, paidhours, qualification, personalqualities, person_idperson)
	VALUES (?, ?, ?, ?, ?, ?, ?);
	
INSERT INTO public.document(
	iddocument, text, workedhours, cashtransfer_idcashtransfer, workacceptdate, workdonedate, car_idcar, price)
	VALUES (?, ?, ?, ?, ?, ?, ?, ?);
	
INSERT INTO public.car(
	idcar, defects, client_person_idperson, model_idmodel)
	VALUES (?, ?, ?, ?);
	
INSERT INTO public.component(
	idcomponent, name, price, dateofmanufacture)
	VALUES (?, ?, ?, ?);