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
#include <conio.h> // ���� conio.h ͷ�ļ�
#include <windows.h>
#include "Book.h"
#define SLEEP(seconds) Sleep((seconds) * 1000)
using namespace std;
class Book;

class User {
public:
	string username;
	string password;
	bool isAdmin; //�ж��Ƿ��ǹ���Ա
	//vector<int> newBookNotifications; // �洢δ��������ID
	User(string& username, string& password, bool& isAdmin);
};


//ͼ�����
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
