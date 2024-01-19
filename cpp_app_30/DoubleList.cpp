#include "DoubleList.h"

DoubleList::DoubleList() : head(nullptr), tail(nullptr) {}

DoubleList::~DoubleList() {
	DeleteAll();
}

void DoubleList::AddToHead(int value) {
	Node* newNode = new Node(value);
	if (head == nullptr) {
		head = newNode;
		tail = newNode;
	}
	else {
		newNode->next = head;
		head->prev = newNode;
		head = newNode;
	}
}

void DoubleList::AddToTail(int value) {
	Node* newNode = new Node(value);
	if (tail == nullptr) {
		head = newNode;
		tail = newNode;
	}
	else {
		newNode->prev = tail;
		tail->next = newNode;
		tail = newNode;
	}
}

void DoubleList::DeleteFromHead() {
	if (head == nullptr) {
		std::cout << "List is empty" << std::endl;
		return;
	}
	else if (head == tail) {
		delete head;
		head = nullptr;
		tail = nullptr;
	}
	else {
		Node* temp = head;
		head = head->next;
		head->prev = nullptr;
		delete temp;
	}
}

void DoubleList::DeleteFromTail() {
	if (tail == nullptr) {
		std::cout << "List is empty" << std::endl;
		return;
	}
	else if (head == tail) {
		delete tail;
		head = nullptr;
		tail = nullptr;
	}
	else {
		Node* temp = tail;
		tail = tail->prev;
		tail->next = nullptr;
		delete temp;
	}
}

void DoubleList::DeleteAll() {
	while (head != nullptr) {
		DeleteFromHead();
	}
}

void DoubleList::Show() {
	if (head == nullptr) {
		std::cout << "List is empty" << std::endl;
		return;
	}
	Node* temp = head;
	while (temp != nullptr) {
		std::cout << temp->data << " ";
		temp = temp->next;
	}
	std::cout << std::endl;
}
