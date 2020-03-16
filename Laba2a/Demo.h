#pragma once
#include <iostream>

using namespace std;

class Demo {
public:
	void start() {
		system("cls");
		cout << " Welcome to Demo Mode!" << endl;
		cout << " In this lab I've writen three types of list:" << endl;
		cout << "  Using Vector\n  Using Constant array\n  Using Linked list\n" << endl;
		cout << " All these lists support:\n";
		cout << "  - create_empty()\n  - append(item)" << endl;
		cout << "  - insert(item,index)\n  - remove(index)" << endl;
		cout << "  - get(index)\n  - set(item,index)" << endl;
		cout << "  - length()" << endl;
		system("pause");
		system("cls");
		cout << " In menu you can try all this\n functions by creating list in:" << endl;
		cout << "  <Start> option" << endl;
		cout << " There you can create list (Vector,Constant,Linked)." << endl;
		cout << " After list choosing you will automaticaly\n redirect in actions menu." << endl;
		cout << " From all munes you can exit by choosing option <Exit>.";
		system("pause");
		system("cls");
		cout << " For this Lab was also created new class: Rectangle"<< endl;
		cout << " that contains two positions: left-down point, and up-right point." << endl;
		cout << " It has constructor: Rectangle(Position,Position) , which uses structure Position" << endl;
		cout << " Position structure also have constructor: Position(double,double)" << endl;
		cout << " Class Rectangle also have own methods setrec() and show(), that help to set rectangle correctly" << endl;
		cout << " That class have methods to set exacly\n left-down point(setdownleftposition)\n or\n up-right point(setuprightposition())" << endl;
		cout << " These methods have as arguments or (Position structure) or (double,double)" << endl;
		system("pause");
		system("cls");
		cout << " In menu you can also try <Benchmark> opion." << endl;
		cout << " It starts write and delete test for each type of list." << endl;
		cout << " This test contains two actions:" << endl;
		cout << " 1) append N elements" << endl;
		cout << " 2)Delete last element till  list is empty" << endl;
		cout << " Try, and you will see how many elements it test per certain time period" << endl;
		system("pause");
		system("cls");
		cout << " That is all." << endl;
		system("pause");
	}
};
