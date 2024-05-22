#pragma once
#include <string>
#include <map>
#include <fstream>
#include <iostream>
#include "Elibrary.h"

using namespace std;

//ͼ����
class Book {
public:
	string name;
	string id;
	string author;
	string category;
	int availableBooks;				  // �ɽ�����
	int totalBooks;					  // ����
	int borrowedBooks;				  // �ѽ�����
	map<string, time_t> borrowRecord; // ���ļ�¼

	Book(string name, string id, string author, string category, int totalBooks, int availableBooks, int borrowedBooks);
	void displayInfo() const;
	bool borrowBooks(string username, time_t dueDate);
	bool returnBooks(string username);
};
