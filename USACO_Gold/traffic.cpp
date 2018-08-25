#include <iostream>
#include <list> 

using namespace std; 

#define INF 1<<20 
#define REP(i, a, b) \
	for (int i = int(a); i<int(b); i++)

int N,M;
int busy[5000] = {0};
list<int> adjlist[5000]; //adjlists

int main() {
	cin >> N >> M;

	int x,y; 
	REP(i, 0, M){
		cin >> x >> y; 
		y--; 
		x--; 
		adjlist[y].push_back(x); //keep node x going into y
	}

	REP(i, 0, N){
		if (adjlist[i].size() == 0){
			busy[i] = 1; 
		}
		else {
			for (list<int>::iterator it = adjlist[i].begin(); it != adjlist[i].end(); it++){
				busy[i] += busy[*it]; 
			}
		}
	}
	cout << busy[N-2] << endl; 
}