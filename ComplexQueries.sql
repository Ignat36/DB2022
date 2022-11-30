SELECT cashtransfer.cash, cashaccount.cardnumber, person.fio 
FROM cashtransfer 
INNER JOIN cashaccount ON cashaccount.idcashaccount = cashtransfer.cashaccount_idcashaccount
INNER JOIN person ON person.idperson = cashaccount.person_idperson
WHERE cashtransfer.type = 'Client'
AND person.fio LIKE '%%1%'
ORDER BY cashtransfer.idcashtransfer DESC;

SELECT cashtransfer.cash, cashaccount.cardnumber, person.fio 
FROM cashtransfer 
INNER JOIN cashaccount ON cashaccount.idcashaccount = cashtransfer.cashaccount_idcashaccount
INNER JOIN person ON person.idperson = cashaccount.person_idperson
WHERE cashtransfer.type = 'Worker'
AND person.fio LIKE '%%1%';

SELECT component.name, component.price, brand.name, model.name, bodystyle.stylename, person.fio
FROM component
INNER JOIN car_component ON car_component.component_idcomponent = component.idcomponent
INNER JOIN car ON car.idcar = car_component.car_idcar
INNER JOIN person ON person.idperson = car.client_person_idperson
INNER JOIN model ON model.idmodel = car.model_idmodel
INNER JOIN brand ON brand.idbrand = model.brand_idbrand
INNER JOIN bodystyle ON bodystyle.idbodystyle = model.bodystyle_idbodystyle;

SELECT document.text, document.workedhours, document.workacceptdate, document.workdonedate, document.price,
		brand.name, model.name, bodystyle.stylename, person.fio
FROM document
INNER JOIN car ON car.idcar = document.car_idcar
INNER JOIN person ON person.idperson = car.client_person_idperson
INNER JOIN model ON model.idmodel = car.model_idmodel
INNER JOIN brand ON brand.idbrand = model.brand_idbrand
INNER JOIN bodystyle ON bodystyle.idbodystyle = model.bodystyle_idbodystyle;

SELECT * 
FROM client
INNER JOIN person ON person.idperson = client.person_idperson
WHERE client.lastvisit = (SELECT MAX(lastvisit) FROM client);