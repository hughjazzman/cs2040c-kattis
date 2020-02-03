#include <iostream>
#include <stdio.h>
using namespace std;

#define SIZE 4


// Scan grid
void scanGrid(int arr[][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            cin >> arr[i][j];
        }
    }
}


// Prints grid
void printGrid(int arr[][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

// Transposes grid
void transpose(int arr[][SIZE]) {
    int temp;
    for (int i = 0; i < SIZE; i++) {
        for (int j = i + 1; j < SIZE; j++) {
            temp = arr[i][j];
            arr[i][j] = arr[j][i];
            arr[j][i] = temp;
        }
    }
}

// Reverses left to right grid
void reverseGrid(int arr[][SIZE]) {
    int temp;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE/2; j++) {
            temp = arr[i][j];
            arr[i][j] = arr[i][SIZE-j-1];
            arr[i][SIZE - j - 1] = temp;
        }
    }
}

// Moves zeroes to the right of a row
void moveZero(int row[]) {
    for (int i = 0;  i < SIZE; i++) {
        if (row[i]) continue;

        for (int j = i + 1; j < SIZE; j++) {
            if (!row[j]) continue;
            row[i] = row[j];
            row[j] = 0;
            break;
        }
    }
}

// Merges a single row leftwards
void mergeRow(int row[]) {
    // If 2 merges are happening
    if (row[0] == row[1] && row[2] == row[3]) {
        row[0] *= 2;
        row[1] = 2 * row[2];
        row[2] = 0;
        row[3] = 0;
        return;
    }

    moveZero(row);
    
    // At most 1 merge
    for (int i = 0; i < SIZE - 1; i++) {
        if (row[i] == row[i + 1]) {
            row[i] *= 2;
            for (int j = i + 1; j < SIZE; j++) {
                row[j] = row[j + 1];
            }
            row[SIZE - 1] = 0;
        }
    }
}

void mergeLeft(int arr[][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        mergeRow(arr[i]);
    }
}

void mergeUp(int arr[][SIZE]) {
    transpose(arr);
    mergeLeft(arr);
    transpose(arr);
}

void mergeRight(int arr[][SIZE]) {
    reverseGrid(arr);
    mergeLeft(arr);
    reverseGrid(arr);
}

void mergeDown(int arr[][SIZE]) {
    transpose(arr);
    mergeRight(arr);
    transpose(arr);
}


void moveGrid(int arr[][SIZE], int dir) {
    switch (dir) {
    case 0: mergeLeft(arr); break;
    case 1: mergeUp(arr); break;
    case 2: mergeRight(arr); break;
    case 3: mergeDown(arr); break;
    }
}


int main()
{
    int grid[SIZE][SIZE];
    int dir;
    scanGrid(grid);
    cin >> dir;
    moveGrid(grid, dir);
    printGrid(grid);
}