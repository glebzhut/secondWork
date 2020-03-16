#pragma once
#include "List.h"
#include <vector>	

template<typename T>
class VectorList: public List<T> {
public:
	VectorList() {
		this->create_empty();
	}

	VectorList& create_empty(){
		std::vector<T> newarr;
		arr = newarr;
		return *this;
	}

	VectorList& append(const T& item){
		arr.push_back(item);
		return *this;
	}
	VectorList& insert(const T& item, const int& index){
		indexcheck(index);
		std::vector<T> newone;
		int i = 0;
		for (; i <= index; i++) {
			newone.push_back(arr[i]);
		}
		newone.push_back(item);
		for (; i < (int)arr.size(); i++) {
			newone.push_back(arr[i]);
		}
		arr = newone;
		return *this;
	}
	VectorList& remove(const int& index){
		indexcheck(index);
		if (index == (int)arr.size() - 1) {
			arr.pop_back();
		}
		else arr.erase(arr.begin() + index);
		return *this;
	}

	T& get(const int& index){
		indexcheck(index);
		return arr[index];
	}
	VectorList& set(const T& item, const int& index){
		indexcheck(index);
		arr[index] = item;
		return *this;
	}

	T& operator[](const int& index) {
		return this->get(index);
	}

	unsigned int length(){
		return arr.size();
	}
protected:
	std::vector<T> arr;
	void indexcheck(const int& index) {
		if ((index >= (int)arr.size()) || (index < 0)) {
			throw std::exception("Invalid index");
		}
	}
};