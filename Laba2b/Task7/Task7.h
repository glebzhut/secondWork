#include "LinkedList.h"
#include <iostream>
#include <string>
#include <conio.h>
#include <functional>

using namespace std;
template<typename T>
class FilterLinkedList : public LinkedList<T> {
public:
	FilterLinkedList<T>& filter(bool (*condition)(T item)) {
		FilterLinkedList<T>* newlist = new FilterLinkedList<T>();
		auto nextnode = FilterLinkedList::firstnode;
		while (nextnode != nullptr) {
			if (condition(nextnode->value)) {
				newlist->append(nextnode->value);
			}
			nextnode = nextnode->next;
		}
		return *newlist;
	}
};

bool higherthantwo(int numb) {
	return (numb > 2);
}
bool lowerthanten(int numb) {
	return (numb < 10);
}
bool higherorequaltosix(int numb) {
	return (numb >= 6);
}

class Demon {
public:
	void start() {
		system("cls");
		cout << "It is demo for task 7: Filter method" << endl;
		cout << " This method returns other list,\n filtered with function,\n that we give in out method" << endl;
		cout << " Signature: FilterLinkedList<T> filter(bool (*condition)(T item))" << endl;
		cout << " \nFor instance, i created new list with elements from 1 to 10" << endl;
		FilterLinkedList<int> list,copy;
		list.append(1);
		list.append(2);
		list.append(3);
		list.append(4);
		list.append(5);
		list.append(6);
		list.append(7);
		list.append(8);
		list.append(9);
		list.append(10);
		for (int i = 0; i < (int)list.length(); i++) {
			cout << i + 1 << ". " << list[i] << endl;
		}
		cout << "\n For filtering I have function:\n";
		cout << " bool higherorequaltosix(int numb){\n	return (numb>=6);\n }\n"<< endl;
		copy = list.filter(higherorequaltosix);
		cout << " That is the result:" << endl;
		for (int i = 0; i < (int)copy.length(); i++) {
			cout << i + 1 << ". " << copy[i] << endl;
		}
		cout << "The end";
		system("pause");
	}
};

class InteractiveMode {
public:
	void start() {
		FilterLinkedList<int>* list = new FilterLinkedList<int>();
		string str[10] = {
		"Demo",
		"Filter",
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
			[]() {
				Demon d;
				d.start();
			},
			[list]() {
				cout << "Before I've created three functions,\n than can be used in function filter()\n" << endl;
				cout << "1. > 2\n2. <10\n3. >=6\n" << endl;
				cout << "Enter the number of operation: ";
				int i = 0;
				cin >> i;
				FilterLinkedList<int> newlist;
				switch (i) {
				case 1:newlist = list->filter(higherthantwo); break;
				case 2:newlist = list->filter(lowerthanten); break;
				case 3:newlist = list->filter(higherorequaltosix); break;
				}
				for (int i = 0; i < (int)newlist.length(); i++) {
					cout << i + 1 << ". " << newlist[i] << endl;
				}
				system("pause");
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
