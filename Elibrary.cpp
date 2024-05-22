#include "Elibrary.h"

User::User(string& _username, string& _password, bool& _isAdmin)
	: username(_username), password(_password), isAdmin(_isAdmin) {};

void Elibrary::displayWelcomePage()
{
	cout << "\t\t欢迎来到小家的图书馆系统！(●'3'●) " << endl;
	cout << "\t\t--------------------------------------------------------------" << endl;
	cout << "\t\t|  ,--.   ,--.,-----.  ,------.   ,---.  ,------.,--.   ,--. |\n"
		"\t\t|  |  |   |  ||  |) /_ |  .--. ' /  O  \\ |  .--. '\\  `.'  /  |\n"
		"\t\t|  |  |   |  ||  .-.  \\|  '--'.'|  .-.  ||  '--'.' '.    /   |\n"
		"\t\t|  |  '--.|  ||  '--' /|  |\\  \\ |  | |  ||  |\\  \\    |  |    |\n"
		"\t\t|  `-----'`--'`------' `--' '--'`--' `--'`--' '--'   `--'    |" << endl;
	cout << "\t\t--------------------------------------------------------------" << endl;
	cout << endl;
	cout << "请按任意键继续..." << std::endl;

	// 等待用户按任意键继续
	_getch();
}

void Elibrary::loadUsers() {
	// 完整路径示例
	ifstream inFile("users.txt");
	if (!inFile) {
		cout << "无法打开用户文件。" << endl;
		return;
	}

	string username, password;
	bool isAdmin;
	while (inFile >> username >> password >> isAdmin) {//读取文件中的用户名，密码，是否是管理员
			users.emplace_back(username, password, isAdmin);
	}
	//if (inFile.eof()) {
	//	cout << "Reached end of file." << endl;
	//}
	//else if (inFile.fail()) {
	//	cout << "An error occurred while reading the file." << endl;
	//}
	inFile.close();
}

void Elibrary::loadBooks() {
	ifstream inFile("books.txt");
	if (!inFile) {
		cout << "无法打开书籍文件。" << endl;
		return;
	}
	string id, name, author, category;
	int totalBooks;
	while (inFile >> id >> name >> author >> category >> totalBooks) {//同上
		books.emplace_back(name, id, author, category, totalBooks, totalBooks, 0);
	}
	inFile.close();
}

//void Elibrary::loadBorrowRecord()
//{
//	ifstream inFile("borrowRecord.txt");
//	if (!inFile) {
//		cout << "无法打开借阅记录文件。" << endl;
//		return;
//	}
//	string username;
//	time_t dueDate;
//	while (inFile >> username >> dueDate) {
//		// 从 borrowRecord 中查找用户名对应的书籍
//		for (auto& book : books) {
//			// 如果找到了对应的书籍，则将借阅记录添加到书籍的 borrowRecord 中
//			if (book.borrowRecord.find(username) != book.borrowRecord.end()) {
//				book.borrowRecord[username] = dueDate;
//			}
//		}
//	}
//	inFile.close();
//}

