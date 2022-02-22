#pragma once

#include "../Include/worker.h"
#include <fstream>
const string FILENAME = "../Resource/empFile.txt";
class WorkerManager{
private:
    int choice;
    int m_emp_number;
    AbstractEmployee ** m_emparray;
    bool m_FileIsEmpty;

public:

    WorkerManager();

    void show_Menu();

    ~WorkerManager();

    void choose();

    void wm_exit();

    void vm_switch();

    void clear();

    void add_worker();

    void display();

    void delemp();

    void modiemp();

    int choose_staff();

    void search();

    void sort();

    void clear_all();

    void save();
};