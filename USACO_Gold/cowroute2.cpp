#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>

using namespace std;

#define REP(i, a, b) \
	for (int i = int(a); i<int(b); i++)

const int maxV = 1010; 

bool mark[maxV]; 
pair<long long, int> dist[maxV];		// same as below 
pair<long long, int> cost[maxV][maxV]; //contains cost in first, flights in second

int main() {
	ofstream fout("cowroute.out"); 
	ifstream fin("cowroute.in"); 
	int A,B, N;
	fin >> A >> B >> N;

	/** Initialize Matrix to infinity**/
	memset(cost, 0x3F, sizeof(cost)); 
	REP(i, 0, maxV)
		cost[i][i] = make_pair(0,0); //init zeroes

	/** Receive Input of Flight Details**/
	REP(m, 0, N){
		long long costF;
		int numF; 
		fin >> costF >> numF; 
		vector<int> cities(numF); 
		REP(i, 0, numF){
			fin >> cities[i]; 
			REP(j, 0, i){ 		
				cost[cities[j]][cities[i]] = min(cost[cities[j]][cities[i]],
												 make_pair(costF, i-j)); 
			}
		}
	}

	/** Begin Dijkstra's **/
	memset(dist, 0x3F, sizeof(dist)); 
	memset(mark, false, sizeof(mark)); 
	dist[A] = make_pair(0,0); 

	REP(i, 0, maxV){
		// Minimum unvisited vertex
		int u = -1; 
		REP(j, 0, maxV){
			if (mark[j]) continue; 
			else if (u == -1 || dist[j] < dist[u]){
				u = j; 	
			}
		}
		mark[u] = true; 
		/** Relax u **/
		REP(j, 0, maxV){
			pair<long long, int> rlx = dist[u]; 
			rlx.first += cost[u][j].first; 
			rlx.second += cost[u][j].second; 
			dist[j] = min(dist[j], rlx); 
		}
	}

	if (dist[B].second <= maxV){
		fout << dist[B].first << " " << dist[B].second << endl; 
	}
	else {
		fout << "-1 -1" << endl; 
	}

	return 0; 
}