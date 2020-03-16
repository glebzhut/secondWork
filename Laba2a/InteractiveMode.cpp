#include "InteractiveMode.h"
#include <conio.h>
#include <iostream>
#include <functional>

using namespace std;

void InteractiveMode::start() {
	string str[4] = {
		"Start",
		"Benchmark",
		"Demo",
		"Exit"
	};
	bool exit = false;
	int arrow = 0;
	function<void()> functions[4] = {
		[this](){
			this->typechoose();
		},
		[]() {
			Benchmark mark;
			mark.start();
		},
		[]() {
			Demo d;
			d.start();
		},
		[&exit]() {
			exit = !exit;
		}

	};
	while (!exit) {
		system("cls");
		for (int i = 0; i < 4; i++) {
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
				else arrow = 3;
			}
			else if ((int)key == 80) {
				if (arrow < 3) arrow++;
				else arrow = 0;
			}
		}
		else if ((int)key == 13) {
			functions[arrow]();
		}
	}
}
void  InteractiveMode::typechoose() {
	string str[4] = {
		"Linked",
		"Constant",
		"Vector",
		"Exit"
	};
	bool exit = false;
	int arrow = 0;
	function<void()> functions[4] = {
		[this]() {
			List<Rectangle>* list = new LinkedList<Rectangle>();
			list->create_empty();
			actions(list);
		},
		[this]() {
			List<Rectangle>* list = new ConstantList<Rectangle>();
			list->create_empty();
			actions(list);
		},
		[this]() {
			List<Rectangle>* list = new VectorList<Rectangle>();
			list->create_empty();
			actions(list);
		},
		[&exit]() {
			exit = !exit;
		}

	};
	while (!exit) {
		system("cls");
		cout << "Choose list type:" << endl;
		for (int i = 0; i < 4; i++) {
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
				else arrow = 3;
			}
			else if ((int)key == 80) {
				if (arrow < 3) arrow++;
				else arrow = 0;
			}
		}
		else if ((int)key == 13) {
			functions[arrow]();
		}
	}
}
void  InteractiveMode::actions(List<Rectangle>* list) {
	string str[7] = {
		"Create_empty",
		"Append",
		"Insert",
		"Remove",
		"Get",
		"Set",
		"Exit"
	};
	bool exit = false;
	int arrow = 0;
	function<void()> functions[7] = {
		[list]() {
			list->create_empty();
		},
		[list]() {
			Rectangle newrec;
			newrec.setrec();
			list->append(newrec);
		},
		[list]() {
			cout << "Enter index: ";
			int ind;
			cin >> ind;
			Rectangle newrec;
			newrec.setrec();
			try {
				list->insert(newrec, ind);
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
				list->get(ind).show();
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
			Rectangle newrec;
			newrec.setrec();
			try {
				list->set(newrec, ind);
			}
			catch (exception & ex) {
				cout << ex.what() << endl;
				system("pause");
			}
		},
		[&exit]() {
			exit = !exit;
		}

	};
	while (!exit) {
		system("cls");
		cout << "Size of list:  " << list->length() << endl;
		for (int i = 0; i < 7; i++) {
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
				else arrow = 6;
			}
			else if ((int)key == 80) {
				if (arrow < 6) arrow++;
				else arrow = 0;
			}
		}
		else if ((int)key == 13) {
			functions[arrow]();
		}
	}
}