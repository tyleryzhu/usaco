/**
	ID: tylerzh1
	PROB: agrinet
	LANG: C++11
**/

#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

ofstream fout("agrinet.out"); 
ifstream fin("agrinet.in"); 

const int INF = 1<<20; 

int arrs[100][100];
int dist[100] = {INF}; 
bool visit[100] = {false}; 
int N, E; 

int prim() {
    fill(dist, dist+100, INF);  
    fill(visit, visit+100, false); 
    
    dist[0] = 0; 
    visit[0] = true; 

    int cost = 0, curV = 0; 
    for (int m = 0; m < N-1; m++){
        int min = INF; 
        // Update Distances From current set 
        for (int j = 0; j < N; j++){
            if (arrs[curV][j] < dist[j] && !visit[j]) 
                dist[j] = arrs[curV][j]; 
        }
        // Then find the minimum vertex 
        for (int j = 0; j < N; j++) {
            if (dist[j] < min && !visit[j]) {
                min = dist[j]; 
                curV = j; 
            }
        }
        visit[curV] = true; 
        cost += dist[curV]; 
    }
    return cost; 
}

int main() {
    fin >> N; 
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            fin >> arrs[i][j]; 
        }
    }

   fout << prim() << endl; 

}
