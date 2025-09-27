#include <iostream>
#include <cmath>
using namespace std;

void printSolution(int board[], int n);  

bool isSafe(int board[], int row, int col) {
    for (int i = 0; i < row; i++) {
        if (board[i] == col || abs(board[i] - col) == abs(i - row)) {
            return false;
        }
    }
    return true;
}

void solveNQueens(int board[], int n, int row, int &solutions) {
    if (row == n) {
        solutions++;
        cout << "Solution " << solutions << ":" << endl;
        printSolution(board, n);
        return;
    }

    for (int col = 0; col < n; col++) {
        if (isSafe(board, row, col)) {
            board[row] = col;
            solveNQueens(board, n, row + 1, solutions);
            board[row] = -1;
        }
    }
}

void printSolution(int board[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i] == j) {
                cout << "Q "; } 
			else {
                cout << ". "; } }
        cout << endl; }
    cout << endl;
}

int main() {
    int n;
    cout << "Enter value of N: ";
    cin >> n;
    int* board = new int[n];
    for (int i = 0; i < n; i++) {
        board[i] = -1; }
    int solutions = 0;
    solveNQueens(board, n, 0, solutions);
    if (solutions == 0) {
        cout << "No solutions exist for N = " << n << endl; } 
    else {
        cout << "Total solutions: " << solutions << endl; }
    delete[] board;
    return 0;
}
