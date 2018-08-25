#include <iostream> 

using namespace std; 

int mat[2500][2500];
int dist[2500]; 
int path[2][2500]; // keep the path
bool mark[2500] = {false}; 
int V, E; 
int well[300]; // store well values

int main() {
	cin >> V; 
	for (int i = 0; i<V; i++){
		dist[i] = 1 << 20; 
		cin >> well[i]; 	
	}

	for (int i = 0; i<V; i++){
		for (int j = 0; j<V; j++){
			cin >> mat[i][j]; 
		}
	}

	//Prim's Algorithm
	// i is the starting node on which we start searching for the min tree on; 
	
	dist[0] = 0; 
	mark[0] = true; 
	int cost = 0; 
	int i = 0;  // min vertex counter; 
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

	cout << cost << endl; 

}