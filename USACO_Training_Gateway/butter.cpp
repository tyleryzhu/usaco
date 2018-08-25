/**
	ID: tylerzh1
	PROB: butter
	LANG: C++14
**/

#include <iostream>
#include <queue>
#include <vector>
#include <fstream>
#include <climits> 

using namespace std;

ofstream fout("butter.out"); 
ifstream fin("butter.in"); 

const int INF = INT_MAX; 
int cows[505]; 

typedef pair<int, int> ii; 
typedef vector<ii> vii; 
#define REP(i,a,b) \
	for (int i = int(a); i<int(b); i++)

const int MaxV = 1000; 
const int maxC = 1000; 

int N, P, C; 
vii graph[MaxV]; 
int dist[maxC][MaxV]; 
bool mark[MaxV]; 

class prioritize{public: bool operator ()(pair<int, int>&p1 ,pair<int, int>&p2){return p1.second>p2.second;}};

int Dijkstra(int S, int D){ //destination for stopping early  (pass -1 to go on for all)
	REP(i, 1, P+1){ 		//initializing dist to inf
		dist[S][i] = INF; 
		mark[i] = false; 
	}
	priority_queue<ii, vii, prioritize> pq; //priority queue of the node #s
	pq.push(make_pair(S,dist[S][S]=0)); // push in first vertex w/ edge of weight 0 
	while (!pq.empty()){
		int k = pq.top().first;  //min node
		pq.pop(); 
		if (mark[k]) continue;  
		mark[k] = true; 
		if (k == D) break; 

		REP(j, 0, graph[k].size()){
			int a = graph[k][j].first; //node of the neighbor of k; 
			int b = graph[k][j].second;  // weight of the edge to a
			if (!mark[a] && dist[S][a]> b+dist[S][k]) 	 // if distance is greater than edge
				pq.push(make_pair(a, dist[S][a] = b+dist[S][k])); 			//pushin the edge and update dist[a]
		}
	}
	return (D == -1 || dist[S][D] == INF) ? -1 : dist[S][D]; 
}

int main() {
    fin >> N >> P >> C; 
    for (int i = 0; i < N; i++){
        fin >> cows[i]; 
    }
    int x,y, c; 
    for (int i = 0; i < C; i++){
        fin >> x >> y >> c; 
        graph[x].push_back(make_pair(y,c)); 
        graph[y].push_back(make_pair(x,c)); 
    }

    for (int i = 0; i < N; i++){
        Dijkstra(cows[i],-1); 
    }

    int best = INF; 
    for (int i = 1; i <= P; i++){
        int tot = 0; 
        for (int j = 0; j < N; j++){
            tot += dist[cows[j]][i]; 
        }
        best = min(best, tot); 
    }
    fout << best << endl; 
}
