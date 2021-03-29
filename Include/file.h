#ifndef _FILE_H_
#define _FILE_H_

#include <iostream>
#include <fstream>

using namespace std;

#include "person.h"

extern int len;
extern struct contact person[1000];

void upload_from_file();
void save_to_file();
void empty_file();


#endif
