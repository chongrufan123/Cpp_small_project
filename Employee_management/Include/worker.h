#pragma once

#include <string>
using std::string;


class AbstractEmployee{
public:
    virtual void show_info();   // 展示个人信息
    virtual string get_deptname() = 0;  // 获得岗位名称
    int m_age;
    string m_name;
    string m_sexy;
    string m_post;
    int m_serial;

};