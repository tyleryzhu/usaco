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

int R, C; 
const int maxR = 101; 
const int maxC = 101; 
int dp[maxR][maxC];  //last one to indicate which row u come from

bool in_bounds(int r, int c){
	if (r < 0 || r >= R || c <= 0 || c >= C) return false; 
	return true; 
}

void printarr(){
	REP(i,0,R){
		REP(j,0,C){
			cout << dp[i][j] << " "; 
		}
		cout << endl; 
	}
	cout << endl; 
}

int main() {
	cin >> R >> C;
	REP(i, 0, R){
		REP(j, 0, C){
			cin >> dp[i][j]; 
			if (i > j) dp[i][j] = 0; 
		}
	}

	REP(j, 1, C){
		REP(i, 0, R){
			if (i == 0){
				dp[i][j] += max(dp[i][j-1],dp[i+1][j-1]); 
			}
			else if (i == R-1){
				dp[i][j] += max(dp[i-1][j-1], dp[i][j-1]); 
			}
			else {
				dp[i][j] += max(dp[i-1][j-1], max(dp[i][j-1],dp[i+1][j-1])); 
			}
//			printarr(); 
		}
	}
	cout << dp[R-1][C-1] << endl; 
}