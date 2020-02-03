#include <iostream>
#include "simpleIntLinkedList.h"
using namespace std;

ListNode::ListNode(int n)
{
	_item = n;
	_next = NULL;
}

void List::insertHead(int n)
{
	ListNode *aNewNode = new ListNode(n);
	aNewNode->_next = _head;
	_head = aNewNode;
	_size++;
};

void List::removeHead()
{
	if (_size > 0) {
		ListNode *temp = _head;
		_head = _head->_next;
		delete temp;
		_size--;
	}
}

void List::print() {
	ListNode *temp = _head;
	while (temp != NULL) {
		cout << temp->_item << " ";
		temp = temp->_next;
	}
	cout << endl; // modify this
}

bool List::exist(int n) {
	ListNode* temp = _head;
	while (temp != NULL) {
		if (temp->_item == n) return 1;
		temp = temp->_next;
	}
	return 0; // modify this
}

int List::headItem()
{
	return _head != NULL ? _head->_item : 0; // modify this
}

List::~List()
{
	while (_size != 0)
		removeHead();
};

bool List::empty() {
	return _head == NULL;
}

int List::tailItem() {
	if (List::empty()) return NULL;
	ListNode* temp = _head;
	while (temp->_next != NULL) temp = temp->_next;
	return temp->_item;
}

void List::removeTail() {
	if (List::empty() || _head->_next == NULL) return;
	ListNode* newTail = _head, *temp = _head->_next;
	while (temp->_next != NULL) {
		newTail = temp;
		temp = temp->_next;
	}
	newTail->_next=temp->_next;
	delete temp;
	_size--;
}

