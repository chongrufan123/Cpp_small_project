#include "../Include/employee.h"
#include "../Include/worker.h"
#include <iostream>
#include <cstring>

using std::cout;
using std::cin;
using std::endl;

Boss::Boss(int age, string name, int sexy, int serial){
    m_age = age;
    m_name = name;
    switch (sexy)
    {
    case 1:
        m_sexy = "male";
        break;
    case 2:
        m_sexy = "female";
        break;
    default:
        m_sexy = "dont_know";
        break;
    }
    m_post = "Boss";
    m_serial = serial;
}

Manager::Manager(int age, string name, int sexy, int serial){
    m_age = age;
    m_name = name;
    switch (sexy)
    {
    case 1:
        m_sexy = "male";
        break;
    case 2:
        m_sexy = "female";
        break;
    default:
        m_sexy = "dont_know";
        break;
    }
    m_post = "Manager";
    m_serial = serial;
}

Staff::Staff(int age, string name, int sexy, int serial){
    m_age = age;
    m_name = name;
    switch (sexy)
    {
    case 1:
        m_sexy = "male";
        break;
    case 2:
        m_sexy = "female";
        break;
    default:
        m_sexy = "dont_know";
        break;
    }
    m_post = "Staff";
    m_serial = serial;
}


void AbstractEmployee::show_info(){
    cout << m_serial << "\t"
        << m_name << "\t"
        << m_sexy << "\t"
        << m_age << "\t"
        << m_post;
}
string Boss::get_deptname(){
    return "to manager all complain.";
}

string Manager::get_deptname(){
    return "to listen boss's conmand and speak it to staff.";
}

string Staff::get_deptname(){
    return "work hard do work.";
}



