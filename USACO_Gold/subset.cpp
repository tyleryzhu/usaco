#include <iostream>

using namespace std; 

long dp[1010]; 

int main() {
	int N; 
	cin >> N; 
	if (( N % 4 == 2) || (N % 4 == 1)){ 
		cout << 0 << endl; 
		return 0; 
	}
	dp[0] = 1; 
	int tot = N*(N+1)/2; 
	for (int i = 1; i<= N; i++){
		for (int j = tot-i; j >= 0; j--){
			if (dp[j] > 0){
				dp[j+i] += dp[j]; 
			}
		}
	}
	cout << dp[tot/2]/2 << endl; 
}