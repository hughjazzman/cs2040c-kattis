#include "HashTable.h"

void testHashFunction();
void testInsertWithoutCollision_1();
void testDeleteWithoutCollision_1();
void testExistWithoutCollision_1();
void testInsertWithCollision_1();
void testDeleteWithCollision_1();
void testExistWithCollision_1();


int main() {
	
	// uncomment the following code for your testing

	testHashFunction();

	testInsertWithoutCollision_1();

	testDeleteWithoutCollision_1();

	testExistWithoutCollision_1();

	testInsertWithCollision_1();

	testDeleteWithCollision_1();

	testExistWithCollision_1();


}

void testHashFunction() {

	cout << "Test Hash Function" << endl; 

	cout << "h(7)" << endl;
	cout << "Output: " << h(7) << endl;
	cout << "Expected: " << 7 << endl;


	cout << "h(25)" << endl;
	cout << "Output: " << h(25) << endl;
	cout << "Expected: " << 7 << endl;

	cout << endl << endl;
}

void testInsertWithoutCollision_1() {

	cout << "Test Insert Without Collision" << endl;

	HashTable ht(50);

	int i = 1;

	//insert 1-9
	while (i < 10) {
		ht.insertWithoutCollision(i++);
	}
	ht.insertWithoutCollision(444); //sum of digits is 12
	ht.insertWithoutCollision(555); //sum of digits is 15
	ht.insertWithoutCollision(99); //sum of digits is 18
	ht.insertWithoutCollision(1234567); //sum of digits is 28
	ht.insertWithoutCollision(9994); //sum of digits is 40

	cout << "Your output" << endl;
	ht.printHashTable();

	cout << "Expected output" << endl;
	int arr[50];
	for (int i = 0; i < 50; i++) {
		arr[i] = 0;
	}
	for (int i = 1; i < 10; ++i) {
		arr[i] = i;
	}
	arr[12] = 444;
	arr[15] = 555;
	arr[18] = 99;
	arr[28] = 1234567;
	arr[31] = 9994;

	for (auto i : arr) {
		cout << i << " ";
	}

	cout << endl << endl;
}


void testDeleteWithoutCollision_1() {

	cout << "Test Delete Without Collision" << endl;

	HashTable ht(50);

	int i = 1;

	//insert 1-9
	while (i < 10) {
		ht.insertWithoutCollision(i++);
	}

	ht.deleteWithoutCollision(1);
	ht.deleteWithoutCollision(3);
	ht.deleteWithoutCollision(5);
	ht.deleteWithoutCollision(9);

	//deleting item which dont exist in HT
	ht.deleteWithoutCollision(99); 

	cout << "Your output" << endl;
	ht.printHashTable();

	cout << "Expected output" << endl;
	int arr[50];
	for (int i = 0; i < 50; i++) {
		arr[i] = 0;
	}
	for (int i = 1; i < 10; ++i) {
		arr[i] = i;
	}
	arr[1] = -1;
	arr[3] = -1;
	arr[5] = -1;
	arr[9] = -1;

	for (auto i : arr) {
		cout << i << " ";
	}

	cout << endl << endl;
}

void testExistWithoutCollision_1() {

	cout << "Test Exist Without Collision" << endl;
	HashTable ht(50);

	int i = 1;

	//insert 1-9
	while (i < 10) {
		ht.insertWithoutCollision(i++);
	}


	ht.insertWithoutCollision(444); //sum of digits is 12
	ht.insertWithoutCollision(555); //sum of digits is 15
	ht.insertWithoutCollision(99); //sum of digits is 18
	ht.insertWithoutCollision(1234567); //sum of digits is 28
	ht.insertWithoutCollision(9994); //sum of digits is 40

	ht.deleteWithoutCollision(2);

	cout << "Your Hashtable" << endl;
	ht.printHashTable();
	cout << endl;

	int test[] = { 1, 2, 5, 31, 444, 1234567, 93294 };

	cout << "Your output " << endl;
	for (int i : test) {
		cout << i << " in HashTable: " << ht.existWithoutCollision(i) << endl; 
	}

	cout << endl;

	cout << "Expected output" << endl;

	cout << "Expected HT after insertion" << endl;
	cout << "0 1 - 1 3 4 5 6 7 8 9 0 0 444 0 0 555 0 0 99 0 0 0 0 ";
	cout << "0 0 0 0 0 1234567 0 0 9994 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0" << endl;

	int expected[] = { 1, 0, 1, 0, 1, 1, 0 };
	for (int i = 0; i < 7; i++) {
		cout << test[i] << " in HashTable: " << expected[i] << endl;
	}

	cout << endl << endl;

}

