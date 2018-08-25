#include <iostream>

using namespace std; 

const int INF = 1<<20; 
#define REP(i, a, b) \
	for (int i = int(a); i<int(b); i++)

int V, E, F; //F is # of favorite pastures 
int arrs[501]; //for holding the F pastures in 
int graph[501][501]; //graph adj. matrix

int main(){
	cin >> V >> F >> E; 

	REP(i, 0, F){
		cin >> arrs[i]; 
	}

	REP(i, 1, V+1){ //initialize mat to infinity
		REP(j, 1, V+1){
			(i == j) ? graph[i][j] = 0 : graph[i][j] = INF; 
		}
	}

	int x, y, w; 
	REP(i, 0, E){
		cin >> x >> y >> w; 
		graph[x][y] = w; 
		graph[y][x] = w; 
	}

	//Floyd Warshall
	REP(k, 1, V+1){
		REP(i, 1, V+1){
			REP(j, 1, V+1){
				if (graph[i][j] > graph[i][k] + graph[k][j]){
					graph[i][j] = graph[i][k] + graph[k][j]; 
				}
			}
		}
	}

	int min = INF; //minimum dist. 
	int minV; 
	REP(i, 1, V+1){ //scan through all vertices and find if its better
		int sum = 0; 
		REP(j, 0, F){
			sum += graph[i][arrs[j]]; //shortest distance between i and a favorite pasture 
		}
		if (sum < min){
			min = sum; 
			minV = i; 
		}
	}
	cout << minV << endl; 

}