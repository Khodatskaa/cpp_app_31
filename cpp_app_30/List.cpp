#include "List.h"

List::List() : head(nullptr), tail(nullptr) {}

void List::AddToHead(int value) {
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

void List::AddToTail(int value) {
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

void List::DeleteFromHead() {
	if (head == nullptr) {
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

void List::DeleteFromTail() {
	if (tail == nullptr) {
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

void List::DeleteAll() {
	while (head != nullptr) {
		DeleteFromHead();
	}
}

void List::Show() {
	if (head == nullptr) {
		std::cout << "List is empty\n";
	}
	else {
		Node* temp = head;
		while (temp != nullptr) {
			std::cout << temp->data << " ";
			temp = temp->next;
		}
		std::cout << std::endl;
	}
}

void List::InsertAtPosition(int value, int position) {
	if (position < 1) {
		std::cout << "Invalid position\n";
		return;
	}
	else if (position == 1) {
		AddToHead(value);
		return;
	}
	else {
		Node* temp = head;
		int count = 1;
		while (temp != nullptr && count < position) {
			temp = temp->next;
			count++;
		}
		if (temp == nullptr) {
			std::cout << "Invalid position\n";
			return;
		}
		else {
			Node* newNode = new Node(value);
			newNode->prev = temp->prev;
			newNode->next = temp;
			temp->prev->next = newNode;
			temp->prev = newNode;
		}
	}
}

void List::DeleteAtPosition(int position) {
	if (position < 1) {
		std::cout << "Invalid position\n";
		return;
	}
	else if (position == 1) {
		DeleteFromHead();
		return;
	}
	else {
		Node* temp = head;
		int count = 1;
		while (temp != nullptr && count < position) {
			temp = temp->next;
			count++;
		}
		if (temp == nullptr) {
			std::cout << "Invalid position\n";
			return;
		}
		else {
			temp->prev->next = temp->next;
			if (temp->next != nullptr) {
				temp->next->prev = temp->prev;
			}
			delete temp;
		}
	}
}

int List::SearchElement(int value) {
	if (head == nullptr) {
		return -1;
	}
	else {
		Node* temp = head;
		int count = 1;
		while (temp != nullptr) {
			if (temp->data == value) {
				return count;
			}
			temp = temp->next;
			count++;
		}
		return -1;
	}
}

int List::ReplaceElement(int oldValue, int newValue) {
	if (head == nullptr) {
		return -1;
	}
	else {
		Node* temp = head;
		int count = 0;
		while (temp != nullptr) {
			if (temp->data == oldValue) {
				temp->data = newValue;
				count++;
			}
			temp = temp->next;
		}
		return count;
	}
}

void List::ReverseList() {
	if (head == nullptr) {
		return;
	}
	else {
		Node* temp = head;
		while (temp != nullptr) {
			Node* nextNode = temp->next;
			temp->next = temp->prev;
			temp->prev = nextNode;
			temp = nextNode;
		}
		temp = head;
		head = tail;
		tail = temp;
	}
}

List::~List() {
	DeleteAll();
}
