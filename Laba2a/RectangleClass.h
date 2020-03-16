#pragma once
#include <iostream>
#include <iomanip>

using namespace std;

struct Position {
	Position() {
		x = y = 0;
	}
	Position(const double& nx, const double& ny) {
		x = nx;
		y = ny;
	}
	double x;
	double y;
};

class Rectangle {
public:
	Rectangle() {
		downleft = Position();
		upright = Position();
	}
	Rectangle(const Position& Ndownleft, const Position& Nupright) {
		downleft = Ndownleft;
		upright = Nupright;
	}

	Rectangle& setdownleftposition(const double& nx, const double& ny){
		downleft.x = nx;
		downleft.y = ny;
		return *this;
	}
	Rectangle& setuprightposition(const double& nx, const double& ny) {
		upright.x = nx;
		upright.y = ny;
		return *this;
	}

	Rectangle& setdownleftposition(const Position& pos) {
		downleft = pos;
		return *this;
	}
	Rectangle& setuprightposition(const Position& pos) {
		upright = pos;
		return *this;
	}

	void show() {
		cout << setprecision(4);
		cout << "Up-left: x= " << downleft.x << "; y= " << upright.y << endl;
		cout << "Up-right: x= " << upright.x << "; y= " << upright.y << endl;
		cout << "Down-left: x= " << downleft.x << "; y= " << downleft.y << endl;
		cout << "Down-right: x= " << downleft.y << "; y= " << upright.x << endl;
	}
	void setrec() {
		cout << "Enter coordinates of down-left point(x y): ";
		cin >> downleft.x >> downleft.y;
		cout << "Enter coordinates of up-right point(x y): ";
		cin >> upright.x >> upright.y;
	}
private:
	Position downleft;
	Position upright;
};