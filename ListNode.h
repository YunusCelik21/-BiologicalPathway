// Name: Yunus Dildar Çelik
// ID: 22203347
// Section: 01

#ifndef _LISTNODE_H
#define _LISTNODE_H
#include <iostream>

template<class T>
struct ListNode {
	T* value;
	ListNode<T>* next;

	ListNode(T* value);
	ListNode(T* value, ListNode<T>* next);
	~ListNode();
};

// ---------------
// implementations
// --------------- 

template<class T>
inline ListNode<T>::ListNode(T* value) : value(value), next(nullptr) {}

template<class T>
inline ListNode<T>::ListNode(T* value, ListNode<T>* next) : value(value), next(next) {}

template<class T>
inline ListNode<T>::~ListNode() {
	ListNode<T>* curr = this->next;
	while (curr) {
		ListNode<T>* temp = curr->next;
		curr->next = nullptr;
		delete curr;
		curr = temp;
	}
}

template<class T>
void addValue(ListNode<T>*& head, T& value) {
	if ((head == nullptr) || (value < *(head->value))) {
		ListNode<T>* ptr = head;
		head = new ListNode<T>(&value, ptr);
	}
	else 
		addValue(head->next, value);
}

template<class T>
bool removeValue(ListNode<T>*& head, const T& value) {
	if (head == nullptr) {
		return false;
	}

	if (*(head->value) == value) {
		ListNode<T>* del = head;
		head = head->next;
		del->next = nullptr;
		delete del;
	}
	else 
		return removeValue(head->next, value);

}

template<class T> 
bool contains(ListNode<T>* head, const T& value) {
	while (head) {
		if (*(head->value) == value)
			return true;
		head = head->next;
	}

	return false;
}

template<class T>
void printList(ListNode<T>* head) {
	while (head) {
		head->value->print();
		head = head->next;
	}
}

template<class T>
int size(ListNode<T>* head) {
	int count = 0;
	while (head) {
		head = head->next;
		++count;
	}

	return count;
}

#endif 