#include "LinkedList.h"
#include <iostream>
#include <string>
#include <conio.h>
#include <functional>

using namespace std;
template<typename T>
class ReverseModLinkedList : public LinkedList<T> {
public:
	ReverseModLinkedList& reverse(const int& begingpoint, const int& endpoint) {
		int end = endpoint;
		int begin = begingpoint;
		this->indexcheck(end);
		this->indexcheck(begin);
		if (begin > end) {
			int c = end;
			end = begin;
			begin = c;
		}
		if (end - begin > 2) {
			T c = this->getnode(begin + 1)->value;
			this->getnode(begin + 1)->value = this->getnode(end - 1)->value;
			this->getnode(end - 1)->value = c;
			this->reverse(begin + 1, end - 1);
		}

		return *this;
	}
};

class Demon {
public:
	void start() {
		system("cls");
		cout << " It is demo for task 10: Reverse method"<<endl;
		cout << " This additional function simply reverse all elements\n value between start and finish index arguments" << endl;
		cout << " For inwtance:\n I created new list of int:";
		ReverseModLinkedList<int>* list = new ReverseModLinkedList<int>();
		list->append(1);
		list->append(2);
		list->append(3);
		list->append(4);
		list->append(5);
		list->append(6);
		for (int i = 0; i < (int)list->length(); i++) {
			cout << i + 1 << ". " << (*list)[i] << endl;
		}
		cout << "\n Than I called list->reverse(0,5):" << endl;
		list->reverse(0, 5);
		for (int i = 0; i < (int)list->length(); i++) {
			cout << i + 1 << ". " << (*list)[i] << endl;
		}
		cout << "\n list->reverse(0,3):" << endl;
		list->reverse(0, 3);
		for (int i = 0; i < (int)list->length(); i++) {
			cout << i + 1 << ". " << (*list)[i] << endl;
		}
		cout << "\n The end.";
		system("pause");
	}
};

class InteractiveMode {
public:
	void start() {
		ReverseModLinkedList<int>* list = new ReverseModLinkedList<int>();
		string str[10] = {
		"Demo",
		"Reverse",
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
		function<void()> functions[10] = {
			[](){
				Demon d;
				d.start();
			},
			[list]() {
				cout << "Enter start index: ";
				int start;
				cin >> start;
				cout << "Enter Finish index: ";
				int finish;
				cin >> finish;
				try {
					list->reverse(start, finish);
				}
				catch (exception & ex) {
					cout << ex.what() << endl;
					system("pause");
				}
				
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
				for (int i = 0; i < (int)list->length(); i++) {
					cout << i + 1 << ". " << (*list)[i] << endl;
				}
				system("pause");
			},
			[&exit]() {
				exit = !exit;
			}

		};
		while (!exit) {
			system("cls");
			cout << "Size of list:  " << list->length() << endl;
			for (int i = 0; i < 10; i++) {
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
					else arrow = 9;
				}
				else if ((int)key == 80) {
					if (arrow < 9) arrow++;
					else arrow = 0;
				}
			}
			else if ((int)key == 13) {
				functions[arrow]();
			}
		}
	}
};