//void Elibrary::mainMenu() {
//	int choice;
//	do {
//		system("cls");
//		cout << "\t\t--------------------------------------------------------------" << endl;
//		cout << "\t\t ★                           主菜单                         ★" << endl;
//		cout << "\t\t--------------------------------------------------------------" << endl;
//		cout << "\t\t|                          1. 登 录                          |" << endl;
//		cout << "\t\t|                          2. 注 册                          |" << endl;
//		cout << "\t\t|                          3. 退 出                          |" << endl;
//		cout << "\t\t--------------------------------------------------------------" << endl;
//		cout << "请输入选项：";
//		cin >> choice;
//		switch (choice) {
//		case 1:
//			login();
//			break;
//		case 2:
//			registerUser();
//			break;
//		case 3:
//			goodbyePage();
//			break;
//		default:
//			cout << "无效选项！" << endl;
//			break;
//		}
//	} while (choice != 3);
//
//}
void Elibrary::mainMenu() {
	int choice = 0;
	const int numOptions = 3;
	char key;

	do {
		system("cls");
		cout << "\t\t--------------------------------------------------------------" << endl;
		cout << "\t\t ★                           主菜单                         ★" << endl;
		cout << "\t\t--------------------------------------------------------------" << endl;
		cout << "\t\t|                        " << (choice == 0 ? "-> " : "   ") << "1. 登 录                         |" << endl;
		cout << "\t\t|                        " << (choice == 1 ? "-> " : "   ") << "2. 注 册                         |" << endl;
		cout << "\t\t|                        " << (choice == 2 ? "-> " : "   ") << "3. 退 出                         |" << endl;
		cout << "\t\t--------------------------------------------------------------" << endl;

		key = _getch(); // 获取按键

		if (key == 72) { // 上箭头
			choice = (choice - 1 + numOptions) % numOptions;
		}
		else if (key == 80) { // 下箭头
			choice = (choice + 1) % numOptions;
		}
		else if (key == 13) { // 回车键
			switch (choice) {
			case 0:
				login();
				break;
			case 1:
				registerUser();
				break;
			case 2:
				goodbyePage();
				break;
			}
		}
	} while (choice != 2 || key != 13); // 按回车键选择“退 出”才退出
}
void Elibrary::hidePasswordInput(string& password) {
	char ch;
	while (true) {
		ch = _getch();	// 从输入读取字符，但不显示在控制台
		if (ch == 13) { // 回车键（Enter），结束输入
			break;
		}
		else if (ch == 8) { // 退格键（Backspace）
			if (!password.empty()) {
				cout << "\b \b"; // 在控制台上删除最后一个星号
				password.pop_back();  // 从密码字符串中删除最后一个字符
			}
		}
		else {
			password.push_back(ch); // 将字符添加到密码字符串
			cout << '*';		// 在控制台上显示星号
		}
	}
	cout << endl; // 换行，结束输入
}
void Elibrary::login() {
	string username, password;
	system("cls");
	cout << "\t\t--------------------------------------------------------------" << endl;
	cout << "\t\t ★                         登录                            ★" << endl;
	cout << "\t\t--------------------------------------------------------------" << endl;
	cout << "请输入用户名：";
	cin >> username;
	cout << "请输入密码：";
	hidePasswordInput(password);
	bool isAdmin = false;
	if (loginUser(username, password, isAdmin))
	{
		if (isAdmin)
		{
			adminMenu();
		}
		else
		{
			stuMenu(username);
		}
	}
}
bool Elibrary::loginUser(string username, string password, bool& isAdmin)
{
	for (const auto& user : users)
	{
		if (user.username == username && user.password == password)
		{
			isAdmin = user.isAdmin;
			return true;
		}
	}
	cout << "用户名或密码错误！" << endl;
	_getch();
	return false;
}
void Elibrary:: registerUser()
{
	system("cls");
	string username, password1;
	string password2;
	bool isAdmin;
	cout << "\t\t--------------------------------------------------------------" << endl;
	cout << "\t\t ★                         注册                            ★" << endl;
	cout << "\t\t--------------------------------------------------------------" << endl;
	cout << "请输入用户名：";
	cin >> username;
	while (true) {
		std::cout << "请输入密码: ";
		hidePasswordInput(password1);

		std::cout << "请再次输入密码: ";
		hidePasswordInput(password2);

		if (password1 == password2) {
			std::cout << "密码匹配！" << std::endl;
			break;
		}
		else {
			std::cout << "两次输入密码不一致，请再次输入。" << std::endl;
			password1.clear();
			password2.clear();
		}
	}
	cout << "是否是管理员？(是输入1，否输入0)" << endl;
	cin >> isAdmin;
	//将用户信息写入文件
	ofstream outFile("users.txt", ios::app);
	outFile << username << " " << password1 << " " << isAdmin << endl;
	outFile.close();
	//将用户添加到当前用户列表中
	User newUser(username, password1, isAdmin);
	users.push_back(newUser);
	cout << "*****注册成功！******" << endl;
	_getch();
}
void Elibrary::welcomeAdmin()
{
	system("cls");
	// 使用 ASCII art 创建大字体的“欢迎管理员”
	cout << "\t\t\t\t************************************" << std::endl;
	cout << "\t\t\t\t*                                  *" << std::endl;
	cout << "\t\t\t\t*           欢迎管理员             *" << std::endl;
	cout << "\t\t\t\t*                                  *" << std::endl;
	cout << "\t\t\t\t************************************" << std::endl;
	cout << endl;
	cout << "请按任意键继续..." << std::endl;

	// 等待用户按任意键继续
	_getch();
	return;
}
//void Elibrary::adminMenu() {
//	int choice;
//	welcomeAdmin();
//	do {
//		system("cls");
//		cout << "\t\t--------------------------------------------------------------" << endl;
//		cout << "\t\t ★                        管理员菜单                       ★" << endl;
//		cout << "\t\t--------------------------------------------------------------" << endl;
//		cout << "\t\t|                        1. 添加图书                         |" << endl;
//		cout << "\t\t|                        2. 修改图书                         |" << endl;
//		cout << "\t\t|                        3. 删除图书                         |" << endl;
//		cout << "\t\t|                   4. 查询即将/已到期图书                   |" << endl;
//		cout << "\t\t|                      5. 查看统计信息                       |" << endl;
//		cout << "\t\t|                          6. 退出                           |" << endl;
//		cout << "\t\t--------------------------------------------------------------" << endl;
//		cout << "请输入选项：";
//		cin >> choice;
//
//		switch (choice) {
//		case 1:
//			addBook();
//			break;
//		case 2:
//			modifyBook();
//			break;
//		case 3:
//			deleteBook();
//			break;
//		case 4:
//			queryDueBook();
//			break;
//		case 5:
//			viewStatus();
//			break;
//		case 6:
//			cout << "再见！" << endl;
//			break;
//		default:
//			cout << "无效选项！" << endl;
//			break;
//		}
//	} while (choice != 6);
//}
void Elibrary::adminMenu() {
	int choice = 0;
	const int numOptions = 6;
	char key;

	welcomeAdmin();
	do {
		system("cls");
		cout << "\t\t--------------------------------------------------------------" << endl;
		cout << "\t\t ★                        管理员菜单                       ★" << endl;
		cout << "\t\t--------------------------------------------------------------" << endl;
		cout << "\t\t|                      " << (choice == 0 ? "-> " : "   ") << "1. 添加图书                         |" << endl;
		cout << "\t\t|                      " << (choice == 1 ? "-> " : "   ") << "2. 修改图书                         |" << endl;
		cout << "\t\t|                      " << (choice == 2 ? "-> " : "   ") << "3. 删除图书                         |" << endl;
		cout << "\t\t|                 " << (choice == 3 ? "-> " : "   ") << "4. 查询即将/已到期图书                   |" << endl;
		cout << "\t\t|                    " << (choice == 4 ? "-> " : "   ") << "5. 查看统计信息                       |" << endl;
		cout << "\t\t|                        " << (choice == 5 ? "-> " : "   ") << "6. 退出                           |" << endl;
		cout << "\t\t--------------------------------------------------------------" << endl;

		key = _getch(); // 获取按键

		if (key == 72) { // 上箭头
			choice = (choice - 1 + numOptions) % numOptions;
		}
		else if (key == 80) { // 下箭头
			choice = (choice + 1) % numOptions;
		}
		else if (key == 13) { // 回车键
			switch (choice) {
			case 0:
				addBook();
				break;
			case 1:
				modifyBook();
				break;
			case 2:
				deleteBook();
				break;
			case 3:
				queryDueBook();
				break;
			case 4:
				viewStatus();
				break;
			case 5:
				cout << "再见！" << endl;
				break;
			}
		}
	} while (choice != 5 || key != 13); // 按回车键选择“退出”才退出
}


