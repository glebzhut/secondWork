#pragma once
#include "LinkedList.h"
#include "ConstantList.h"
#include "VectorList.h"
#include "RectangleClass.h"
#include "Benchmark.h"
#include "Demo.h"

class InteractiveMode {
public:
	void start();
private:
	void actions(List<Rectangle>* list);
	void typechoose();
};