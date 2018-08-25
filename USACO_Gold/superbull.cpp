//Prim's Application

#include <iostream> 

using namespace std; 

int mat[2000][2000];
int temp[2000]; //store vals in 
long dist[2000]; 
bool mark[2000] = {false}; 
int V, E; 

int main() {
	cin >> V; 
	for (int i = 0; i<V; i++){
		dist[i] = (1 << 20); 
	}

	for (int i = 0; i<V; i++){
		cin >> temp[i]; 
	}

	for (int i = 0; i<V; i++){ // receiving input
		for (int j = i; j<V; j++){
			mat[i][j] = -(temp[i] ^ temp[j]); 
			mat[j][i] = -(temp[i] ^ temp[j]);
		} 
	}

	dist[0] = 0; 
	mark[0] = true; 
	long long cost = 0; 
	int i = 0;  // min vertex counter; 
	//Prim's Algorithm
	for (int m = 0; m<V-1; m++){
		int min = 1<< 20; // initalize min as inf 
		for (int j = 0; j<V; j++){
			if (mat[i][j] < dist[j] && !mark[j]){   // if the dist from i to j is smaller than curr dist in dist[]
				dist[j] = mat[i][j]; // write in neighbors. 
			}
		}
		for (int j = 0; j<V; j++){  		// find the minimum distance and not marked
			if (dist[j] < min && !mark[j]) {
				min = dist[j]; 
				i = j; 
			}
		}
		mark[i] = true; 
		cost += dist[i]; 
	}

	cout << -1*cost << endl; 

}
