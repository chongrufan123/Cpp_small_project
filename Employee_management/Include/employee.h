#ifndef EMPLOYEE_H_
#define EMPLOYEE_H_
#include <iostream>
#include "worker.h"

/*
int age;
string name;
string sexy;
int post;
int serial;
*/

class Boss : public AbstractEmployee{
public:
    Boss(int age, string name, int sexy, int serial);
    // virtual void show_info();
    virtual string get_deptname();
};

class Manager : public AbstractEmployee{
public:
    Manager(int age, string name, int sexy, int serial); 
    // virtual void show_info();
    virtual string get_deptname();
};

class Staff : public AbstractEmployee{
public:
    Staff(int age, string name, int sexy, int serial);
    // virtual void show_info();
    virtual string get_deptname();
};

#endif