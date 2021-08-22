#pragma once

class ListNode {

private:
    int _item;
    ListNode* _next;

public:
    ListNode( int );        // Constructs the list node with parameter
    void printItem();       // Prints the item

    friend class List;
};

class List {

private:
    ListNode* _head;
    void recursiveMergeSort( List* );   // TODO: Implement merge sort

public:
    List();                             // Constructs an empty list
    ~List();                            // Destructs a list

    void insertHead( int );             // Inserts the new value into the linked list
    int getHeadItem();                  // Retrieves the value in the head node
    int removeHead();                   // Removes the head node and returns the value removed

    void reverse();                     // Reverses the list

    void bubbleSort( bool );            // TODO: Implement bubble sort
    void mergeSort();                   // Calls the recursive merge sort function

    void split( List* );                // TODO: Splits the linked lists into two halves
    void merge( List* );                // TODO: Merge two linked lists in ascending order

    void print( bool );                 // Prints all items of the linked lists.
};

#include "LinkedList.hpp"
