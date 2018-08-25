//Dijkstra Implementation using Prim Method
// O(V^2) SHortest Path Algorithm
// IMPORTANT: INITIALIZE YOUR DISTANCE ARRAY TO INFINITY SOMEHOW IN YOUR PROGRAM!!
#include <iostream> 

using namespace std; 

int mat[2000][2000];
int dist[2000]; 
bool mark[2000]; 
int V, E;  

void dijkstra(int S){
	for (int i = 0; i<V; i++){     // reset dist and mark 
		dist[i] = 1 << 20;   // initialize to huge values
		mark[i] = false; 		//initialize all to unvisited 
	}

	dist[S] = 0; 
	mark[S] = true; 
	int i = S;  // start node
	for (int m = 0; m<V-1; m++){
		int min = 1<< 20; // initalize min as inf 
		for (int j = 0; j<V; j++){
			if (mat[i][j] + dist[i] < dist[j] && !mark[j]){ // +dist[i] is only diff from Prim's
				 // if the path from S to i and i to j is smaller than curr dist in dist[]
				dist[j] = mat[i][j]+dist[i]; // write in neighbors. 
			}
		}
		for (int j = 0; j<V; j++){  		// find the minimum distance and not marked
			if (dist[j] < min && !mark[j]) {
				min = dist[j]; 
				i = j; 
			}
		}
		mark[i] = true; 
	}
}

int main() {
	int P,Q; // starting node
	int B; 
	cin >> V >> E >> B; 
	for (int i = 0; i<V; i++){
		for (int j = 0; j<V; j++){
			mat[i][j] = (1<<20); // intialize arrays to huge values.  
			if (i ==j){
				mat[i][j] = 0; 
			}
		}
	}

	for (int i = 0; i<E; i++){ // receiving input
		int x,y, C; 
		cin >> x >> y >> C;
		if (C < mat[x-1][y-1]){
			mat[x-1][y-1] = C; 
			mat[y-1][x-1] = C; 
		}
	}

	dijkstra(0);  // run dijkstras starting at S=1; 

	for (int i = 0; i<B; i++){
		cin >> P >> Q; 
		cout << dist[P-1]+dist[Q-1] << endl; 
	}	

	return 0; 
}