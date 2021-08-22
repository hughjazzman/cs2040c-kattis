#pragma once
#include <math.h>

#include <iostream>
using namespace std;

#ifndef HEAPHPP
#define HEAPHPP

template <class T>
void Heap<T>::_swap(int i, int j) {
	T temp = _heap[i];
	_heap[i] = _heap[j];
	_heap[j] = temp;
}

template <class T>
void Heap<T>::_bubbleUp(int index) {
	int parent = floor((index - 1) / 2);
	while (index > 0) {
		// If parent already larger do nothing
		if (_heap[parent] > _heap[index]) return;
		_swap(parent, index);
		index = parent;
		parent = floor((index - 1) / 2);
	}
}

template <class T>
void Heap<T>::_bubbleDown(int index) {
	int left = 2 * index + 1, right = left + 1, higher;
	while (right < _n) {
		T idxT = _heap[index], leftT = _heap[left], rightT = _heap[right];
		// If both child smaller do nothing
		if (idxT > leftT && idxT > rightT) return;
		// Higher priority placed into index
		higher = leftT > rightT ? left : right;
		_swap(higher, index);
		index = higher;
		left = 2 * index + 1;
		right = left + 1;
	}
	// Deal with no right, and left child higher priority
	if (left < _n && _heap[left] > _heap[index])
	    _swap(index, left);
}

template <class T>
void Heap<T>::insert(T item) {
	_heap[_n] = item;
	_bubbleUp(_n++);
}

template <class T>
T Heap<T>::extractMax() {
	T mx = peekMax();
	_heap[0] = _heap[--_n];
	_bubbleDown(0);
	return mx;
}


template <class T>
void Heap<T>::printHeapArray() {
	for (int i = 0; i < _n; i++)
		cout << _heap[i] << " ";
	cout << endl;
}

template <class T>
int Heap<T>::_lookFor(T x){ // not a very good implementation, but just use this for now.
    int i;
    for(i=0;i<_n;i++)
        if (_heap[i] == x)
            return i;
    
    return -1;
}

template <class T>
void Heap<T>::decreaseKey(T from, T to)
{
	int i = _lookFor(from);
	// If not found do nothing
	if (i == -1) return;
	_heap[i] = to;
	_bubbleDown(i);
}


template <class T>
void Heap<T>::increaseKey(T from, T to)
{
	int i = _lookFor(from);
	// If not found do nothing
	if (i == -1) return;
	_heap[i] = to;
	_bubbleUp(i);
}

template <class T>
void Heap<T>::deleteItem(T x)
{
	int i = _lookFor(x);
	// If not found do nothing
	if (i == -1) return;
	T last = _heap[--_n];
	_heap[i] = last;
	x > last ? _bubbleDown(i) : _bubbleUp(i);
}

template <class T>
void Heap<T>::printTree() {
    int parity = 0;
	if (_n == 0)
		return;
	int space = pow(2,1 + (int) log2f(_n)),i;
	int nLevel = (int) log2f(_n)+1;
	int index = 0,endIndex;
    int tempIndex;
	
	for (int l = 0; l < nLevel; l++)
	{
		index = 1;
        parity = 0;
		for (i = 0; i < l; i++)
			index *= 2;
		endIndex = index * 2 - 1;
		index--;
        tempIndex = index;
        while (index < _n && index < endIndex) {
            for (i = 0; i < space-1; i++)
                cout << " ";
            if(index==0)
                cout << "|";
            else if (parity)
                cout << "\\";
            else
                cout << "/";
            parity = !parity;
            for (i = 0; i < space; i++)
                cout << " ";
			index++;
		}
        cout << endl;
        index=tempIndex;
		while (index < _n && index < endIndex) {
			for (i = 0; i < (space-1-((int) log10(_heap[index]))); i++)
				cout << " ";
			cout << _heap[index];
			for (i = 0; i < space; i++)
				cout << " ";
			index++;
		}
		
		cout << endl;
		space /= 2;
	}

}






#endif
