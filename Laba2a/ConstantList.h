#pragma once
#include "List.h"

template<typename T>
class ConstantList : public List<T>{
public:
	ConstantList() {
		this->create_empty(100);
	}
	ConstantList(const int& size) {
		this->create_empty(size);
	}

	ConstantList& create_empty() {
		return this->create_empty(100);
	}
	ConstantList& create_empty(const int& size) {
		arr = new T[size];
		maxarrsize = size;
		arrsize = 0;
		return *this;
	}

	ConstantList& append(const T& item) {
		if (arrsize == maxarrsize) {
			throw std::exception("Array is full");
		}
		arr[arrsize] = item;
		arrsize++;
		return *this;
	}
	ConstantList& insert(const T& item, const int& index) {
		indexcheck(index);
		int i = arrsize;
		for (; i > index + 1; i--) {
			arr[i] = arr[i - 1];
		}
		arr[i] = item;
		arrsize++;
		return *this;
	}
	ConstantList& remove(const int& index) {
		indexcheck(index);
		for (int i = index; i < (int)arrsize - 1; i++) {
			arr[i] = arr[i + 1];
		}
		arrsize--;
		return *this;
	}

	T& get(const int& index) {
		indexcheck(index);
		return arr[index];
	}
	ConstantList& set(const T& item, const int& index) {
		indexcheck(index);
		arr[index] = item;
		return *this;
	}

	T& operator[](const int& index) {
		return this->get(index);
	}

	unsigned int length() {
		return arrsize;
	}
protected:
	T* arr = nullptr;
	unsigned arrsize = 0;
	unsigned maxarrsize = 0;
	void indexcheck(const int& index) {
		if ((index >= (int)arrsize) || (index < 0)) {
			throw std::exception("Invalid index");
		}
	}
};