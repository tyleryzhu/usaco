#include <iostream>
#include <fstream>
#include <queue>

using namespace std; 

ofstream fout("moocast.out"); 
ifstream fin("moocast.in"); 

#define REP(i, a, b) \
	for (int i = int(a); i < int(b); i++)
const int maxN = 1010; 
int N; 
int arrs[maxN][maxN];  //adjacency matrix of the distances 
int x[maxN]; 
int y[maxN]; //x,y stores coords 

bool check(int X){ //return true if X allows cows to reach all other ones
	queue<int> q; 
	bool mark[maxN] = {false}; 
	q.push(1); //initialize with cow 1 
	int counter = 0; 
	while (!q.empty()){
		int curr = q.front(); 
		q.pop(); 
		counter++; 
//		cout << curr << endl; 
		REP(i, 2, N+1){
			if (!mark[i] && arrs[curr][i] <= X){ //neighbor is unmarked and dist is <= X
//				cout << curr << " " << i << endl; 
				mark[i] = true; 
				q.push(i);
			}
		}
	}
/**	REP(i, 1, N+1){
		if (!mark[i]) return false; 
	}
**/	
	if (counter == N) return true; 
	return false; 
}

int main() {
	fin >> N; 
	REP(i, 1, N+1){
		fin >> x[i] >> y[i]; 
	}
	int low = 0; //for binary searching
	int high = 0; //update w/ max dist; 
	REP(i, 1, N+1){
		REP(j, i, N+1){
			if (i == j) arrs[i][j] = 0; 
			else {
				int dist = (x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]); //store distance 
				if (dist > high) high = dist; //keep max for bs. 
				arrs[i][j] = dist; 
				arrs[j][i] = dist; 
			}
		}
	}
	//Run binary search on the answer; 
	while (low < high){
		int mid = low+ (high - low)/2; 
		if (check(mid)){
			high = mid; 
		}
		else {
			low = mid+1; 
		}
	}

	fout << low << endl; 
	return 0; 
}
	