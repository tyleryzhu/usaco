// Returns # of ways to place n queens on an NxN board

#include <iostream>

using namespace std; 

const int maxQ = 30; 
int N; 
int ct = 0; 
int c[maxQ];  //keep column places of the queens 

bool legal(int row, int col){ //checks if row is a legal move so far; obviously at there are row queens already placed 
	for (int i = 0; i<row; i++){
		/** First check vertical **/ 
		if (col == c[i]) return false; 
		/** Then check diagonal **/ 
		int xdif = row - i; 
		int ydif = col - c[i]; 
		if ((xdif == ydif) || (xdif == -1*ydif)) return false; 
	}
	return true; 
}

void dfs(int row){ //dfs based on the row #
	if (row == N){
		ct++; 
		return; 
	}
	for (int i = 0; i<N; i++){ //iterate based on column, see if marked
		if (legal(row, i)){
			c[row] = i; 
			dfs(row+1); 
		}
	}
}

int main() {
	cin >> N; 	
	dfs(0); 
	cout << ct << endl; 
}