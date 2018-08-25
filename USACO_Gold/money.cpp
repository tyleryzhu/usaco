#include <iostream>

using namespace std; 

int V, N, val; 
long long dp[10010];  //dp[i] of making coin of up to value i 

int main() {
	cin >> V >> N; 
	dp[0] = 1; 
	for (int i = 1; i<=V; i++) { //iterate through coin values
			cin >> val; 
			for (int j = val; j <= N; j++)
				dp[j] += dp[j-val]; 
	}
	cout << dp[N] << endl; 
}