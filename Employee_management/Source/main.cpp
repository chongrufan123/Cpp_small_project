#include <iostream>
#include "../Include/workermanager.h"
#include "../Include/worker.h"
#include "../Include/employee.h"
#include <string>

using std::string;
using std::cout;
using std::endl;

int main(){
    using namespace std;
    WorkerManager wm;
    while(1){
        wm.show_Menu();
        wm.choose();
        wm.vm_switch();
        wm.clear();
    }

    return 0;
}
