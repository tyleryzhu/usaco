#include <iostream>
#include <queue> 

using namespace std; 

int N, M; // #nodes, edges 
int adj[101][101]; // adjacency , will become transitive closure matrix 


int main() {
	cin >> N >> M; 	

	for (int i = 0; i<N; i++){
		for (int j = 0; j<N; j++){
			adj[i][j] = 0; 
		}
	}

	for (int i = 0; i<M; i++){
		int x,y; 
		cin >> x >> y; 
		x--;
		y--; 
		adj[x][y] = 1; 
	}

	//Transitive Matrix Creation
	for (int k= 0; k<N; k++){
		for (int i = 0; i<N; i++){
			if (adj[i][k] == 1){
				for (int j = 0; j<N; j++){
					if (adj[k][j] == 1) adj[i][j] = 1; 
				}
			}
		}
	}

	int counter = 0; 
	for (int i = 0; i<N; i++){
		int temp = 0; 			//counts number of wins/losses
		for (int j = 0; j<N; j++){
			if (i != j){
				if (adj[i][j] == 1) temp++; 
				if (adj[j][i] == 1) temp++; 
			}
		}
		if (temp == (N-1)) counter++; 
	}
	cout << counter << endl; 
}