/**
	ID: tylerzh1
	PROB: subset 
	LANG: C++11
**/
#include <iostream>
#include <fstream>
#include <cstring> 

using namespace std; 

ofstream fout("subset.out"); 
ifstream fin("subset.in"); 

int N, maxS; 
long dp[400][40]; //dp[i][j] is the # of subsets of 1..j that sum to i; 

long solve(int sum, int num){ //sum is sum of subsets, num is 1.. num
	if (sum == 1 && num == 1) return 1; 
	if (num == 1 || sum == 0) return 0; 
	if (dp[sum][num] >= 0) return dp[sum][num]; 
	long best = 0; //minimum 
	if (sum - num >= 0){
		best = max(best, solve(sum, num-1)+solve(sum-num, num-1)); 
	}
	else {
		best = max(best, solve(sum, num-1)); 
	}
	dp[sum][num] = best; 
	return best; 
}

int main() {
	fin >> N; 
	if ((N%4 == 1) || (N%4 == 2)) {
		fout << 0 << endl; 
		return 0; 
	}
	maxS = N*(N+1)/4; 
	for (int i = 1; i<= maxS; i++){
		for (int j = 1; j<= N; j++){
			dp[i][j] = -1; 
		}
	}
	fout << solve(maxS, N) << endl; 
}
