#include "../Include/contens.h"

/* 函数功能:展示目录界面 */
char show_content(void)
{
  int get;
  cout << "******************" << "\n" << endl;
  cout << "1. 添加新的联系人" << endl;
  cout << "2. 查看所有的联系人" << endl;
  cout << "3. 删除指定联系人" << endl;
  cout << "4. 查找指定联系人" << endl;
  cout << "5. 修改指定联系人" << endl;
  cout << "6. 清空所有联系人" << endl;
  cout << "0. 退出通讯录" << endl;
  cout << endl;
  cout << "请选择前面的序号" << endl;
  cout << endl;
  cout << "******************" << "\n" << endl;
  cin >> get;
  return get;
}

/* 函数功能:用于后台选择函数实现特定功能 */
void content_judgment(int get)
{
  switch(get)
    {
    case 1:
      add_new_contact();        // 添加一个新的通讯录成员
      break;
    case 2:
      check_all_contact();      // 展示所有的通讯录成员
      break;
    case 3:
      delete_contact();         // 删除指定的通讯录成员
      break;
    case 4:
      check_specify_contact();  // 展示特定的通讯录成员
      break;
    case 5:
      modify_specify_contact(); // 修改特定的通讯录成员
      break;
    case 6:
      empty_all_contact();      // 清空通讯录
      break;
    case 0:
      exit(0);                  // 退出程序
    default:
      exit(0);
    }
}
