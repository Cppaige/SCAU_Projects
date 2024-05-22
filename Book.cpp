#include "Book.h"

Book::Book(string name, string id, string author, string category,int totalBooks, int availableBooks,  int borrowedBooks)
	:name(name), id(id), author(author), category(category) ,totalBooks(totalBooks), availableBooks(availableBooks), borrowedBooks(borrowedBooks) {}

void Book::displayInfo() const
{
	cout << "书名: " << name << endl;
	cout << "图书编号: " << id << endl;
	cout << "作者: " << author << endl;
	cout << "类别: " << category << endl;
	cout << "总数: " << totalBooks << endl;
	cout << "可借阅数: " << availableBooks << endl;
	cout << "已借阅数: " << borrowedBooks << endl;
}

bool Book::borrowBooks(string username, time_t dueDate)
{
	if (availableBooks > 0)
	{
		availableBooks--;
		borrowedBooks++;
		borrowRecord[username] = dueDate;
		return true;
	}
	else
	{
		cout << "*****没有可以借阅的书。*****" << endl;
		return false;
	}
}

bool Book::returnBooks(string username) {
	if (borrowRecord.find(username) != borrowRecord.end())
	{
		availableBooks++;
		borrowedBooks--;
		borrowRecord.erase(username);
		return true;
	}
	else
	{
		cout << "*****你没有借阅这本书。*****" << endl;
		return false;
	}
}           