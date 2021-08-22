#pragma once

#ifndef LINKEDLIST_HPP_
#define LINKEDlIST_HPP_

#include <iostream>
#include "LinkedList.h"
using namespace std;

/*
 * LISTNODE CONSTRUCTUORS AND FUNCTIONS
 */
ListNode::ListNode( int item ) {
    _item = item;
    _next = NULL;
}

void ListNode::printItem() {
    cout << _item;
}


/*
 * LIST CONSTRUCTORS AND FUNCTIONS
 */
List::List() {
    _head = NULL;
}

List::~List() {
    while ( _head ) {
        removeHead();
    }
}

void List::insertHead( int item ) {
    ListNode* newNode = new ListNode( item );
    newNode->_next = _head;
    _head = newNode;
}

int List::getHeadItem() {
    return _head->_item;
}

int List::removeHead() {
    int item = SHRT_MIN;  // -32768
    ListNode* temp;

    if ( _head ) {
        temp = _head;
        item = getHeadItem();
        _head = _head->_next;
        delete temp;
    }

    return item;
}

void List::reverse() {
    ListNode* curr = _head;
    ListNode* prev = NULL;
    ListNode* next = NULL;

    while ( curr ) {
        next = curr->_next;
        curr->_next = prev;
        prev = curr;
        curr = next;
    }

    _head = prev;
}

void List::bubbleSort( bool printAtEveryIteration ) {

    // TODO: Implement bubble sort on this implementation of single linked list.
    //       Print the linked list after every pass in the outer iteration
    //       using print(false) function in List class if parameter is true.
    //       The list should be sorted in ascending order.

    // ENTER YOUR ANSWER BELOW.
    ListNode* temp = _head;
    // If 0 or 1 item do nothing
    if (!temp || !temp->_next) return;
    bool swap = true;
    int tempItem;
    while (swap) {
        temp = _head;
        swap = false;
        while (temp->_next) {
            if (temp->_item > temp->_next->_item) {
                tempItem = temp->_next->_item;
                temp->_next->_item = temp->_item;
                temp->_item = tempItem;
                swap = true;
            }
            temp = temp->_next;
        }
        if (printAtEveryIteration && swap) print(false);
    }


    // ENTER YOUR ANSWER ABOVE.
}

void List::mergeSort() {
    recursiveMergeSort( this );
}

void List::recursiveMergeSort( List* list ) {
    // TODO: Implement merge sort on this implementation of single linked list.
    // ENTER YOUR ANSWER BELOW.
    // if single node do nothing
    if (!list->_head->_next) return;
    else {
        List list2;
        list->split(&list2);
        recursiveMergeSort(list);
        recursiveMergeSort(&list2);
        list->merge(&list2);
    }


    // ENTER YOUR ANSWER ABOVE.
}

void List::split( List* otherList ) {
    // TODO: Implement splitting of the current list.
    //       The first half of the list will be pointed by itself.
    //       The second half of the list will be pointed by otherList.
    //       It is guaranteed that the original list will have more than one node.
    //
    // ENTER YOUR ANSWER BELOW.
    ListNode* temp = _head, *cutoff = NULL;
    otherList->_head = _head;
    while (temp->_next) {
        temp = temp->_next;
        if (temp->_next) {
            temp = temp->_next;
            // If odd number
            if (!temp->_next)
                otherList->_head = otherList->_head->_next;
        }
        cutoff = otherList->_head;
        otherList->_head = otherList->_head->_next;
    }
    if (cutoff)
        cutoff->_next = NULL;

    // ENTER YOUR ANSWER ABOVE.
}

void List::merge( List* otherList ) {
    // TODO: Implement merging of current list and otherList.
    //       The otherList should be empty after merging.
    //       It is guaranteed that both lists are non-empty.
    //
    // ENTER YOUR ANSWER BELOW.
    List sortedList;

    while (_head && otherList->_head) {
        if (otherList->getHeadItem()> getHeadItem())
            sortedList.insertHead(removeHead());
        else
            sortedList.insertHead(otherList->removeHead());
    }
    while (_head)
        sortedList.insertHead(removeHead());
    while (otherList->_head)
        sortedList.insertHead(otherList->removeHead());

    while (sortedList._head)
        insertHead(sortedList.removeHead());
    // ENTER YOUR ANSWER ABOVE.
}

void List::print( bool printWithNewLine = false ) {

    ListNode* curr = _head;

    while ( curr ) {
        cout << curr->_item;

        if ( printWithNewLine )
            cout << endl;
        else
            cout << " ";

        curr = curr->_next;
    }

    cout << endl;
}

#endif
