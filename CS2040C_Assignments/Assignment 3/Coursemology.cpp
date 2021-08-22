#include <iostream>
using namespace std;
template <class T>
class BinarySearchTree;

template <class T>
class TreeNode {
private:
	T _item;
	TreeNode<T>* _left;
	TreeNode<T>* _right;
	int _height;
public:
	TreeNode(T x) { _left = _right = NULL; _item = x; _height = 0; };

	friend BinarySearchTree<T>;
	
	//You may add any further functions/variables here, if necessary.
	//But please do not modify any of the functions above in this class.
};

template <class T>
class BinarySearchTree {
private:
	int _size;
	TreeNode<T>* _root;
	void _printTree(int indent, TreeNode<T>*, bool withHeight);

	bool _exist(TreeNode<T>* node, T x);

	void _updateHeight(TreeNode<T>*);

	void _preOrderPrint(TreeNode<T>*);
	void _inOrderPrint(TreeNode<T>*);
	void _postOrderPrint(TreeNode<T>*);
	TreeNode<T>* _insert(TreeNode<T>* current, T x);
	
	int _balance(TreeNode<T>*);
	TreeNode<T>* _rightRotation(TreeNode<T>*);
	TreeNode<T>* _leftRotation(TreeNode<T>*);
    void _destroySubTree(TreeNode<T>*);

public:
	BinarySearchTree() { _root = NULL; _size = 0; }
	~BinarySearchTree();
	int size() { return _size; };
	void insert(T);
	void printTree(bool withHeight = 1);
	void inOrderPrint();
	void postOrderPrint();
	void preOrderPrint();
	T searchMax() ;
	T searchMin();
	bool exist(T x);
	T successor(T);
	
	//You may add any further functions/variables here, if necessary.
	//But please do not modify any of the functions above in this class.
};


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
int BinarySearchTree<T>::_balance(TreeNode <T>* current) {
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
	
	int balance = _balance(current);
	// Left heavy current
	if (balance > 1) {
		// Right heavy current.left
		if (_balance(current->_left) < 0)
			current->_left = _leftRotation(current->_left);
		current = _rightRotation(current);
	}
	// Right heavy current
	else if (balance < -1) {
		// Left heavy current.right
		if (_balance(current->_right) > 0)
			current->_right = _rightRotation(current->_right);
		current = _leftRotation(current);
	}
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
	// Assume non-empty (_size > 0)
	TreeNode<T>* temp = _root;
	T tempItem, lastRight = T();
	while (temp) {
		tempItem = temp->_item;
		if (x == tempItem && temp->_right) {
			// Minimum of right subtree
			temp = temp->_right;
			while (temp->_left)
				temp = temp->_left;
			return temp->_item;
		}
		else if (x < tempItem) {
			lastRight = tempItem;
			temp = temp->_left;
		}
		else
			temp = temp->_right;
	}
	// Reach null
	return lastRight;
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

//If you defined any further functions in the above classes, remember to include them.


