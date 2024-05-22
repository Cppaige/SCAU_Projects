#pragma once
#include <string>
#include <map>
#include <fstream>
#include <iostream>
#include "Elibrary.h"

using namespace std;

//图书类
class Book {
public:
	string name;
	string id;
	string author;
	string category;
	int availableBooks;				  // 可借阅数
	int totalBooks;					  // 总数
	int borrowedBooks;				  // 已借阅数
	map<string, time_t> borrowRecord; // 借阅记录

	Book(string name, string id, string author, string category, int totalBooks, int availableBooks, int borrowedBooks);
	void displayInfo() const;
	bool borrowBooks(string username, time_t dueDate);
	bool returnBooks(string username);
};
