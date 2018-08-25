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

const long MOD = 10e8 + 7; 
const int maxR = 101; 
const int maxC = 101; 
int grid[maxR][maxC]; 
long dp[maxR][maxC]; 

int main() {
	int R, C, K;
	cin >> R >> C >> K; 
	REP(i, 0, R){
		REP(j, 0, C){
			cin >> grid[i][j]; 
		}
	}
	dp[0][0] = 1; 
	/** Iterate on all possiblilities for subsquares **/
	REP(r, 0, R-1){
		REP(c, 0, C-1){
			/** Now recurse on the subsquare **/
			REP(i, r+1, R){
				REP(j, c+1, C){
					if (grid[i][j] != grid[r][c]) {
						dp[i][j] += dp[r][c]; 
						dp[i][j] %= MOD; 
					}
				}
			}
		}
	}
	cout << dp[R-1][C-1] << endl; 
}