#ifndef List_h
#define List_h

#include <iostream>
#include <string>
#include "Node.h"

class List {
private:
	Node* head;
	Node* tail;
public:
	List();
	
	void AddToHead(int value);
	void AddToTail(int value);
	void DeleteFromHead();
	void DeleteFromTail();
	void DeleteAll();
	void Show();

	void InsertAtPosition(int value, int position);
	void DeleteAtPosition(int position);
	int SearchElement(int value);
	int ReplaceElement(int oldValue, int newValue);
	void ReverseList();

	~List();
};

#endif 
