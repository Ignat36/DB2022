CREATE OR REPLACE PROCEDURE insertModel(
	BrandName character varying(20),
	BodyStyleName character varying(20),
	ModelName character varying(20)
) 
language plpgsql
as $$
	DECLARE
	bid integer := 0;
	bsid integer := 0;
	rec record;
	recs record;
BEGIN
	insert into brand(name) 
	select BrandName
	where not exists (select * from brand where name = BrandName);
	
	insert into bodystyle(stylename) 
	select BodyStyleName
	where not exists (select * from bodystyle where stylename = BodyStyleName);
	
	for rec in (select * from brand where name = BrandName)
	loop
		bid := rec.idbrand;
	end loop;
	
	for recs in (select * from bodystyle where stylename = BodyStyleName)
	loop
		bsid := recs.idbodystyle;
	end loop;
	
	
	insert into model(name, brand_idbrand, bodystyle_idbodystyle) 
	select ModelName, bid, bsid
	where not exists (select * from model where name = ModelName AND brand_idbrand = bid AND bodystyle_idbodystyle = bsid);

END; $$

CREATE OR REPLACE PROCEDURE newClient(
	pFIO character varying(60),
	phone character varying(20),
	mail character varying(60),
	curdate date,
	BrandName character varying(20),
	BodyStyleName character varying(20),
	ModelName character varying(20)
) 
language plpgsql
as $$
	DECLARE
	pid integer := 0;
	cid integer := 0;
	mid integer := 0;
	recs record;
BEGIN
	insert into person(fio, phonenumber, mailadres) 
	values (pFIO, phone, mail);
	
	for recs in (select * from person where person.fio = pFIO order by idperson)
	loop
		pid := recs.idperson;
	end loop;
	
	insert into client(person_idperson, lastvisit) 
	values (pid, curdate);
	
	call insertmodel(BrandName, BodyStyleName, ModelName);
	
	for recs in (select * from model where name = ModelName order by idmodel)
	loop
		mid := recs.idmodel;
	end loop;
	
	insert into car (defects, client_person_idperson, model_idmodel)
	values('', pid, mid);
	
	for recs in (select * from car order by idcar)
	loop
		cid := recs.idcar;
	end loop;
	
	insert into document(text, workedhours, workacceptdate, car_idcar, price) 
	values ('', 0, curdate, cid, 0);

END; $$

CREATE OR REPLACE PROCEDURE hireWorker(
	pFIO character varying(60),
	phone character varying(20),
	mail character varying(60),
	curdate date,
	Wsalary real,
	qualif character varying(45)
) 
language plpgsql
as $$
	DECLARE
	pid integer := 0;
	recs record;
BEGIN
	insert into person(fio, phonenumber, mailadres) 
	values (pFIO, phone, mail);
	
	for recs in (select * from person where person.fio = pFIO order by idperson)
	loop
		pid := recs.idperson;
	end loop;
	
	insert into worker(salary, hiredate, unpaidhours, paidhours, qualification, personalqualities, person_idperson) 
	values (Wsalary, curdate, 0, 0, qualif, '', pid);

END; $$

CREATE OR REPLACE PROCEDURE paySalary() 
language plpgsql
as $$
	DECLARE
	w record;
	acc record;
	sal int := 0;
	h int := 0;
	accid int := 0;
BEGIN
	for w in (select * from worker)
	loop
		sal := w.salary * w.unpaidhours;
		h := w.unpaidhours + w.paidhours;
		
		if (w.unpaidhours = 0) THEN CONTINUE;
		end if;
		
		UPDATE worker
		SET unpaidhours=0, paidhours=h
		WHERE person_idperson = w.person_idperson;
		
		for acc in (select * from cashaccount where cashaccount.person_idperson = w.person_idperson)
		loop
			accid := acc.idcashaccount;
		end loop;
		
		insert into cashtransfer(cash, cashaccount_idcashaccount, type)
		values (sal, accid, 'Worker');
		
	end loop;
	
END; $$