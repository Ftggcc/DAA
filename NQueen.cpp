#include <iostream>

#include <cmath>



using namespace std;



int board[20], solutionCount = 0;



bool isSafe(int row, int col) {

for (int i=1; i < row; i++) {

if (board[i] == col || abs(board[i] - col) == abs(i - row)) {

return false;

}

}

return true;

}



void printSolution(int n) {

solutionCount++;

cout << "\nSolution" << solutionCount <<":\n";

for (int i=1; i <= n; i++) {

for (int j = 1; j <= n; j++) {

cout << (board[i] == j? "Q ": "- ");

}

cout << endl;

}

}



void solveNQueens(int row, int n) {

for (int col=1; col <= n; col++) {

if (isSafe(row, col)) {

board[row] =col;

if (row==n) {

printSolution(n);

} 

else {

solveNQueens (row + 1, n);

}

}

}

}



int main() {

int n;

cout << "Enter the number of Queens: ";

cin >> n;

solveNQueens(1, n);

return 0;



}
