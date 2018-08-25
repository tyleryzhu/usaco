/*
 // list implementation, unfinished 
#include <iostream>
#include <queue>
#include <list>

using namespace std; 

int N, M; //node, vertices 
list<int> adjlist[20000]; 
bool mark[20000]; 
queue<int> q; 
queue<int> dist; 
int counter;  // count how many vertices of a specific dist there are
int currNode; 

int bfs(int start){ // returns max dist
	q.push(start); 
	dist.push(0); 
	mark[0] = true; 
	int currDist = 0;  // current max dist
	currNode = 0; //current min Node 

	while (!q.empty()){
		int node = q.front(); 
		int tempDist = dist.front(); 
		q.pop(); 
		dist.pop(); 

		if (currDist != tempDist){
			currDist = tempDist; //update currDist, reset counter and node
			counter = 1; 
			currNode = node; 
		}
		else {				// same dist update
			counter++; 
			if (node < currNode) currNode = node; 
		}

		for (int i = 0; i< adjlist[node].size(); i++){ // iterate through the neighbors of node
			if (!mark[adjlist[node][i]]){  // if a neighbor is not marked
				q.push(adjlist[node][i]); //push in the neigbor
				dist.push(tempDist+1);    // push its dist + 1
				mark[adjlist[node][i]] = true; 
			}
		}
	}
	return currDist; 
}

int main() {
	cin >> N >> M; 
	counter = 1; 
	for (int i = 0; i<N; i++){
		mark[i] = false; 
	}

	for (int i = 0; i<M; i++){
		int x, y;
		cin >> x >> y; 
		x--; 
		y--; 
		adjlist[x].push_back(y); 
		adjlist[y].push_back(x); 
	}

	int maxDist = bfs(0); 
	cout << currNode+1 << " " << maxDist << " " << counter << endl; 
	return 0; 
}
*/

#include <iostream>
#include <queue>
#include <vector> 

using namespace std; 

int N, M; //node, vertices 

vector<int> adjlist[20000];  // adjacency list
bool mark[20000]; 
queue<int> q; 
queue<int> dist; 
int counter;  // count how many vertices of a specific dist there are
int currNode; 

int bfs(int start){ // returns max dist
	q.push(start); 
	dist.push(0); 
	mark[0] = true; 
	int currDist = 0;  // current max dist
	currNode = 0; //current min Node 

	while (!q.empty()){
		int node = q.front(); 
		int tempDist = dist.front(); 
		q.pop(); 
		dist.pop(); 

		if (currDist != tempDist){
			currDist = tempDist; //update currDist, reset counter and node
			counter = 1; 
			currNode = node; 
		}
		else {				// same dist update
			counter++; 
			if (node < currNode) currNode = node; 
		}

		for (int i = 0; i< adjlist[node].size(); i++){ // iterate through the neighbors of node
			if (!mark[adjlist[node][i]]){  // if a neighbor is not marked
				q.push(adjlist[node][i]); //push in the neigbor
				dist.push(tempDist+1);    // push its dist + 1
				mark[adjlist[node][i]] = true; 
			}
		}
	}
	return currDist; 
}

int main() {
	cin >> N >> M; 
	counter = 1; 
	for (int i = 0; i<N; i++){
		mark[i] = false; 
	}

	for (int i = 0; i<M; i++){
		int x, y;
		cin >> x >> y; 
		x--; 
		y--; 
		adjlist[x].push_back(y); 
		adjlist[y].push_back(x); 
	}

	int maxDist = bfs(0); 
	cout << currNode+1 << " " << maxDist << " " << counter << endl; 
	return 0; 
}
