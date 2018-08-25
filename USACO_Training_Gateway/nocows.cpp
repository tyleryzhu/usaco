/**
	ID: tylerzh1
	PROB: nocows 
	LANG: C++11
**/
#include <iostream>
#include <fstream>
#include <cstring>

using namespace std; 

ofstream fout("nocows.out"); 
ifstream fin("nocows.in"); 

const int MOD = 9901; 
const int maxN = 205;  //# of nodes 
const int maxK = 105;  //height of tree 
long long dp[maxK][maxN];    //# of trees with depth k and node # n
long long stree[maxK][maxN]; //# of trees with depth <= k and node # n 

int main() {
	int N, K; 
	fin >> N >> K; 
	dp[1][1] = 1; 
	stree[1][1] = 1; 
	for (int k = 2; k <= K; k++){ //iterate first on height
		for (int n = 1; n <= N; n += 2){ 	
			stree[k][n] = stree[k-1][n]; //add all the possible trees
			stree[k][n] %= MOD; 
			//Then iterate on the # of nodes in each subtree, m 
			for (int m = 1; m <= n - 1; m+=2 ){
				if (m != (n-1-m)){ //multipy by 2
					dp[k][n] += 2*stree[k-2][m]*dp[k-1][n-1-m]; 
					dp[k][n] %= MOD; 
					dp[k][n] += dp[k-1][m]*dp[k-1][n-1-m]; 
					dp[k][n] %= MOD; 
				}
				else {
					dp[k][n] += stree[k-2][m]*dp[k-1][n-1-m]; 
					dp[k][n] %= MOD; 
					dp[k][n] += dp[k-1][m]*stree[k-2][n-1-m]; 
					dp[k][n] += dp[k-1][m]*dp[k-1][n-1-m];  
					dp[k][n] %= MOD; 
				}
//				cout << k << " " << n << " " << m << " " << dp[k][n] << endl; 
			}	
			stree[k][n] += dp[k][n]; 
			stree[k][n] %= MOD; 
		}
		for (int n = 1; n<= N; n+= 2){
//			cout << dp[k][n] << " "; 
		}
//		cout << endl; 
	}	
	fout << dp[K][N] << endl; 
}