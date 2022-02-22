#include "../Include/basic.h"

/* 函数功能:打印结构体中指定位置的相关信息数据 */
void print_contact(int i)
{
  cout << "姓名: " << person[i].name << "\t" << "性别: "
       << person[i].gender << "\t" << "年龄"
       << person[i].age << "\t" << "电话号码: "
       << person[i].telephone << "\t" << "家庭住址: "
       << person[i].address << endl;

}

/* 函数功能:判断结构体中的数据是否包含指定的数据 */
int check_specify_contact(char name[20], int a[1000])
{
  int j = 0;
  char nul;
  for( int i = 0; i < len; i++)
    {
      if(!strcmp(person[i].name, name))
        {
          a[j] = i;
          j++;
        }
    }
  
  if(j == 0)
    {
      cout << "查无此人, 按任意键返回主菜单";
      cin >> nul;
      return 0;
    }
  
  else
    {
      cout << "查找到的有以下这些人" << endl;
      for(int i = 0; i < j; i++)
        {
          cout << i+1 << "\t";
          print_contact(a[i]);
        }
      return j;
    }
}

/* 函数功能:添加新的通讯录成员到person[len]中 */
void add()
{
  cout << "请输入姓名: ";
  cin >> person[len].name;
  cout << "请输入性别: ";
  cin >> person[len].gender;
  cout << "请输入年龄: ";
  cin >> person[len].age;
  cout << "请输入电话号码: ";
  cin >> person[len].telephone;
  cout << "请输入地址: ";
  cin >> person[len].address;
}