void testInsertWithCollision_1() {

	cout << "Test Insert With Collision" << endl;

	HashTable ht(50);

	int i = 1;

	//insert 1-9
	while (i < 10) {
		ht.insertWithCollision(i++);
	}

	//insert again (should not do anything since already exist)
	while (i < 10) {
		ht.insertWithCollision(i++);
	}
	ht.insertWithCollision(44); //sum of digits is 8
	ht.insertWithCollision(555); //sum of digits is 15
	ht.insertWithCollision(96); //sum of digits is 15
	ht.insertWithCollision(11); //sum of digits is 2

	cout << "Your output" << endl;
	ht.printHashTable();

	cout << "Expected output" << endl;
	int arr[50];
	for (int i = 0; i < 50; i++) {
		arr[i] = 0;
	}
	for (int i = 1; i < 10; ++i) {
		arr[i] = i;
	}
	arr[10] = 44;
	arr[15] = 555;
	arr[16] = 96;
	arr[11] = 11;

	for (auto i : arr) {
		cout << i << " ";
	}

	cout << endl << endl;
}

void testDeleteWithCollision_1() {

	cout << "Test Delete With Collision" << endl;

	HashTable ht(50);

	int i = 1;

	//insert 1-9
	while (i < 10) {
		ht.insertWithCollision(i++);
	}
	ht.insertWithCollision(44); //sum of digits is 8
	ht.insertWithCollision(555); //sum of digits is 15
	ht.insertWithCollision(96); //sum of digits is 15
	ht.insertWithCollision(11); //sum of digits is 2


	ht.deleteWithCollision(1);
	ht.deleteWithCollision(44);
	ht.deleteWithCollision(555);
	ht.deleteWithCollision(96);
	ht.deleteWithCollision(9876); //item which dont exist

	cout << "Your output" << endl;
	ht.printHashTable();

	cout << "Expected output" << endl;
	int arr[50];
	for (int i = 0; i < 50; i++) {
		arr[i] = 0;
	}
	for (int i = 1; i < 10; ++i) {
		arr[i] = i;
	}
	arr[11] = 11;

	arr[1] = -1;
	arr[10] = -1;
	arr[15] = -1;
	arr[16] = -1;

	for (auto i : arr) {
		cout << i << " ";
	}

	cout << endl << endl;
}

void testExistWithCollision_1() {

	cout << "Test Exist With Collision" << endl;

	HashTable ht(50);

	int i = 1;

	//insert 1-9
	while (i < 10) {
		ht.insertWithCollision(i++);
	}

	ht.insertWithCollision(44); //sum of digits is 8
	ht.insertWithCollision(555); //sum of digits is 15
	ht.insertWithCollision(96); //sum of digits is 15
	ht.insertWithCollision(11); //sum of digits is 2


	ht.deleteWithCollision(1);
	ht.deleteWithCollision(44);
	ht.deleteWithCollision(555);
	ht.deleteWithCollision(96);
	ht.deleteWithCollision(9876); //dont exist in HT

	ht.printHashTable();
	//expected hashtable 
	int arr[50];
	for (int i = 0; i < 50; i++) {
		arr[i] = 0;
	}
	for (int i = 1; i < 10; ++i) {
		arr[i] = i;
	}
	arr[11] = 11;

	arr[1] = -1;
	arr[10] = -1;
	arr[15] = -1;
	arr[16] = -1;



	int test[] = { 1, 2, 5, 10, 11, 12, 14, 44, 9876 };

	cout << "Your output " << endl;
	for (int i : test) {
		cout << i << " in HashTable: " << ht.existWithCollision(i) << endl;
	}

	cout << endl;

	cout << "Expected output" << endl;
	cout << "Expected Hash Table" << endl;
	for (auto i : arr) {
		cout << i << " ";
	}
	cout << endl; 
	int expected[] = { 0, 1, 1, 0 , 1, 0 , 0, 0, 0 };
	for (int i = 0; i < 9; i++) {
		cout << test[i] << " in HashTable: " << expected[i] << endl;
	}

	cout << endl << endl;



}





