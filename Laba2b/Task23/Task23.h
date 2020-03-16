#pragma once
#include <cstdint>
#include <iostream>
#include <functional>
#include <string>
#include <conio.h>

using namespace std;

template<typename T>
class XORLinkedList {
public:
	struct Node {
		T item;
		Node* xorp;
	};
	XORLinkedList() {
		head = nullptr;
		size = 0;
	}
	XORLinkedList& create_empty() {
		int arrsize = size;
		for (int i = 0; i < arrsize; i++) {
			this->pop_back();
		}
		return *this;
	}

	XORLinkedList& append(const T& item) {	
		if (this->length() > 0) {
			Node* lastnode = traversetonode(this->length() - 1);
			Node* newnode = new Node();
			newnode->item = item;
			newnode->xorp = XOR(lastnode, nullptr);
			lastnode->xorp = XOR(newnode, XOR(lastnode->xorp, nullptr));
			size++;
		}
		else {
			head = new Node();
			head->item = item;
			head->xorp = nullptr;
			size++;
		}
		return *this;
	}
	XORLinkedList& pop_back() {
		if (this->length() == 0) {
			throw exception("Array is empty before pop_back");
		}
		else {
			Node* lastnode = this->traversetonode(this->length() - 1);
			Node* prev = XOR(lastnode, nullptr);
			prev->xorp = XOR(XOR(lastnode, prev->xorp), nullptr);
			delete lastnode;
			size--;
		}
	}
	XORLinkedList& insert(const T& item, const int& index) {
		indexcheck(index);
		Node* prevnode = traversetonode(index);
		Node* newnode = new Node();
		newnode->item = item;
		if (index == this->length() - 1) {
			this->append(item);
		}
		else {
			Node* prevprev = traversetonode(index - 1);
			Node* nexttoprev = XOR(prevprev,prevnode->xorp);
			newnode->xorp = XOR(prevnode, nexttoprev);
			nexttoprev->xorp = XOR(newnode, XOR(prevnode, nexttoprev->xorp));
			prevnode->xorp = XOR(XOR(nexttoprev,prevnode->xorp ), newnode);
			size++;
		}
		return *this;
	}
	XORLinkedList& remove(const int& index) {
		indexcheck(index);
		if (index == this->length() - 1) {
			this->pop_back();
		}
		else {
			Node* next = traversetonode(index + 1);
			Node* delnode = traversetonode(index);
			Node* previous = XOR(next, delnode->xorp);
			next->xorp = XOR(previous, XOR(delnode, next->xorp));
			if (previous) {
				previous->xorp = XOR(XOR(delnode, previous->xorp), next);
				delete delnode;
			}
			else {
				delete head;
				head = next;
			}
			size--;
		}
		return *this;
	}

	T& operator[](const int& index) {
		return traversetonode(index)->item;
	}

	friend ostream& operator<<(ostream& output, XORLinkedList& V) {
		for (int i = 0; i < (int)V.length(); i++) {
			output << i + 1 << ". " << V[i] << endl;
		}
		return output;
	}

	unsigned int length() {
		return size;
	}
private:
	unsigned size;
	Node* XOR(const Node* a,const Node* b) {
		return (Node*)((uintptr_t)a ^ (uintptr_t)b);
	}
	Node* head;
	void indexcheck(const int& index) {
		if ((index >= (int)size) || (index < 0)) {
			throw std::exception("Invalid index");
		}
	}
	Node* traversetonode(const int& index) {
		if (index == -1) {
			return nullptr;
		}
		else {
			indexcheck(index);
			Node* current = head;
			Node* previous = nullptr;
			Node* next;
			for (int i = 0; i < index; i++) {
				next = XOR(previous, current->xorp);
				previous = current;
				current = next;
			}
			return current;
		}
		
	}
};

class Demon {
public:
	void start() {
		system("cls");
		cout << " It is solution for task 23: XORLinkedList:"<< endl;
		cout << " Methods:\n create_empty()\n append(item)\n pop_back()" << endl;
		cout << " insert(item,index)\n remove(index)\n length()\n operator []\n operator <<\n" << endl;
		system("pause");
		system("cls");
		cout << " Quick example:\n" << endl;
		XORLinkedList<int> list = XORLinkedList<int>();
		cout << " Let's create a list and append 1 and 2 to it:\n" << endl;
		list.append(1);
		list.append(2);
		cout << list << endl;
		cout << " Then we insert 3 after index 0:\n " << endl;
		list.insert(3, 0);
		cout << list << endl;
		cout << " Then we remove 0 element:\n" << endl;
		list.remove(0);
		cout << list << endl;
		cout << " And pop_back:\n" << endl;
		list.pop_back();
		cout << list << endl;
		system("pause");
		system("cls");
		cout << "That's it, try all functions in our dialog menu!\n";
		system("pause");
	}
};

class InteractiveMode {
public:
	void start() {
		XORLinkedList<int>* list = new XORLinkedList<int>();
		string str[9] = {
		"Demo",
		"Create_empty",
		"Append",
		"Insert",
		"Remove",
		"Get",
		"Set",
		"Show All",
		"Exit"
		};
		bool exit = false;
		int arrow = 0;
		function<void()> functions[9] = {
			[](){
				Demon d;
				d.start();
			},
			[list]() {
				list->create_empty();
			},
			[list]() {
				cout << "Enter number: ";
				int a;
				cin >> a;
				list->append(a);
			},
			[list]() {
				cout << "Enter index: ";
				int ind;
				cin >> ind;
				cout << "Enter number: ";
				int a;
				cin >> a;
				try {
					list->insert(a, ind);
				}
				catch (exception & ex) {
					cout << ex.what() << endl;
					system("pause");
				}

			},
			[list]() {
				cout << "Enter index: ";
				int ind;
				cin >> ind;
				try {
					list->remove(ind);
				}
				catch (exception & ex) {
					cout << ex.what() << endl;
					system("pause");
				}
			},
			[list]() {
				cout << "Enter index: ";
				int ind;
				cin >> ind;
				try {
					cout << (*list)[ind];
					cout << endl;
				}
				catch (exception & ex) {
					cout << ex.what() << endl;
				}
				system("pause");

			},
			[list]() {
				cout << "Enter index: ";
				int ind;
				cin >> ind;
				cout << "Enter number: ";
				int a;
				cin >> a;
				try {
					(*list)[ind] = a;
				}
				catch (exception & ex) {
					cout << ex.what() << endl;
					system("pause");
				}
			},
			[list]() {
				cout << *list << endl;
				system("pause");
			},
			[&exit]() {
				exit = !exit;
			}

		};
		while (!exit) {
			system("cls");
			cout << "Size of list:  " << list->length() << endl;
			for (int i = 0; i < 9; i++) {
				if (arrow == i) {
					cout << " >> ";
				}
				else cout << "    ";
				cout << str[i] << endl;
			}
			char key = _getch();
			if ((int)key == 0 || (int)key == -32) {
				key = _getch();
				if ((int)key == 72) {
					if (arrow > 0) arrow--;
					else arrow = 8;
				}
				else if ((int)key == 80) {
					if (arrow < 8) arrow++;
					else arrow = 0;
				}
			}
			else if ((int)key == 13) {
				functions[arrow]();
			}
		}
	}
};

