#ifndef WORKER_H
#define WORKER_H

#include "person.h"

class Worker : public Person
{
public:
    Worker();
    //Worker();

private:
    int Person_idPerson;
    QString PersonalQualities;
};

#endif // WORKER_H