void Elibrary::addBook() {
	string name, id, author, category;
	system("cls");
	cout << "\t\t--------------------------------------------------------------" << endl;
	cout << "\t\t ★                         添加图书                        ★" << endl;
	cout << "\t\t--------------------------------------------------------------" << endl;
	int totalBooks;
	cout << "请输入图书名称：" ;
	cin >> name;
	cout << "请输入图书编号：" ;
	cin >> id;
	cout << "请输入作者 ：" ;
	cin >> author;
	cout << "请输入类别：" ;
	cin >> category;
	cout << "请输入总数：" ;
	cin >> totalBooks;
	books.emplace_back(name, id, author, category, totalBooks, totalBooks, 0);    
	// 清除输入缓冲区中的剩余换行符
	//cin.ignore(numeric_limits<streamsize>::max(), '\n');

	// 打开文件以追加模式写入图书信息
	ofstream file("books.txt", ios::app);

	// 检查文件是否成功打开
	if (!file) {
		cerr << "无法打开文件以追加数据。" << endl;
		return;
	}

	// 将图书信息写入文件
	file << id << " " << name << " " << author << " " << category << " " << totalBooks  << endl;

	// 关闭文件
	file.close();
	cout << endl;
	cout << "*****添加成功！*****" << endl;
	_getch();
}

