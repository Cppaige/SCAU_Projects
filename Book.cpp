#include "Book.h"

Book::Book(string name, string id, string author, string category,int totalBooks, int availableBooks,  int borrowedBooks)
	:name(name), id(id), author(author), category(category) ,totalBooks(totalBooks), availableBooks(availableBooks), borrowedBooks(borrowedBooks) {}

void Book::displayInfo() const
{
	cout << "����: " << name << endl;
	cout << "ͼ����: " << id << endl;
	cout << "����: " << author << endl;
	cout << "���: " << category << endl;
	cout << "����: " << totalBooks << endl;
	cout << "�ɽ�����: " << availableBooks << endl;
	cout << "�ѽ�����: " << borrowedBooks << endl;
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
		cout << "*****û�п��Խ��ĵ��顣*****" << endl;
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
		cout << "*****��û�н����Ȿ�顣*****" << endl;
		return false;
	}
}           