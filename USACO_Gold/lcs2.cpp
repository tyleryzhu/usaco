#include <iostream> 
#include <string> 

using namespace std; 

const int maxN = 10010; 
int dp[maxN][2]; //for keeping in 1-D 

int main() {
	string s1, s2; 
	getline(cin, s1); 
	getline(cin, s2); 
	if (s2.size() == 0){
		cout << s1.size() << endl; 
		return 0; 
	}
	for (int j = 1; j <= s2.size(); j++){
		int curr, old; 
		if (j % 2 == 0) {
			curr = 0; 
			old = 1; 
		}
		else {
			curr = 1; 
			old = 0; 
		}
		for (int i = 1; i <= s1.size(); i++){
			dp[i][curr] = max(dp[i-1][curr], dp[i][old]); 
			if (s1.at(i-1) == s2.at(j-1)) dp[i][curr] = max(dp[i][curr], dp[i-1][old] + 1); 
		}
	}
	cout << dp[s1.size()][s2.size()%2] << endl; 
} 