#pragma once

#ifndef SIMPLELINKEDLISTTEMPLATEHPP
#define SIMPLELINKEDLISTTEMPLATEHPP

#include <iostream>
#include "simpleLinkedListTemplate.h"
using namespace std;


template <class T>
ListNode<T>::ListNode(T n)
{
	_item = n;
	_next = NULL;
}

template <class T>
void List<T>::insertHead(T n)
{
	ListNode<T> *aNewNode = new ListNode<T>(n);
	aNewNode->_next = _head;
	_head = aNewNode;
	_size++;
};

template <class T>
void List<T>::removeHead()
{
	if (_size > 0) {
		ListNode<T> *temp = _head;
		_head = _head->_next;
		delete temp;
		_size--;
	}
}

template <class T>
void List<T>::print(bool withNL) {

	ListNode<T> *temp = _head;
	while (temp) {
		cout << temp->_item;
		if (withNL)
			cout << endl;
		else
			cout << " ";
		temp = temp->_next;
	}
	cout << endl;
	  
}

template <class T>
bool List<T>::exist(T n) {
	ListNode<T>* temp = _head;
	while (temp) {
		if (temp->_item == n) return true;
		temp = temp->_next;
	}
	// modify this
	return false; 
}

template <class T>
T List<T>::headItem()
{
	if (_size)
		return *_head;
}

template <class T>
T List<T>::extractMax()
{
	if (!_size) return NULL;
	// Assume non-empty
	ListNode<T>* temp = _head, *maxNode = _head, *b_maxNode = NULL;
	T maxItem = _head->_item; // to keep track of max item

	while (temp->_next) {
		
		if (temp->_next->_item > maxNode->_item) {
			maxNode = temp->_next;
			b_maxNode = temp;
			maxItem = maxNode->_item;
		}
		temp = temp->_next;
	}

	// If the greatest is at the head, b_maxNode will stil be NULL
	if (!b_maxNode)
		removeHead();
	else {
		b_maxNode->_next = maxNode->_next;
		delete maxNode;
		_size--;
	}


	// if there are duplicates maximas in the list, return the leftmost one (the one closest to the _head)
	return maxItem;
}
/* Disadvantages:
The sort take O(N^2) time complexity as it has to traverse the entire linked list to find each maximum
The linked list itself is also lost as each ListNode is deleted when retrieving each _item	*/

template <class T>
void List<T>::reverseOp() {
	if (_size < 2) return; //Do nothing

	ListNode<T>* before = NULL, *curr = _head, *after = _head->_next;
	while (after) {
		curr->_next = before;
		before = curr;
		curr = after;
		after = after->_next;
	}

	curr->_next = before;
	_head = curr;
}



template <class T>
List<T>::~List()
{
	while (_head)
		removeHead();
};


#endif