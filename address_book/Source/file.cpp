#include "../Include/file.h"
#include <fstream>

/* 函数功能:将文件中的数据取出到结构体person中 */
void upload_from_file()
{
  
  ifstream readfile;
  readfile.open("../Resource/contact.txt", ios::in);
  /* 如果没有该文件的话创建一个再打开之 */
  if(!readfile.is_open())
    {
      ofstream writefile;
      writefile.open("../Resource/contact.txt", ios::out);
      writefile.close();
      readfile.open("../Resource/contact.txt", ios::in);
    }
  
  for(len = 0; len < 1000; len++)
    {
      person[len].name[0] = 0;
      readfile >> person[len].name;
      if(person[len].name[0] == 0)
          break;
      else
        {
          readfile >> person[len].gender;
          readfile >> person[len].age;
          readfile >> person[len].telephone;
          readfile >> person[len].address;
        }

    }
  readfile.close();
}

/* 函数功能:保存person中的数据到文件中 */
void save_to_file()
{
  ofstream writefile;
  writefile.open("../Resource/contact.txt", ios::trunc);
  cout << len << endl;
  for(int i = 0; i < len; i++)
      writefile << person[i].name << ' ' << person[i].gender
                << ' ' << person[i].age << ' '
                << person[i].telephone << ' '
                << person[i].address << endl;
  writefile.close();
}

/* 函数功能:清空文件中的数据 */
void empty_file()
{
  ofstream writefile;
  writefile.open("../Resource/contact.txt", ios::trunc);
  writefile.close();
}
