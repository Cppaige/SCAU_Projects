#include "Elibrary.h"
#include <iostream>

using namespace std;

int main() {
    Elibrary library;
    library.displayWelcomePage();//��ӭ����
    library.loadUsers(); // �����û�����
    library.loadBooks(); // ����ͼ������
	library.mainMenu(); // ��ʾ���˵�

    return 0;
}
