#include <iostream>

using namespace std; 

#define REP(i,a,b) \
	for (int i = int(a); i < int(b); i++) // a to b, i is local as usual 

#define INF 2000000000 // 2 billion 
//If you need to recall how to use memset 
#define MEMSET_INF 127 // about 2 B
#define MEMSET_INF_HALF 63 // about 1 B
//memset(dist, MEMSET_INF, sizeof dist); // useful for shortest path distances
//memset(dp_memo, -1, sizeof dp_memo); // useful to initialize DP memoization table

const int maxN = 100010; 
int N; 
int arrs[maxN]; 

int main() {
	cin >> N;
	REP(i, 0, N){
		cin >> arrs[i]; 
	}	
	int best = -INF; 
	int curr = 0; 
	REP(i, 0, N){
		curr += arrs[i]; 
		if (curr > best) best = curr; 
		if (curr < 0) curr = 0; 	
	}
	cout << best << endl; 
}