#include <iostream>
#include <map> 

using namespace std; 

#define REP(i,a,b) \
	for (int i = int(a); i < int(b); i++) // a to b, i is local as usual 

#define INF 2000000000 // 2 billion 
//If you need to recall how to use memset 
#define MEMSET_INF 127 // about 2 B
#define MEMSET_INF_HALF 63 // about 1 B
//memset(dist, MEMSET_INF, sizeof dist); // useful for shortest path distances
//memset(dp_memo, -1, sizeof dp_memo); // useful to initialize DP memoization table

int const maxN = 10010; 
int const maxD = 1010; 
int const maxM = 510; 
int pref[maxN]; 
int dp[maxN]; 
int N, M; 

int query(int a, int b){ //find sum from [a...b]; 
	return pref[b]-pref[a-1]; 
}

int main() {
	cin >> N >> M; 
	pref[0] = 0; 
	REP(i, 1, N+1){
		cin >> pref[i]; 
		pref[i] += pref[i-1]; 
	}
	REP(i, 1, N+1){  // dp[i] will contain best solution for ending at that point
		REP(m, 1, M+1){ // loop through all possible exhaustions
			if ( i > 2*m )
			dp[i] = max(dp[i], dp[i-2*m] + query(i-2*m, i-m-1)); 
		}
		cout << i << " " << dp[i] << endl; 
	}
	cout << dp[N] << endl; 
}
 
