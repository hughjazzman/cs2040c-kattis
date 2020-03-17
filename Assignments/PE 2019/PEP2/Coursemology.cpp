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