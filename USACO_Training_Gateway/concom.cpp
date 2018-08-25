/**
	ID: tylerzh1
	PROB: concom 
	LANG: C++11
**/
#include <iostream>
#include <fstream>
#include <algorithm>
#include <cstring> 
#include <queue> 

using namespace std; 

ofstream fout("concom.out"); 
ifstream fin("concom.in"); 

const int INF = 1000000000; 
const int maxC = 105; 
int M; 
int adj[maxC][maxC]; 
int own[maxC][maxC]; 
bool mark[maxC][maxC];  

void control(int node){ //finds all companies node is controlling
	queue<int> q; 
	q.push(node); 
	mark[node][node] = true; 
	while (!q.empty()){ //then keep pushing nodes that it controls in 
		int n = q.front(); q.pop();  //get the first node
		for (int i = 1; i<= 100; i++){ //check its neighbors, add them to own 
			if (adj[n][i] > 0) own[node][i] += adj[n][i]; 
			//Then check if any nodes are > 50; If they are, push them into queue for another roudn of checking
			if (own[node][i] >= 50 && !mark[node][i]) {
				mark[node][i] = true; 
				q.push(i); 
			}
		}
	}
}

int main() {
	fin >> M; 
	for (int i = 0; i<M; i++){
		int x, y, w; 
		fin >> x >> y >> w;  
		adj[x][y] = w; //directed edge
	}		

	for (int i = 1; i<= 100; i++){ //go through every vertex, recurse
		control(i); 
	}
	for (int i = 1; i<= 100; i++){
		for (int j = 1; j<= 100; j++){
			if (mark[i][j] && i != j) fout << i << " " << j << endl; 
		}
	}
}
