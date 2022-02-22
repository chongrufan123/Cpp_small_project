#include "../Include/workermanager.h"
#include "../Include/employee.h"

#include <iostream>
#include <cctype>
#include <string>
using std::string;

WorkerManager::WorkerManager(){
    m_emp_number = 0;
    this->m_emparray = NULL;
}

WorkerManager::~WorkerManager(){
    delete [] m_emparray;

}

void WorkerManager::show_Menu(){
    using namespace std;
    cout << "****************************************************************" << endl;
    cout << "************Welcome use employee management system**************" << endl;
    cout << "************  0. exit management system        *****************" << endl;
    cout << "************  1. add employee message          *****************" << endl;
    cout << "************  2. display employees message     *****************" << endl;
    cout << "************  3. Deletion former employees     *****************" << endl;
    cout << "************  4. modification employee message *****************" << endl;
    cout << "************  5. search employee message       *****************" << endl;
    cout << "************  6. Sort by serial number         *****************" << endl;
    cout << "************  7. Clear all message             *****************" << endl;
    cout << "****************************************************************" << endl;
    cout << endl;
    cout << "Please enter your choice: ";
}

void WorkerManager::choose(){
    char a;
    std::cin >> a;
    while(!isdigit(a)){
        std::cout << "enter again: ";
        std::cin >> a;
    }
    choice = a - '0';
}

void WorkerManager::wm_exit(){
    std::cout << "welcome use it again.";
    exit(0);
}

void WorkerManager::add_worker(){
    using std::cout;
    using std::cin;
    using std::endl;
    cout << "Enter the number you want to add: ";
    int number = 0;
    cin >> number;
    if(number > 0){
        int newSize = this->m_emp_number + number;
        AbstractEmployee ** newSpace = new AbstractEmployee*[newSize];
        if(m_emparray != nullptr){
            for(int i = 0; i < m_emp_number; i++){
                newSpace[i] = m_emparray[i];
            }
        }
        int serial, age, post, sexy;
        string name;
        for(int i = 0; i < number; i++){
            cout << "Enter the serial: ";
            cin >> serial;
            cout << "Enter the name: ";
            cin >> name;
            cout << "Enter the age: ";
            cin >> age;
            cout << "Enter sexy (1 for male and 2 for female): ";
            cin >> sexy;
            cout << "Enter the post (1 for Boss, 2 for manager and 3 for staff): ";
            cin >> post;
            switch (post)
            {
            case 1:
                newSpace[m_emp_number + i] = new Boss(age, name, sexy, serial);
                break;
            case 2:
                newSpace[m_emp_number + i] = new Manager(age, name, sexy, serial);
                break;
            case 3:
                newSpace[m_emp_number + i] = new Staff(age, name, sexy, serial);
                break;
            default:
                break;
            }
        }
        m_emp_number = newSize;
        m_emparray = newSpace;


        display();
        std::cin.ignore();
        std::cin.get();
    }
    else{
        cout << "input error!";
        return;
    }

    // // test code
    // m_emp_number = 5;
    // m_emparray = new AbstractEmployee*[5];
    // m_emparray[0] = new Boss(22, "范崇儒", 1, 2);
    // m_emparray[1] = new Manager(31, "付玉波", 1, 1);
    // m_emparray[2] = new Staff(16, "美林", 2, 7);
    // m_emparray[3] = new Staff(12, "贝贝", 1, 3);
    // m_emparray[4] = new Staff(27, "苏苏", 2, 9);
    save();
}

void WorkerManager::vm_switch(){
    switch (choice)
    {
    case 0:
        wm_exit();
        break;
    case 1:
        add_worker();
        break;
    case 2:
        display();
        std::cin.ignore();
        std::cin.get();
        break;
    case 3:
        delemp();
        std::cin.ignore();
        std::cin.get();
        break;
    case 4:
        modiemp();
        std::cin.ignore();
        std::cin.get();
        break;
    case 5:
        search();
        std::cin.ignore();
        std::cin.get();
        break;
    case 6:
        sort();
        std::cin.ignore();
        std::cin.get();
        break;
    case 7:
        clear_all();
        std::cin.ignore();
        std::cin.get();
        break;     
    default:
        break;
    }
}

void WorkerManager::clear(){
    system("clear");
}


void WorkerManager::display(){
    for(int i = 0; i < m_emp_number; i++){
        m_emparray[i]->show_info();
        std::cout << "\t" << m_emparray[i]->get_deptname() << std::endl;
    }
}


