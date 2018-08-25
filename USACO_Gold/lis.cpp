#include <iostream>

using namespace std; 

int arrs[20010]; 
int dp[20010]; 

int main() {
	int N; 
	cin >> N; 
	for (int i = 1; i<= N; i++){
		cin >> arrs[i]; 	
	}	
	int best = 0; 
	dp[0] = 0; 
	for (int i = 1; i<= N; i++){
		dp[i] = 1; 
		for (int j = 1; j<i; j++){
			if (arrs[j] < arrs[i]){
				dp[i] = max(dp[i], dp[j]+1); 
			}
		}
		best = max(best, dp[i]); 
	} 
	cout << best << endl; 
}