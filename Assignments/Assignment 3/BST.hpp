#pragma once
#ifndef BSTHPP
#define BSTHPP
#include "BST.h"

template <class T>
void BinarySearchTree<T>::_updateHeight(TreeNode <T>* current) {
	int leftHeight = -1, rightHeight = -1;
	if (current->_left)
		leftHeight = current->_left->_height;
	if (current->_right)
		rightHeight = current->_right->_height;
	current->_height = leftHeight > rightHeight ? leftHeight + 1 : rightHeight + 1;
}

template <class T>
short BinarySearchTree<T>::_balance(TreeNode <T>* current) {
	int leftHeight = -1, rightHeight = -1;
	if (current->_left)
		leftHeight = current->_left->_height;
	if (current->_right)
		rightHeight = current->_right->_height;
	return leftHeight - rightHeight;
}

template <class T>
TreeNode<T>* BinarySearchTree<T>::_insert(TreeNode<T>* current, T x) {


	if (current->_item > x)
	{
		if (current->_left)
			current->_left = _insert(current->_left, x);
		else
		{
			current->_left = new TreeNode<T>(x);
			_size++;
		}
	}
	else if (x > current->_item) {
		if (current->_right)
			current->_right = _insert(current->_right, x);
		else
		{
			current->_right = new TreeNode<T>(x);
			_size++;
		}
	}
	else
		return current;
	
	_updateHeight(current);
	
	short balance = _balance(current);
	// Left heavy current
	if (balance > 1) {
		// Right heavy current.left
		if (_balance(current->_left) < -1)
			current->_left = _leftRotation(current->_left);
		current = _rightRotation(current);
	}
	// Right heavy current
	else if (balance < -1) {
		// Left heavy current.right
		if (_balance(current->_right) > 1)
			current->_right = _rightRotation(current->_right);
		current = _leftRotation(current);
	}
	//_updateHeight(current);
	return current;

}

template <class T>
void BinarySearchTree<T>::insert(T x) {

	if (_root == NULL) {
		_root = new TreeNode<T>(x);
		_size++;
	}
	else
		_root = _insert(_root, x);

}

template <class T>
bool BinarySearchTree<T>::_exist(TreeNode<T>* node, T x) {
	// If null node then not in tree
	if (!node) return false;
	T curr = node->_item;
	if (curr == x)
		return true;
	else if (x < curr)
		return _exist(node->_left, x);
	else
		return _exist(node->_right, x);

}

template <class T>
bool BinarySearchTree<T>::exist(T x) {
	return _exist(_root, x);
}

template <class T>
T BinarySearchTree<T>::searchMax() {
	// Assume non-empty (_size > 0)
	TreeNode<T>* temp = _root;
	while (temp->_right)
		temp = temp->_right;
	return temp->_item;
}

template <class T>
T BinarySearchTree<T>::searchMin() {
	// Assume non-empty (_size > 0)
	TreeNode<T>* temp = _root;
	while (temp->_left)
		temp = temp->_left;
	return temp->_item;
}


template <class T>
T BinarySearchTree<T>::successor(T x)
{
	if (!_root) return T();
	// Assume non-empty (_size > 0)
	TreeNode<T>* temp = _root, *lastRight = _root;
	T tempItem = temp->_item;
	while (temp) {
		tempItem = temp->_item;
		if (x == tempItem) {
			if (temp->_right)
				return temp->_right->_item;
			else
				return lastRight->_item;
		}
		else if (x < tempItem) {
			lastRight = temp;
			temp = temp->_left;
		}
		else
			temp = temp->_right;
	}
	// Reach null
	return lastRight->_item;
}

template <class T>
TreeNode<T>* BinarySearchTree<T>::_leftRotation(TreeNode<T>* node)
{
	TreeNode<T> * newRoot = node->_right;
	node->_right = newRoot->_left;
	newRoot->_left = node;
	_updateHeight(node);
	_updateHeight(newRoot);
	return newRoot;
}

template <class T>
TreeNode<T>* BinarySearchTree<T>::_rightRotation(TreeNode<T>* node)
{
	TreeNode<T> * newRoot = node->_left;
	node->_left = newRoot->_right;
	newRoot->_right = node;
	_updateHeight(node);
	_updateHeight(newRoot);
	return newRoot;
}

template <class T>
void BinarySearchTree<T>::printTree(bool withHeight) {
	_printTree(0, _root, withHeight);
}

template <class T>
void BinarySearchTree<T>::preOrderPrint() {
	_preOrderPrint(_root);
	cout << endl;
}


template <class T>
void BinarySearchTree<T>::_preOrderPrint(TreeNode<T>* node) {
	if (!node) return;
	cout << node->_item << " ";
	_preOrderPrint(node->_left);
	_preOrderPrint(node->_right);
}

template <class T>
void BinarySearchTree<T>::inOrderPrint() {
	_inOrderPrint(_root);
	cout << endl;	
}

template <class T>
void BinarySearchTree<T>::_inOrderPrint(TreeNode<T>* node) {
	if (!node) return;
	_inOrderPrint(node->_left);
	cout << node->_item << " ";
	_inOrderPrint(node->_right);
}



template <class T>
void BinarySearchTree<T>::postOrderPrint() {
	_postOrderPrint(_root);
	cout << endl;
}

template <class T>
void BinarySearchTree<T>::_postOrderPrint(TreeNode<T>* node) {
	if (!node) return;
	_postOrderPrint(node->_left);
	_postOrderPrint(node->_right);
	cout << node->_item << " ";
}



template <class T>
void BinarySearchTree<T>::_printTree(int indent, TreeNode<T>* node, bool withHeight) {

	if (!node)
		return;

	if (node->_right)
		_printTree(indent + 2, node->_right, withHeight);
	for (int i = 0; i < indent; i++)
		cout << "  ";
	cout << node->_item;
	if (withHeight)
		cout << "(h=" << node->_height << ")";
	cout << endl;
	if (node->_left)
		_printTree(indent + 2, node->_left, withHeight);


};


template <class T>
void BinarySearchTree<T> ::_destroySubTree(TreeNode<T>* node)
{
	if (node->_left)
		_destroySubTree(node->_left);
	if (node->_right)
		_destroySubTree(node->_right);
	delete node;
}

template <class T>
BinarySearchTree<T> :: ~BinarySearchTree()
{
	if (_root)
		_destroySubTree(_root);
}


#endif
