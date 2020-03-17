#include <iostream>
#include "LinkedList.h"
using namespace std;

void testBubbleSort();
void testSplit();
void testMerge();
void testMergeSort();

int main() {

    testBubbleSort();
    testSplit();
    testMerge();
    testMergeSort();
    return 0;
}

void testBubbleSort() {

    cout << "Problem 2 Task 1: Bubble Sort" << endl;
    cout << "=============================" << endl;

    List invertedList;
    for ( int i = 0; i < 10; i ++ )
        invertedList.insertHead( i * 10 );

    cout << "Current List with 10 elements: ";
    invertedList.print();
    cout << endl;

    cout << "Sorting the list using bubbleSort, with printing after each pass:" << endl;
    invertedList.bubbleSort( true );
    cout << endl;

    cout << "Sorted List with 10 elements: ";
    invertedList.print();
    cout << endl << endl;

    List normalList;
    normalList.insertHead( -20 );
    normalList.insertHead( 20 );
    normalList.insertHead( 30 );
    normalList.insertHead( 10 );
    normalList.insertHead( 40 );

    cout << "Current List with 5 elements: ";
    normalList.print();
    cout << endl;

    cout << "Sorting the list using bubbleSort, without printing after each pass." << endl;
    normalList.bubbleSort( false );
    cout << endl;

    cout << "Sorted List with 5 elements: ";
    normalList.print();
    cout << endl << endl;

    cout << endl;
}

void testSplit() {

    cout << "Problem 2 Task 2: Split" << endl;
    cout << "=======================" << endl;

    List firstList;
    List secondList;

    cout << "List with even number of elements." << endl;
    for ( int i = 0; i < 10; i ++ )
        firstList.insertHead( i * 10 );

    cout << "First List with 10 elements: ";
    firstList.print();
    cout << endl;

    cout << "Second List with 0 elements: ";
    secondList.print();
    cout << endl;

    cout << "Splitting the list into firstList and secondList." << endl << endl;

    firstList.split( &secondList );

    cout << "First List: ";
    firstList.print();
    cout << endl;

    cout << "Second List: ";
    secondList.print();
    cout << endl << endl;

    cout << "List with odd number of elements." << endl;
    List thirdList;
    List fourthList;
    for ( int i = 0; i < 9; i ++ )
        thirdList.insertHead( i * 10 );

    cout << "Third List with 9 elements: ";
    thirdList.print();
    cout << endl;

    cout << "Fourth List with 0 elements: ";
    fourthList.print();
    cout << endl;

    cout << "Splitting the list into thirdList and fourthList." << endl << endl;

    thirdList.split( &fourthList );

    cout << "Third List: ";
    thirdList.print();
    cout << endl;

    cout << "Fourth List: ";
    fourthList.print();
    cout << endl;
    cout << "If your first linked list contains 80 70 60 50, and your second linked list contains 40 30 20 10 0,\nyou will still be awarded full marks for this test case.";
    cout << endl << endl;

    List fifthList;
    List sixthList;
    int arr[] = { 72, 63, 54, 45, 36, 27, 18, 9, 0 };
    for (int i = 0; i < 9; i++)
        fifthList.insertHead(arr[8-i]);

    cout << "Fifth List with 9 elements: ";
    fifthList.print();
    cout << "Splitting the list into fifthList and sixthList." << endl << endl;
    fifthList.split(&sixthList);
    cout << "Fifth List: ";
    fifthList.print();
    cout << endl;

    cout << "Fourth List: ";
    sixthList.print();
    cout << endl;
    cout << endl;
    cout << endl;
}

void testMerge() {

    cout << "Problem 2 Task 3: Merge" << endl;
    cout << "=======================" << endl;

    List firstList;
    for ( int i = 9; i >= 0; i -= 2 ) {
        firstList.insertHead( i * 10 );
    }

    List secondList;
    for ( int i = 8; i >= 0; i -= 2 ) {
        secondList.insertHead( i * 10 );
    }

    cout << "First List with 5 elements: ";
    firstList.print();
    cout << endl;

    cout << "Second List with 5 elements: ";
    secondList.print();
    cout << endl;


    cout << "Merging the two lists together." << endl << endl;
    firstList.merge( &secondList );

    cout << "Merged list with 10 elements: ";
    firstList.print();
    cout << endl;

    cout << "Second list with no elements: ";
    secondList.print();
    cout << endl << endl;

    cout << endl;
}

void testMergeSort() {

    cout << "Problem 2 Task 4: Merge Sort" << endl;
    cout << "============================" << endl;

    List invertedList;
    for ( int i = 0; i < 10; i ++ )
        invertedList.insertHead( i * 10 );

    cout << "Current List with 10 elements: ";
    invertedList.print();
    cout << endl;

    cout << "Sorting the list using mergeSort." << endl;
    invertedList.mergeSort();
    cout << endl;

    cout << "Sorted List with 10 elements: ";
    invertedList.print();
    cout << endl << endl;

}
