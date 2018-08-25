#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
#include <climits> 

using namespace std; 

typedef long long ll; 
#define REP(i, a, b)  \
	for (int i = int(a); i< int(b); i++)
const int maxV = 1010; 

int arrs[10][10]; 
pair<ll, int> dist[maxV];		// same thing as below 
pair<ll, int> cost[maxV][maxV]; //adjacency matrix w/ cost and flights
bool mark[maxV]; 

int main() {
	ofstream fout("cowroute.out"); 
	ifstream fin("cowroute.in"); 
	int A, B, N; 
	fin>> A >> B >> N; 
	/** Initialize **/
	memset(cost, 0x3F, sizeof(cost)); 
	REP(i, 0, maxV)
		cost[i][i] = make_pair(0,0); 

	REP(m, 0, N){
		ll costF; 
		int numF; 
		fin >> costF >> numF; 
		vector<int> cities(numF); 
		REP(i, 0, numF){
			fin >> cities[i]; 
			REP(j, 0, i){ 			//take minimums 
				cost[cities[j]][cities[i]] = min(cost[cities[j]][cities[i]],
												 make_pair(costF, i-j)); 
			}
		}
	}
	/** Dijkstra's **/ 
	memset(dist, 0x3F, sizeof(dist)); 
	memset(mark, false, sizeof(mark)); 
	dist[A] = make_pair(0,0); 
	REP(i, 0, maxV){
		int u = -1; 
		REP(j, 0, maxV){
			/** Find smallest unmarked vertex **/
			if (mark[j]) continue; 
			if (u == -1 || dist[j] < dist[u])
				u = j; 
		}
		mark[u] = true; 

		/** Relax u **/ 
		REP(j, 0, maxV){
			pair<ll, int> rlx = dist[u]; 
			rlx.first += cost[u][j].first; 
			rlx.second += cost[u][j].second; 
			dist[j] = min(dist[j], rlx); 
		}
	}
	if (dist[B].second  <= maxV ){
		fout << dist[B].first << " " << dist[B].second << endl; 
	}
	else {
		fout << "-1 -1\n"; 
	}

	memset(arrs, 0x3F, sizeof(arrs)); 
	REP(i, 0, 10){
		REP(j, 0, 10){
			cout << arrs[i][j] << " "; 
		}
		cout << endl; 
	}
	cout << endl << INT_MAX; 
	return 0; 
}
