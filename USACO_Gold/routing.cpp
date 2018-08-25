//Dijkstra Implementation using Prim Method and Adjacency Matrix
// O(E+V^2) Shortest Path Algorithm
// IMPORTANT: INITIALIZE YOUR DISTANCE ARRAY TO INFINITY SOMEHOW IN YOUR PROGRAM!!
#include <iostream> 
#include <cstring>

using namespace std; 

typedef long long ll; 
#define REP(i,a,b) \
	for (int i = int(a); i<int(b); i++)
const int maxV = 1001; 
const ll INF = 1 << 30; 
ll mat[maxV][maxV];
ll dist[maxV]; 
bool mark[maxV]; 
int V; 

int A, B, N; 
int cities[maxV]; //for reading in cities
int parent[maxV]; 
int flights[maxV][maxV]; 

ll Dijkstra(int S, int D){   //start, destination
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
				parent[j] = i; 
			}
		}
		ll min = INF; // initalize min as inf 
		int minV; 
		for (int j = 1; j<V+1; j++){  		// find the minimum distance and not marked
			if (dist[j] < min && !mark[j]) {
				min = dist[j]; 
				minV = j; 
			}
		}
		i = minV; 
		mark[i] = true; 
	}	
	return ((D == -1) ? -1 : dist[D]); //returns distance to D
}

int main() {
	cin >> A >> B >> N; 
	V = 1000; 

	for (int i = 1;i<V+1; i++){ 		//initializing matrix 
		for (int j = 1; j<V+1; j++){
			mat[i][j] = INF; 
			if (i == j) mat[i][j] = 0; 
		}
	}

	memset(parent, -1, 1001);  //reconstruct the path 

	ll W, C; //weight of the path, # of cities in the path
	int maxVert = 0; 
	REP(m, 0, N){  //N flights
		cin >> W >> C; 
		REP(i, 0, C){
			cin >> cities[i];  //get the cities in the path. 
			if (cities[i] > maxVert) maxVert= cities[i]; 
		}
		REP(i, 0, C){
			REP(j, i+1, C){
				int x = cities[i]; 
				int y = cities[j]; 
				if (W < mat[x][y]){
					mat[x][y] = W; //if shortest dist then use 
					flights[x][y] = j-i;  //# of individ. flights from x to y
				}
			}
		}
	}

	V = maxVert; 
	/** prints mat
	REP(i, 1, V+1){
		REP(j, 1, V+1){
			cout << mat[i][j] << " "; 
		}
		cout << endl; 
	}
	**/
	ll temp = Dijkstra(A,B); 
	if (temp == -1) {			//if no path
		cout << "-1 -1" << endl; 
		return 0; 
	}
	cout << temp << " "; 
	int counter = 0; 
	while (B != A){
		counter += flights[parent[B]][B];  
		B = parent[B]; 
	}
	cout << counter << endl; 
	return 0; 
}