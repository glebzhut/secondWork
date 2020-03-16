#pragma once
#include "ConstantList.h"
#include "LinkedList.h"
#include "VectorList.h"
#include "RectangleClass.h"
#include <chrono>

using namespace std;
using namespace std::chrono;

class Benchmark {
public:
	void start() {
		cout << "Linked List Benchmark Test:\n\n";
		List<Rectangle>* list = new LinkedList<Rectangle>();
		check(list);
		cout << "Constant List Benchmark Test:\n\n";
		list = new ConstantList<Rectangle>(10000000);
		check(list);
		cout << "Vector List Benchmark Test:\n\n";
		list = new VectorList<Rectangle>();
		check(list);
		delete list;
		system("pause");
	}
private:
	void check(List<Rectangle>* list) {
		long N = 100;
		auto st = high_resolution_clock::now();
		auto end = high_resolution_clock::now();
		auto dur = duration_cast<milliseconds>(end - st);
		while (dur.count() < 1000) {
			N *= 2;
			st = high_resolution_clock::now();
			pushNitems(list, N);
			removeNitems(list, N);
			end = high_resolution_clock::now();
			dur = duration_cast<milliseconds>(end - st);
		}
		cout << "Number of elements: " << N << endl;
		cout << "Size: " << N * sizeof(Rectangle) << " bytes" << endl;
		cout << "Time: " << dur.count() << " milliseconds\n" << endl;
	}
	void pushNitems(List<Rectangle>* list,const int N) {
		for (int i = 0; i < N; i++) {
			list->append(*(new Rectangle()));
		}
	}
	void removeNitems(List<Rectangle>* list,const int N) {
		for (int i = 0; i < N; i++) {
			list->remove((int)(list->length())-1);
		}
	}
};