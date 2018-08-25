#include <iostream>
#include <cstring> 

using namespace std; 

#define REP(i, a, b) \
	for (int i = int(a); i < int(b); i++)
const int maxV = 1010; 
int arrs1[maxV][maxV]; //adj mat for one direction
int dist1[maxV]; 
bool mark1[maxV]; 
int arrs2[maxV][maxV]; 
int dist2[maxV]; 
bool mark2[maxV]; 

int main() {
	int V, E, S; 
	cin >> V >> E >> S; 

	int a, b, w; 

	/** Initialize Adjacency Matrices**/
	memset(arrs1, 0x3F, sizeof(arrs1)); 
	memset(arrs2, 0x3F, sizeof(arrs2)); 
	REP(i, 0 , V){
		arrs1[i][i] = 0; 
		arrs2[i][i] = 0; 
	}
	REP(i, 0, E){
		cin >> a >> b >> w; 
		arrs1[a][b] = min(arrs1[a][b], w); 
		arrs2[b][a] = min(arrs2[b][a], w); //keep reversed edges for backwards dijkstras 
	}	

	/**Dijkstra (normal)**/ 
	memset(dist1, 0x3F, sizeof(dist1)); 
	memset(mark1, false, sizeof(mark1)); 
	dist1[S] = 0; 
	REP(i, 0, V){
		/** Find minimum unmarked vertex **/
		int u = -1; 
		REP(j, 1, V+1){
			if (mark1[j]) continue; 
			else if (u == -1 || dist1[j] < dist1[u]){
				u = j; 
			}
		}
		mark1[u] = true; 

		/** Relax u **/
		REP(j, 1, V+1){
			dist1[j] = min(dist1[j], dist1[u]+arrs1[u][j]); 
		}
	}

	/**Dijkstra (reversed)**/ 
	memset(dist2, 0x3F, sizeof(dist2)); 
	memset(mark2, false, sizeof(mark2)); 
	dist2[S] = 0; 
	REP(i, 0, V){
		/** Find minimum unmarked vertex **/
		int u = -1; 
		REP(j, 1, V+1){
			if (mark2[j]) continue; 
			else if (u == -1 || dist2[j] < dist2[u]){
				u = j; 
			}
		}
		mark2[u] = true; 

		/** Relax u **/
		REP(j, 1, V+1){
			dist2[j] = min(dist2[j], dist2[u]+arrs2[u][j]); 
		}
	}

	int max = 0; 
	REP(i, 1, V+1){
		if (i != S){
			if (dist1[i]+dist2[i] > max) max = dist1[i]+dist2[i]; 
		}
	}	

	cout << max << endl; 
	return 0; 
}
	