bool Elibrary::modifyBook() {
	string id;
	system("cls");
	cout << "\t\t--------------------------------------------------------------" << endl;
	cout << "\t\t ★                         修改图书                        ★" << endl;
	cout << "\t\t--------------------------------------------------------------" << endl;
	cout << "请输入图书编号：";
	cin >> id;
	for (auto& book: books) {
		if (book.id == id) {
			bool contiEdit = true;
			//循环直到退出修改
			while (contiEdit) {
				cout << endl;
				cout << "图书信息：" << endl;
				book.displayInfo();
				cout << endl;
				cout << "请选择要修改的信息：" << endl;
				cout << "1. 图书名称" << endl;
				cout << "2. 作者" << endl;
				cout << "3. 类别" << endl;
				cout << "4. 总数" << endl;
				cout << "5. 退出修改" << endl;
				cout << "请输入选项：" << endl;
				int choice;
				cin >> choice;
				switch (choice) {
				case 1:
					cout << "请输入新的图书名称：" << endl;
					cin >> book.name;
					break;
				case 2:
					cout << "请输入新的作者：" << endl;
					cin >> book.author;
					break;
				case 3:
					cout << "请输入新的类别：" << endl;
					cin >> book.category;
					break;
				case 4:
					cout << "请输入新的总数：" << endl;
					int newtotalBooks;
					cin >> newtotalBooks;
					//计算新的可借阅数
					book.availableBooks += newtotalBooks - book.totalBooks;
					book.totalBooks = newtotalBooks;
					break;
				case 5:
					contiEdit = false;
					break;
				default:
					cout << "无效选项，请重试。" << endl;
					break;
				}
			}

			if (!contiEdit) {
				cout << "*****修改成功！*****" << endl;
				ofstream file("books.txt");
				if (!file) {
					cerr << "无法打开文件。" << endl;
					return false;
				}

				for (const auto& book : books) {
					file << book.id << " " << book.name << " " << book.author << " " << book.category << " "<< book.totalBooks << endl;
				}
				file.close();
				_getch();
			}
			return true;
		}
	}
	cout << "*****未找到该图书！*****" << endl;
	_getch();
	return false;
}

void Elibrary::deleteBook() {
	string id;
	system("cls");
	cout << "\t\t--------------------------------------------------------------" << endl;
	cout << "\t\t ★                         删除图书                        ★" << endl;
	cout << "\t\t--------------------------------------------------------------" << endl;
	cout << "请输入图书编号：" << endl;
	cin >> id;

	int flag = 0;
	//展示图书信息
	for (auto it = books.begin(); it != books.end(); ++it) {
		if (it->id == id) {
			flag = 1;
			cout << "找到以下图书：" << endl;
			cout << it->name << " " << it->author << " " << it->category << endl;
		}
	}
	if (flag == 0)
	{
		cout << "*****未找到该图书！*****" << endl;
		_getch();
		return;
	}
	cout << "是否确认删除？(是输入1，否输入0)" << endl;
	int choice;
	cin >> choice;
	if (choice == 0) {
		cout << "*****取消删除！*****" << endl;
		_getch();
		return;
	}
	else {
		for (auto it = books.begin(); it != books.end(); ++it) {
			if (it->id == id) {
				books.erase(it);
				ofstream file("books.txt");
				if (!file) {
					cerr << "无法打开文件。" << endl;
					return;
				}
				for (const auto& book : books) {
					file << book.id << " " << book.name << " " << book.author << " " << book.category << " " << book.totalBooks << endl;
				}
				cout << "*****删除成功！*****" << endl;
				_getch();
				return;
			}
		}
	}
}

