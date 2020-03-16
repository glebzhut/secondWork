#pragma once
#include "List.h"
#include <vector>	

template<typename T>
class LinkedList : public List<T> {
public:
	LinkedList() {
		this->create_empty();
	}

	LinkedList& create_empty() {
		firstnode = new Node();
		arrsize = 0;
		return *this;
	}

	LinkedList& append(const T& item) {
		if (arrsize == 0) {
			firstnode->value = item;
		}
		else {
			Node* newnode = new Node(nullptr, item);
			Node* lastnode = getnode(arrsize - 1);
			lastnode->next = newnode;
		}
		arrsize++;
		return *this;
	}
	LinkedList& insert(const T& item, const int& index) {
		indexcheck(index);
		Node* previousnode = getnode(index);
		Node* newnode = new Node(previousnode->next, item);
		previousnode->next = newnode;
		arrsize++;
		return *this;
	}
	LinkedList& remove(const int& index) {
		indexcheck(index);
		if (arrsize != 1) {
			Node* prevnode = getnode(index - 1);
			Node* deletenode = prevnode->next;
			prevnode->next = deletenode->next;
			delete deletenode; 
		}
		arrsize--;
		return *this;
	}

	T& get(const int& index) {
		indexcheck(index);
		Node* searchednode = getnode(index);
		return searchednode->value;
	}
	LinkedList& set(const T& item, const int& index) {
		indexcheck(index);
		Node* searchednode = getnode(index);
		searchednode->value = item;
		return *this;
	}

	T& operator[](const int& index) {
		return this->get(index);
	}

	unsigned int length() {
		return arrsize;
	}
protected:
	struct Node {
		Node() {
			next = nullptr;
		}
		Node(Node* nextnode, const T& item) {
			next = nextnode;
			value = item;
		}
		Node* next;
		T value;
	};
	unsigned arrsize;
	Node* firstnode;
	void indexcheck(const int& index) {
		if ((index >= (int)arrsize) || (index < 0)) {
			throw std::exception("Invalid index");
		}
	}
	Node* getnode(const int& index) {
		Node* iteratornode = firstnode;
		for (int i = 0; i < index; i++) {
			iteratornode = iteratornode->next;
		}
		return iteratornode;
	}
	Node* createnode() {
		Node* node = new Node();
		return node;
	}
};

