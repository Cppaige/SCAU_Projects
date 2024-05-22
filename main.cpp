#include "Elibrary.h"
#include <iostream>

using namespace std;

int main() {
    Elibrary library;
    library.displayWelcomePage();//欢迎界面
    library.loadUsers(); // 加载用户数据
    library.loadBooks(); // 加载图书数据
	library.mainMenu(); // 显示主菜单

    return 0;
}