void Elibrary::queryDueBook() {
	system("cls");
	cout << "\t\t--------------------------------------------------------------" << endl;
	cout << "\t\t ★                 查询即将/已到期图书                     ★" << endl;
	cout << "\t\t--------------------------------------------------------------" << endl;

	// 获取当前时间
	time_t now = time(nullptr);

	// 表头：图书名称、借书人、到期状态
	cout << left << setw(20) << "图书名称"
		 << left << setw(15) << "图书编号"
		 << left << setw(14) << "借书人"
		 << left << setw(20) << "到期状态"
		 <<endl;
	cout <<  string(64, '-') << endl;

	// 遍历所有书籍
	for (const auto& book : books) {
		// 遍历书籍的借阅记录
		for (const auto& record : book.borrowRecord) {
			string status;
			// 检查到期日期与当前时间的关系
			if (record.second < now) {
				status = "已到期";
			}
			else {
				// 如果到期时间与当前时间的差异较小，则可以标记为即将到期
				const time_t a_week = 7 * 24 * 60 * 60;
				if (record.second <= now + a_week) {
					status = "一周内即将到期";
				}
				else {
					// 跳过不是即将到期或已到期的记录
					continue;
				}
			}

			// 获取借书人
			string borrower = record.first;

			// 格式化输出图书名称、借书人、到期状态
			cout << left << setw(20) << book.name
				 << left << setw(15) << book.id
				 << left << setw(14) << borrower
				 << left << setw(20) << status
				 << endl;
		}
	}
	_getch();
}

//统计各分类的图书情况，图书被借阅次数，在库情况等
void Elibrary::viewStatus() {
	map<string, int> categoryCount;
	map<string, int> borrowedCount;
	map<string, int> availableCount;
	for (const auto& book : books) {
		categoryCount[book.category]++;
		borrowedCount[book.name] = book.borrowedBooks;
		availableCount[book.name] = book.availableBooks;
	}
	cout << "图书统计信息：" << endl;
	printAllBooks();
	_getch();
	//cout << "各类别图书数量：" << endl;
	//for (const auto& category : categoryCount) {
	//	cout << category.first << "：" << category.second << endl;
	//}
	//cout << "各图书被借阅次数：" << endl;
	//for (const auto& borrowed : borrowedCount) {
	//	cout << borrowed.first << "：" << borrowed.second << endl;
	//}
	//cout << "各图书在库情况：" << endl;
	//for (const auto& available : availableCount) {
	//	cout << available.first << "：" << available.second << endl;
	//}
}

