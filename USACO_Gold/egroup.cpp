#include <iostream>

using namespace std; 

const int maxN = 30010; 
const int INF = 1 << 30; 
const int maxK = 10; 
int N, K, best; 
int arrs1[maxN]; //store forward 
int arrs2[maxN]; //store reverse 


int solve(int arrs[]){
	int dp[maxN][maxK]; //to store values 
	for (int i = 0; i<= N; i++){
		dp[i][0] = INF;  //so min doesn't screw up (initialization)
	}
	for (int i = 1; i<= N; i++){
		for (int j = 1; j<= K; j++){
			dp[i][j] = dp[i-1][j]+ ((arrs[i] == j) ? 0 : 1); 
			for (int k = 1; k < j; k++){
				dp[i][j] = min(dp[i][j], dp[i-1][j-k] + ((arrs[i] == j) ? 0 : 1)); //either coming from same row, or from previous 
			}
		}
	}
	return min(dp[N][1], min(dp[N][2], dp[N][3])); 
}

int main() {
	cin >> N; 
	K = 3;  //# of ids 
	for (int i = 1; i<= N; i++){
		cin >> arrs1[i]; 
		arrs2[N-i+1] = arrs1[i];  //creates reverse
	}
	best = min(solve(arrs1), solve(arrs2)); 
	cout << best << endl; 
}