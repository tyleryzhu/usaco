//Dijkstra Implementation using Prim Method and Adjacency Matrix
// O(V^2) Shortest Path Algorithm
// IMPORTANT: INITIALIZE YOUR DISTANCE ARRAY TO INFINITY SOMEHOW IN YOUR PROGRAM!!
#include <iostream> 

using namespace std; 

const int maxV = 2501; 
const int INF = 1 << 20; 
int mat[maxV][maxV];
int dist[maxV]; 
bool mark[maxV]; 
int V, E; 

int Dijkstra(int S, int D){   //start, destination
	for (int i = 1; i< V+1; i++){
		dist[i] = INF; 
		mark[i] = false; 
	}
	dist[S] = 0; 
	mark[S] = true; 
	int i = S;  // current node  
	for (int m = 0; m<V-1; m++){
		if (i == D) break; 
		for (int j = 1; j<V+1; j++){ // relax neighbors of i
			if (mat[i][j] + dist[i] < dist[j] && !mark[j]){ // +dist[i] is only diff from Prim's
				 // if the path from S to i and i to j is smaller than curr dist in dist[]
				dist[j] = mat[i][j]+dist[i]; // write in neighbors. 
			}
		}
		int min = INF; // initalize min as inf 
		for (int j = 1; j<V+1; j++){  		// find the minimum distance and not marked
			if (dist[j] < min && !mark[j]) {
				min = dist[j]; 
				i = j; 
			}
		}
		mark[i] = true; 
	}	
	return ((D == -1) ? -1 : dist[D]); //returns distance to D
}

int main() {
	int S; 
	int D = -1; //destination
	cin >> V >> E >> S; 

	for (int i = 1;i<V+1; i++){
		for (int j = 1; j<V+1; j++){
			mat[i][j] = INF; 
		}
	}

	int x,y, C; 
	for (int i = 0; i<E; i++){ // receiving input
		cin >> x >> y >> C;
		mat[x][y] = C; 
		mat[y][x] = C;  //remove if directed
	}

	Dijkstra(S,D); 	

	for (int i = 1; i<V+1; i++){
		cout << ((dist[i]< INF) ? dist[i] : -1) << endl; 
	}

	return 0; 
}