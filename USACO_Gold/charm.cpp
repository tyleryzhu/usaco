#include <iostream>

using namespace std; 

const int maxN = 3500; 
const int maxM = 13000; 
int dp[maxM];  //for saving values 
int d[maxN]; // list of charm desirability reatings 
int w[maxN]; //list of weights

int main() {
	int N, M; 
	cin >> N >> M; 
	for (int i = 1; i<= N; i++){
		cin >> w[i] >> d[i]; 
	}		
	for (int i = 1; i<= N; i++){ //iterating through all of the chamrs
		for (int j = M-w[i]; j >= 0; j--){
			dp[j+w[i]] = max(dp[j+w[i]], dp[j] + d[i]);
		}
		for (int i = 0; i<= N; i++){
			cout << dp[i] << " "; 
		}
		cout << endl; 
	}
	cout << dp[M] << endl; 
}