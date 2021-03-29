#include "../Include/contact.h"

/* 函数功能:增加新的通讯录成员 */
void add_new_contact()
{
  char aaa;                     // 用于选择是否继续输入
  upload_from_file();           // 从文件中取出通讯录数据放到结构体中
  if(len >= 1000)
    {
      cout << "人数已经满啦" << endl;
      return;
    }
  while(1)
    {
      add();                    // 添加新的结构体数据到person[len]
      len++;
      save_to_file();           // 将目前的数据保存到文件当中
      cout << "请问还要继续输入吗(Y/N)";
      cin >> aaa;

      while(1)
        {
          if(aaa == 'y' || aaa == 'Y')
            break;
          else if(aaa == 'n' || aaa == 'N')
            return;
          else
            {
              cout << "请重新输入: ";
              cin >> aaa;
            }
        }
    }
}

/* 函数功能:展示所有通讯录成员 */
void check_all_contact()
{
  int i;
  char nul;
  upload_from_file();           // 从文件中取出通讯录数据放到结构体中
  for( i = 0; i < len; i++)
    print_contact(i);           // 打印person中第i个成员到屏幕
  cout << "请按任意键后回车返回"<< endl;
  cin >> nul;
}

/* 函数功能:删除特定的通讯录成员 */
void delete_contact()
{
  int serial;
  int a[1000];
  int j;
  char delete_name[20];
  upload_from_file();           // 从文件中取出通讯录数据放到结构体中
  cout << "请输入要删除的对象的名字: ";
  cin >> delete_name;
  j = check_specify_contact(delete_name, a); // 检索特定的名字的数据,并且把得到的数据序号储存到a数组当中
  if(j == 0)
    return;
  cout << "请输入要删除人的序号(按0退出): ";
  /* 确保用户输入正确的数据,或者退出 */
  while(1)
    {
      cin >> serial;
      if(serial <= j && serial >= 1)
        {
          for(int i = a[serial-1]; i < len - 1; i++)
            person[i] = person[i+1];
          len--;
          save_to_file();
          return;
        }
      else if(serial == 0)
        return;
      else
        cout << "请输入合法的数据";
    }

}

/* 函数功能:查看特定名称的通讯录成员 */
void check_specify_contact()
{
  int a[1000];
  char nul;
  int j;
  char delete_name[20];
  upload_from_file();
  cout << "请输入要查询的对象的名字: ";
  cin >> delete_name;
  j = check_specify_contact(delete_name, a);
  if(j == 0)
    return;
  cout << "请按任意键返回";
  cin >> nul;
  

}

/* 函数功能:改变特定的成员的相关信息 */
void modify_specify_contact()
{
  int serial;
  int a[1000];
  int j;
  char delete_name[20];
  upload_from_file();
  cout << "请输入要修改的对象的名字: ";
  cin >> delete_name;
  j = check_specify_contact(delete_name, a);
  if(j == 0)
    return;
  cout << "请输入要修改的对象的序号(按0退出): ";
  while(1)
    {
      cin >> serial;
      /* 将新增到len处的数据覆盖掉选中的数据,但是总的len保持不变 */
      if(serial <= j && serial >= 1)
        {
          add();
          person[a[serial-1]] = person[len];
          save_to_file();
          return;
        }
      else if(serial == 0)
        return;
      else
        cout << "请输入合法的数据";
    }

}

/* 函数功能:清空通讯录 */
void empty_all_contact()
{
  char bbb;
  cout << "你确定要清楚吗(Y/N)";
  while(1)
    {
      cin >> bbb;
      if(bbb == 'Y' || bbb == 'y')
        {
          empty_file();         // 直接清空文件
          return;
        }
      else if(bbb == 'N' || bbb == 'n')
        return;
      else
        cout << "请输入合法数据" << endl;
    }

}