void WorkerManager::delemp(){
    using namespace std;
    int choice;
    int i = m_emp_number;
    while(1){
        i = choose_staff();
        if(i >= m_emp_number){
            cout << "enter is error!" << endl;
        }
        else{
            char cc;
            WorkerManager::m_emparray[i]->show_info();
            cout << endl;
            cout << "are you srue delete?(y/n)";
            cin >> cc;
            if(cc == 'y' || cc == 'Y'){
                AbstractEmployee* fr = m_emparray[i];
                for( ; i < m_emp_number - 1; i++){
                    m_emparray[i] = m_emparray[i + 1];
                }
                m_emparray[m_emp_number - 1] = nullptr;
                delete m_emparray[m_emp_number - 1];
                delete fr;
                m_emp_number--;
                cout << "delete success!" << endl;
            }
        }
        if(m_emp_number <= 0){
            cout << "Staff informations is empty! " << endl;
            break;
        }
        char ch;
        cout << "continue or quit(q for quit, c for continue): ";
        cin >> ch;
        if(ch == 'q' || ch == 'Q')
            break;
        i = m_emp_number;
    }
        
}


int WorkerManager::choose_staff(){
    using namespace std;
    int i;
    cout << "Chose serch for serial or name(1 for serial, 2 for name): ";
    cin >> choice;
    if(choice == 1){
        int ch_serial;
        cout << "enter serial: ";
        cin >> ch_serial;
        for(i = 0; i < m_emp_number; i++){
            if(ch_serial == m_emparray[i]->m_serial)
                break;
        }
    }
    else if(choice == 2){
        string ch_name;
        cout << "Enter name: ";
        cin >> ch_name;
        for(i = 0; i < m_emp_number; i++){
            if(ch_name == m_emparray[i]->m_name)
                break;
        }
    }
    return i;
}


void WorkerManager::modiemp(){
    using namespace std;
    int i = m_emp_number;
    int serial, age, post, sexy;
    string name;
    i = choose_staff();
    if(i >= m_emp_number){
        cout << "enter is error!" << endl;
    }
    else{
        cout << "origin: " << endl;
        m_emparray[i]->show_info();
        cout << endl;
        cout << "modificate the serial: ";
        cin >> serial;
        cout << "modificate the name: ";
        cin >> name;
        cout << "modificate the age: ";
        cin >> age;
        cout << "modificate sexy (1 for male and 2 for female): ";
        cin >> sexy;
        cout << "modificate the post (1 for Boss, 2 for manager and 3 for staff): ";
        cin >> post;
        switch (post){
            case 1:
                m_emparray[i] = new Boss(age, name, sexy, serial);
                break;
            case 2:
                m_emparray[i] = new Manager(age, name, sexy, serial);
                break;
            case 3:
                m_emparray[i] = new Staff(age, name, sexy, serial);
                break;
            default:
                break;
        }
        cout << "modify success" << endl;
    }

}

void WorkerManager::search(){
    using namespace std;
    int i = m_emp_number;
    i = choose_staff();
    if(i >= m_emp_number){
        cout << "enter is error!" << endl;
    }
    else{
        m_emparray[i]->show_info();
        cout << "\t" << m_emparray[i]->get_deptname() << endl;
    }
}


void WorkerManager::sort(){
    int i, j;
    AbstractEmployee* temp;
    for(i = 0; i < m_emp_number; i++){
        for(j = 0; j < m_emp_number - i - 1; j++){
            if(m_emparray[j]->m_serial > m_emparray[j + 1]->m_serial){
                temp = m_emparray[j];
                m_emparray[j] = m_emparray[j + 1];
                m_emparray[j + 1] = temp;
            }
        }
    }
    std::cout << "sort sucess!";
}


void WorkerManager::clear_all(){
    using namespace std;
    char c;
    cout << "are you sure clear all message(y/n)? ";
    cin >> c;
    if(c == 'Y' || c == 'y'){
        for(int i = 0; i < m_emp_number; i++){
            delete m_emparray[i];
        }
        delete m_emparray;
        m_emp_number = 0;
        cout << "delete success!" << endl;  
    }
}

void WorkerManager::save(){
    using namespace std;
    ofstream ofs;
    ofs.open(FILENAME, ios::trunc);
    ofs << "serial\t" << "name\t" << "sexy\t" << "age\t" << "post" << endl;
    for(int i = 0; i < m_emp_number; i++){
        ofs << m_emparray[i]->m_serial << "\t" << m_emparray[i]->m_name << "\t" << m_emparray[i]->m_sexy << "\t" << m_emparray[i]->m_age << "\t" << m_emparray[i]->m_post << endl;
    }
    ofs.close();
}