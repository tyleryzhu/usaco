#include <iostream>

using namespace std; 

int N, M; 
int mat[100][100]; 
int dest[10000]; // keep the island dests in here

int main() {
	cin >> N >> M;  // #nodes, # edges

	for (int i = 0; i<M; i++){ //read in dest
		cin >> dest[i]; 
		dest[i]--; 
	}

	for (int i = 0; i<N; i++){
		for (int j = 0; j<N; j++){
			cin >> mat[i][j];     // initialize entries as infinity
		}
	}

	for (int k = 0; k < N; k++){		//Floyd-Warshall
		for (int i = 0; i < N; i++){
			for (int j = 0; j<N; j++){
				if (mat[i][j] > mat[i][k] + mat[k][j]){
					mat[i][j] = mat[i][k] + mat[k][j]; 
				}
			}
		}
	}

	int tot = 0; 
	for (int i = 0; i<M-1; i++){
		tot += mat[dest[i]][dest[i+1]]; 
	}
	cout << tot << endl; 
}