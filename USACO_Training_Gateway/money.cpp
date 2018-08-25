/**
	ID: tylerzh1
	PROB: money 
	LANG: C++11
**/
/**
#include <iostream>
#include <fstream>
#include <cstring> 

using namespace std; 

ofstream fout("money.out"); 
ifstream fin("money.in"); 

const int maxV = 26; 
const int maxN = 10110; 

int V, N; 
int val[maxV]; 
long long dp[maxN][maxV];  //dp[i][j] = # of ways of making value i with coins up to j

int main() {
	fin >> V >> N; 
	for (int i = 1; i<=V; i++){
		fin >> val[i]; 
	}	
	memset(dp, 0, sizeof(dp)); 

	for (int i = 0; i<= N; i++){ //using no coins, no ways
		dp[i][0] = 0; 
	}
	dp[0][0] = 1; 
	for (int j = 1; j<=V; j++){ //iterate forwards
		for (int i = 0; i<=N; i++) { //iterate through coin values
			dp[i][j] += dp[i][j-1]; 
			if (i >= val[j]) dp[i][j] += dp[i-val[j]][j]; 
		}
	}

	fout << dp[N][V] << endl; 
}
**/
#include <fstream>

using namespace std; 

ofstream fout("money.out"); 
ifstream fin("money.in"); 

int V, N, val; 
long long dp[10010];  //dp[i] of making coin of up to value i 

int main() {
	fin >> V >> N; 
	dp[0] = 1; 
	for (int i = 1; i<=V; i++) { //iterate through coin values
			fin >> val; 
			for (int j = val; j <= N; j++)
				dp[j] += dp[j-val]; 
	}
	fout << dp[N] << endl; 
}