#include <iostream>
#include <string> 
#include <cstring> 

using namespace std; 

const int maxL = 1010; 
string s1, s2; 
int dp[maxL][maxL]; 

int main() {
	cin >> s1 >> s2; 
	memset(dp, 63, sizeof(dp)); 
	dp[0][0] = 0; 
	for (int i = 1; i < maxL; i++){
		dp[0][i] = i; 
		dp[i][0] = i; 
	}
	for (int i = 1; i <= s1.size(); i++){
		for (int j = 1; j<= s2.size(); j++){
			if (s1.at(i-1) == s2.at(j-1)) dp[i][j] = dp[i-1][j-1]; 
			dp[i][j] = min(dp[i][j], min(dp[i-1][j-1], min(dp[i][j-1], dp[i-1][j]))+1); 
		}
	}	
	cout << dp[s1.size()][s2.size()] << endl; 
}