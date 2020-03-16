#pragma once

template<typename T>
class List {
public:
	virtual List& create_empty() = 0;
	virtual List& append(const T& item) = 0;
	virtual List& insert(const T& item, const int& index) = 0;
	virtual List& remove(const int& index) = 0;
	virtual T& get(const int& index) = 0;
	virtual List& set(const T& item, const int& index) = 0;
	//virtual T& operator[](const T& index) = 0;
	virtual unsigned int length() = 0;
};