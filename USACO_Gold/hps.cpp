#include <iostream>
#include <fstream>
#include <cstring>

using namespace std; 

ofstream fout("hps.out"); 
ifstream fin("hps.in"); 

#define REP(i,a,b) \
	for (int i = int(a); i < int(b); i++) // a to b, i is local as usual 

#define INF 2000000000 // 2 billion 
//If you need to recall how to use memset 
#define MEMSET_INF 127 // about 2 B
#define MEMSET_INF_HALF 63 // about 1 B
//memset(dist, MEMSET_INF, sizeof dist); // useful for shortest path distances
//memset(dp_memo, -1, sizeof dp_memo); // useful to initialize DP memoization table

const int maxN = 100010; 
const int maxK = 23; 
int N; 
int gest[maxN]; 
int dp[maxN][maxK][3]; 


int main() {
	int K; 
	fin >> N >> K; 
	REP(i, 1, N+1){
		char temp; 
		fin >> temp; 
		if (temp == 'P') gest[i] = 0; 
		else if (temp == 'H') gest[i] = 1; 
		else gest[i] = 2;  //creating prefix sums
	}	
	for (int i = 0; i<=K; i++){
		for (int j = 0; j<3; j++){
			dp[0][i][j] = 0;  //base case when N = 0; 
		}
	}

	for (int n = 1; n <= N; n++){
		for (int k = 0; k <= K; k++){
			for (int g = 0; g<3; g++){
				int best = dp[n-1][k][g]; 
				if (gest[n] == g) best++;  //represents if move was good
				if (k > 0){ //then dp on the moves
					best = max(best, max(dp[n-1][k-1][(g+1)%3], dp[n-1][k-1][(g+2)%3])+ ((gest[n] == g) ? 1 : 0)); //check switching a move and if it gains a point
				}
//				cout << n << " " << k << " " << g << " " << best << endl; 
				dp[n][k][g] = best; 
			}
		}
	}

	fout << max(dp[N][K][0],max(dp[N][K][1],dp[N][K][2])) << endl; 
}