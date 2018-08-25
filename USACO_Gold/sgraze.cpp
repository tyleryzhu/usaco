#include <iostream>
#include <algorithm>

using namespace std; 

const int maxN = 50010;  
pair<int, int> range[maxN]; 
int dp[maxN]; 
int ending[maxN]; 

int N; 

int main() {
	cin >> N; 
	for (int i = 0; i<N; i++){
		int s, e; 
		cin >> s >> e; 
		range[i] = make_pair(e, s); 
		ending[i] = -e; //for sorting based on negs to get right index
	} 
	sort(range, range+N);
	sort(ending, ending+N); 
	dp[0] = 1; 
	for (int i = 1; i<N; i++){
		dp[i] = dp[i-1]; 
		int best = N-1-(lower_bound(ending+(N-i), ending+N, -range[i].second) - ending); //look for first cow with ending before start
		if (dp[best] + 1 > dp[i]) dp[i]++; 
	}
	cout << dp[N-1] << endl; 
}