void Elibrary::printAllBooks()
{
	system("cls");
	cout <<  string(100, '-') << endl;
	cout <<  left;
	cout <<  setw(10) << "ISBN"
		 <<  setw(20) << "书名"
		 <<  setw(20) << "作者"
		 <<  setw(10) << "类别"
		 <<  setw(10) << "总数"
		 <<  setw(15) << "可借阅数"
		 <<  setw(15) << "已借阅数" << endl;
	cout <<  string(100, '-') << endl;
	for (const auto& book : books)
	{
		cout << left;
		cout << setw(10) << book.id
			 << setw(20) << book.name
			 << setw(20) << book.author
			 << setw(10) << book.category
			 << setw(10) << book.totalBooks
			 << setw(15) << book.availableBooks
			 << setw(15) << book.borrowedBooks << endl;
	}
	cout << string(100, '-') << endl;
}
void Elibrary::welcomeStu() {
	system("cls");
	cout << "\t\t\t\t************************************" << std::endl;
	cout << "\t\t\t\t*                                  *" << std::endl;
	cout << "\t\t\t\t*            欢迎学生              *" << std::endl;
	cout << "\t\t\t\t*                                  *" << std::endl;
	cout << "\t\t\t\t************************************" << std::endl;
	cout << endl;
	cout << "请按任意键继续..." << std::endl;

	// 等待用户按任意键继续
	_getch();
	return;
}
//void Elibrary::stuMenu(string username) {
//	int choice;
//	welcomeStu();
//	do {
//		system("cls");
//		cout << "\t\t--------------------------------------------------------------" << endl;
//		cout << "\t\t ★                         学生菜单                        ★" << endl;
//		cout << "\t\t--------------------------------------------------------------" << endl;
//		cout << "\t\t|                         1. 查询图书                         |" << endl;
//		cout << "\t\t|                         2. 借阅图书                         |" << endl;
//		cout << "\t\t|                         3. 归还图书                         |" << endl;
//		cout << "\t\t|                       4. 查看统计信息                       |" << endl;
//		cout << "\t\t|                           5. 退出                           |" << endl;
//		cout << "\t\t--------------------------------------------------------------" << endl;
//		cout << "请输入选项：" ;
//		cin >> choice;
//		switch (choice)
//		{
//		case 1:
//			searchBook();
//			break;
//		case 2:
//			borrowBook(username);
//			break;
//		case 3:
//			returnBook(username);
//			break;
//		case 4:
//			viewStatus();
//			break;
//		case 5:
//			cout << "再见！" << endl;
//			break;
//		default:
//			cout << "*****无效选项！*****" << endl;
//		}
//	} while (choice != 5);
//}
void Elibrary::stuMenu(string username) {
	int choice = 0;
	const int numOptions = 5;
	char key;

	welcomeStu();
	do {
		system("cls");
		cout << "\t\t--------------------------------------------------------------" << endl;
		cout << "\t\t ★                         学生菜单                        ★" << endl;
		cout << "\t\t--------------------------------------------------------------" << endl;
		cout << "\t\t|                      " << (choice == 0 ? "-> " : "   ") << "1. 查询图书                         |" << endl;
		cout << "\t\t|                      " << (choice == 1 ? "-> " : "   ") << "2. 借阅图书                         |" << endl;
		cout << "\t\t|                      " << (choice == 2 ? "-> " : "   ") << "3. 归还图书                         |" << endl;
		cout << "\t\t|                    " << (choice == 3 ? "-> " : "   ") << "4. 查看统计信息                       |" << endl;
		cout << "\t\t|                        " << (choice == 4 ? "-> " : "   ") << "5. 退出                           |" << endl;
		cout << "\t\t--------------------------------------------------------------" << endl;

		key = _getch(); // 获取按键

		if (key == 72) { // 上箭头
			choice = (choice - 1 + numOptions) % numOptions;
		}
		else if (key == 80) { // 下箭头
			choice = (choice + 1) % numOptions;
		}
		else if (key == 13) { // 回车键
			switch (choice) {
			case 0:
				searchBook();
				break;
			case 1:
				borrowBook(username);
				break;
			case 2:
				returnBook(username);
				break;
			case 3:
				viewStatus();
				break;
			case 4:
				cout << "再见！" << endl;
				break;
			}
		}
	} while (choice != 4 || key != 13); // 按回车键选择“退出”才退出
}
void Elibrary::searchBook() {
	string keyword;
	system("cls");
	cout << "\t\t--------------------------------------------------------------" << endl;
	cout << "\t\t ★                         查询图书                        ★" << endl;
	cout << "\t\t--------------------------------------------------------------" << endl;
	cout << "请输入关键字（书名或作者或分类）：" << endl;
	cin >> keyword;
	int flag = 0;
	for (const auto book : books) {
		if (book.name.find(keyword) != string::npos || book.author.find(keyword) != string::npos || book.category.find(keyword) != string::npos) {
			cout << " *****找到相关图书： *****" << endl;
			cout << left;
			cout <<  string(100, '-') << endl;
			cout << setw(10) << "图书编号"
				 << setw(20) << "书名"
				 << setw(20) << "作者"
				 << setw(10) << "类别"
				 << setw(10) << "总数"
				 << setw(15) << "可借阅数"
				 << setw(15) << "已借阅数" << endl;

			cout << string(100, '-') << endl;
			cout << left;
			cout << setw(10) << book.id
				 << setw(20) << book.name
				 << setw(20) << book.author
				 << setw(10) << book.category
				 << setw(10) << book.totalBooks
				 << setw(15) << book.availableBooks
				 << setw(15) << book.borrowedBooks << endl;
			cout << string(100, '-') << endl;
			flag = 1;
		}
	}
	if (flag == 0) {
		cout << "*****未找到相关图书！*****" << endl;
	}
	_getch();
	return;
}

