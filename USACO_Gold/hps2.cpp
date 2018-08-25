#include <iostream>
#include <fstream>
#include <cstring>

using namespace std; 

ofstream fout("hps.out"); 
ifstream fin("hps.in"); 

#define REP(i,a,b) \
	for (int i = int(a); i <= int(b); i++) // a to b, i is local as usual 

#define INF 2000000000 // 2 billion 
//If you need to recall how to use memset 
#define MEMSET_INF 127 // about 2 B
#define MEMSET_INF_HALF 63 // about 1 B
//memset(dist, MEMSET_INF, sizeof dist); // useful for shortest path distances
//memset(dp_memo, -1, sizeof dp_memo); // useful to initialize DP memoization table

typedef long long ll; 
const int maxN = 100010; 
const int maxK = 23; 
int N; 
ll h[maxN]; 
ll p[maxN]; 
ll s[maxN]; 
long long dp[maxN][maxK]; 

long long win(int start, int end){ //returns optimal # of games that can be won using one move from games start to end
	long long best = 0; 
	best = max(h[end]-h[start-1], max(p[end]-p[start-1], s[end]-s[start-1])); 
	return best; 
}

ll solve(int n, int k){
	if (n <= k) return n; 
	if (n == 1) return 1; 
	if (k == 0 || n == 0) return (win(1, n)); 
	if (dp[n][k] > -1) return dp[n][k];
	ll best = k; 
	REP(i, 1, n){
		best = max(best, solve(i, k-1)+win(i+1, n)); 
	}
	dp[n][k] = best;
	return best; 
}

int main() {
	int K; 
	fin >> N >> K; 
	h[0] = 0; 
	p[0] = 0; 
	s[0] = 0; 
	REP(i, 1, N+1){
		h[i] = h[i-1]; 
		p[i] = p[i-1];
		s[i] = s[i-1]; 
		char temp; 
		fin >> temp; 
		if (temp == 'P') p[i]++; 
		else if (temp == 'H') h[i]++; 
		else s[i]++;  //creating prefix sums
	}	
	memset(dp, -1, sizeof(dp)); 
	fout << solve(N,K) << endl; 
}