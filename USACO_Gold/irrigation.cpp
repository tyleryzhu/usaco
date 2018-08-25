#include <iostream> 

using namespace std; 

int gridx[2000]; 
int gridy[2000]; 
int mat[2000][2000];
int dist[2000]; 
int path[2][2000]; // keep the path
bool mark[2000] = {false}; 
int V, C;  // # of vertices, cost

int dist_euc(int a, int b){ // returns euc. dist of two points
	return ((gridx[a]-gridx[b])*(gridx[a]-gridx[b])+(gridy[a]-gridy[b])*(gridy[a]-gridy[b])); 
}

int main() {
	cin >> V >> C; 

	for (int i = 0; i<V; i++){ //  receive in the points
		int x,y; 
		cin >> x >> y;
		gridx[i] = x; 
		gridy[i] = y; 

	}

	for (int i = 0; i<V; i++){
		dist[i] = 1 << 24; 
		for (int j = i; j<V; j++){
			if ( i == j){
				mat[i][j] = 0; 
				mat[j][i] = 0; 
			}
			else {
				int distance = dist_euc(i,j);   // find distances of all points 
				if (distance < C) distance = (1 << 25); 
				mat[i][j] = distance; 
				mat[j][i] = distance; 
			}
		}
	}

	// good up to here

	dist[0] = 0; 
	mark[0] = true; 
	int cost = 0; 
	int i = 0;  // min vertex counter; 
	for (int m = 0; m<V-1; m++){
		int minVert = i; 
		int min = 1<< 24; // initalize min as inf 
		for (int j = 0; j<V; j++){
			if (mat[i][j] < dist[j] && !mark[j]){   // if the dist from i to j is smaller than curr dist in dist[] and unmarked
				dist[j] = mat[i][j]; // write in neighbors. 
			}
		}
		for (int j = 0; j<V; j++){  		// find the minimum distance and not marked
			if (dist[j] < min && !mark[j]) {
				min = dist[j]; 
				minVert = j; 
			}
		}
		if (minVert == i){
			cout << -1  << endl; 
			return 0; 
		}
		i = minVert; 
		mark[i] = true; 
	}

	for (int i = 0; i<V; i++){
		cost += dist[i]; 
	}
	cout << cost << endl; 

}