void Elibrary::borrowBook(string username) {
	string id;
	system("cls");
	cout << "\t\t--------------------------------------------------------------" << endl;
	cout << "\t\t ★                         借阅图书                        ★" << endl;
	cout << "\t\t--------------------------------------------------------------" << endl;
	cout << "请输入图书编号：";
	cin >> id;
	time_t now = time(nullptr);
	time_t dueDate;

	// 遍历书籍，找到指定编号的书籍
	for (auto& book : books) {
		if (book.id == id) {
			cout << book.name << " " << book.id << " " << book.author << " " << book.category << endl;
			cout << "您确定要借阅这本书吗？(是输入1，否输入0)" << endl;
			int choice;
			cin >> choice;
			if (choice == 0) {
				cout << "*****取消借阅！*****" << endl;
				return;
			}
			else {
				cout << "请输入借书期限（天）：" << endl;
				int days;
				cin >> days;

				// 计算归还日期
				dueDate = now + days * 24 * 60 * 60;

				// 尝试借阅书籍
				if (book.borrowBooks(username, dueDate)) {
					cout << "*****借阅成功！*****" << endl;

					// 使用 localtime_s 安全地将归还日期转换为本地时间
					struct tm dueDate_tm;
					// localtime_s 返回 0 表示成功
					if (localtime_s(&dueDate_tm, &dueDate) == 0) {
						// 格式化日期
						char buffer[80];
						strftime(buffer, sizeof(buffer), "%Y-%m-%d", &dueDate_tm); //%H:%M:%S

						// 输出借书人和归还日期
						cout << "借书人: " << username << endl;
						cout << "归还日期: " << buffer << endl;
						_getch();
					}
					else {
						cout << "无法转换归还日期！" << endl;
					}
				}
				else {
					cout << "*****借阅失败！*****" << endl;
				}
				return; // 处理完毕后退出函数
			}
		}
	}
	cout << " *****未找到该图书！ *****" << endl;
	_getch();
}




void Elibrary::returnBook(string username) {
	string id;
	system("cls");
	cout << "\t\t--------------------------------------------------------------" << endl;
	cout << "\t\t ★                         归还图书                        ★" << endl;
	cout << "\t\t--------------------------------------------------------------" << endl;
	cout << "请输入图书编号：" << endl;
	cin >> id;
	for (auto& book : books) {
		if (book.id == id) {
			// 显示图书信息
			cout << book.name << " " << book.id << " " << book.author << " " << book.category << endl;
			cout << "您确定要归还这本书吗？(是输入1，否输入0)" << endl;
			int choice;
			cin >> choice;
			if (choice == 1) {
				if (book.returnBooks(username)) {
					cout << "*****归还成功！*****" << endl;
					_getch();
				}
				else {
					//cout << "*****归还失败！*****" << endl;
					_getch();
				}
				return;
			}
			else {
				cout << "取消归还！" << endl;
				_getch();
				return;
			}
		}
	}
	cout << "未找到该图书！" << endl;
	_getch();
	return;
}

void Elibrary::goodbyePage()
{
	showAdPopup();
	
	system("cls");
	cout << "\t\t               _____        _        __       __    \n"
		"\t\t              /__   \\/\\  /\\/_\\    /\\ \\ \\/\\ /\\/ _\\   \n"
		"\t\t                / /\\/ /_/ //_\\\\  /  \\/ / //_/\\ \\    \n"
		"\t\t               / / / __  /  _  \\/ /\\  / __ \\ _\\ \\   \n"
		"\t\t               \\/  \\/ /_/\\_/ \\_/\\_\\ \\/\\/  \\/ \\__/   " << endl;
	cout << "\t\t--------------------------------------------------------------" << endl;
	cout << "\t\t ★                  感谢您的使用！再见！                   ★" << endl;
	cout << "\t\t--------------------------------------------------------------" << endl;

	cout << "请按任意键继续..." << std::endl;

	// 等待用户按任意键继续
	_getch();
	return;
}



void Elibrary:: showAdPopup() {
	system("cls"); // Use "cls" on Windows
	cout << "广告：" << endl;
	printf("\t\t************************************\n");
	printf("\t\t*         邀请您提供宝贵意见       *\n");
	printf("\t\t************************************\n");
	printf("\t\t* 您的反馈对我们非常重要：         *\n");
	printf("\t\t* 1. 系统易用性                    *\n");
	printf("\t\t* 2. 功能完善性                    *\n");
	printf("\t\t* 3. 整体满意度                    *\n");
	printf("\t\t************************************\n");
	printf("\t\t* 请访问：www.xiaojia.com          *\n");
	printf("\t\t* 参与问卷调查，赢取精美礼品！     *\n");
	printf("\t\t************************************\n");
	SLEEP(5); // Pause for 5 seconds
}