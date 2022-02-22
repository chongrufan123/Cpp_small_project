#include "../Include/main.h"

struct contact person[1000];
int len;                        // 这是两个全局变量

int main()
{
  int get; // 用于用户选择目录选项
  while(1)
    {
      get = show_content();  // 目录的展示界面
      content_judgment(get); // 目录的后台选择界面
    }
  return 0;
}

