#pragma once
#include <string>
#include <vector>
#include <map>
#include <ctime>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <istream>
#include <algorithm>
#include <conio.h> // 包含 conio.h 头文件
#include <windows.h>
#include "Book.h"
#define SLEEP(seconds) Sleep((seconds) * 1000)
using namespace std;
class Book;

class User {
public:
	string username;
	string password;
	bool isAdmin; //判断是否是管理员
	//vector<int> newBookNotifications; // 存储未读的新书ID
	User(string& username, string& password, bool& isAdmin);
};


//图书馆类
class Elibrary {
private:
	vector<User> users;
	vector<Book> books;

public:
	//vector<User> users;
	//vector<Book> books;
	void displayWelcomePage();
	void loadUsers();
	void loadBooks();
	//void loadBorrowRecord();
	void mainMenu();
	void hidePasswordInput(string& password);
	void login();
	bool loginUser(string username, string password, bool& isAdmin);
	void registerUser();
	void welcomeAdmin();
	void adminMenu();
	void addBook();
	bool modifyBook();
	void deleteBook();
	void queryDueBook();
	void viewStatus();
	void printAllBooks();
	void welcomeStu();
	void stuMenu(string username);
	void searchBook();
	void borrowBook(string username);
	void returnBook(string username); 
	void goodbyePage();
	void showAdPopup();
};
