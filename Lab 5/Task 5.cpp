#include <iostream>
using namespace std;

void printGrid(int grid[9][9]) {
    for (int i = 0; i < 9; i++) {
        if (i % 3 == 0 && i != 0) {
            cout << "---------------------" << endl; }
        for (int j = 0; j < 9; j++) {
            if (j % 3 == 0 && j != 0) {
                cout << "| "; }
            cout << grid[i][j] << " "; }
        cout << endl; }
}

bool isValid(int grid[9][9], int row, int col, int num) {
    for (int j = 0; j < 9; j++) {
        if (grid[row][j] == num) return false; }
    for (int i = 0; i < 9; i++) {
        if (grid[i][col] == num) return false; }
    int startRow = row - row % 3;
    int startCol = col - col % 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (grid[i + startRow][j + startCol] == num) return false; } }
    return true;
}

bool findEmptyCell(int grid[9][9], int &row, int &col) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (grid[i][j] == 0) {
                row = i;
                col = j;
                return true; } } }
    return false;
}

bool solveSudoku(int grid[9][9]) {
    int row, col;
    if (!findEmptyCell(grid, row, col)) return true;
    for (int num = 1; num <= 9; num++) {
        if (isValid(grid, row, col, num)) {
            grid[row][col] = num;
            if (solveSudoku(grid)) return true;
            grid[row][col] = 0; } }
    return false;
}

int main() {
    int grid[9][9] = {
        {5,3,0,0,7,0,0,0,0},
        {6,0,0,1,9,5,0,0,0},
        {0,9,8,0,0,0,0,6,0},
        {8,0,0,0,6,0,0,0,3},
        {4,0,0,8,0,3,0,0,1},
        {7,0,0,0,2,0,0,0,6},
        {0,6,0,0,0,0,2,8,0},
        {0,0,0,4,1,9,0,0,5},
        {0,0,0,0,8,0,0,7,9} };
    if (solveSudoku(grid)) {
        cout << "Solved Sudoku:\n";
        printGrid(grid); } 
	else {
        cout << "No solution\n"; }
    return 0;
}
