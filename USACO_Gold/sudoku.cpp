#include <iostream>
#include <fstream>

using namespace std;

int sudoku[9][9];
bool findRow[9][10]; // first is row #, second is the # you want to check
bool findCol[9][10]; // first is col #, second is the # you want to check
bool findSquare[9][10]; // first is square #, second is the # you want to check

/*
 * ****************
 * S1 | S2 | S3
 * S4 | S5 | S6
 * S7 | S8 | S9
 * ****************
 */

bool find_row(int row, int col, int n) { // checks if number is already found in row
	if (findRow[row][n]) return true;
	return false;
}

bool find_col(int row, int col, int n) { // checks if number is already found in col
	if (findCol[col][n]) return true;
	return false;
}

bool find_square(int row, int col, int n){  // checks if number is already found in square
	int sNumss = (row-(row%3))+(col-(col%3))/3 + 1;
	if (findSquare[sNumss][n]) return true;
	return false;
}

void makeMove(int row, int col, int val, int mark){
	int sNums = 0;
	if (mark == 1) { // create val at row,col
		sudoku[row][col] = val;
		findRow[row][sudoku[row][col]] = true;
		findCol[col][sudoku[row][col]] = true;
		sNums = 3*(row/3)+(col/3) + 1;
		findSquare[sNums][sudoku[row][col]] = true;  // fill out the squares
	}
	else {// remove all instances of val
		findRow[row][sudoku[row][col]] = false;
		findCol[col][sudoku[row][col]] = false;
		sNums = 3*(row/3)+(col/3) + 1;
		findSquare[sNums][sudoku[row][col]] = false;
		sudoku[row][col] = 0;
	}
}

bool find_ok(int row, int col, int n){ // returns if n is in any of the rows/col/squares
	return (find_square(row,col,n) || find_col(row,col,n) || find_row(row,col,n));
}

bool solve(int row, int col) {
	if (col > 8) {
		col = 0;
		row++;
	}

	if ( row > 8) return true;
	if (sudoku[row][col] != 0) return solve(row,col+1);
	for (int m = 1; m<10; m++){
		if (!(find_ok(row, col, m))){
			makeMove(row,col,m,1);
			//print_sudoku();
			if (solve(row,col+1)) return true;
			makeMove(row,col,m,0);
			//print_sudoku();
		}
	}
	return false;
}

int main() {
	ofstream fout("sudoku.out"); 
	ifstream fin("sudoku.in"); 
	for (int i = 0; i<9; i++){
		for (int j = 0; j<10; j++){
			findRow[i][j] = false;
			findCol[i][j] = false;
			findSquare[i][j] = false;
		}
	}

	int sNum = 0;
	for (int i = 0; i<9; i++){
		for (int j= 0; j<9; j++){
			fin >> sudoku[i][j];
			if (sudoku[i][j] != 0){
			findRow[i][sudoku[i][j]] = true;
			findCol[j][sudoku[i][j]] = true;
			sNum = 3*(i/3)+(j/3) + 1;
			findSquare[sNum][sudoku[i][j]] = true;  // fill out the squares
			}
		}
	}
	if (solve(0,0)) {
	for (int i = 0; i<9; i++){
		for (int j = 0; j<9; j++){
			fout << sudoku[i][j] << " ";
		}
		fout << endl;
	}
	}
	else {
		fout << "NO SOLUTION" << endl;
	}
}

