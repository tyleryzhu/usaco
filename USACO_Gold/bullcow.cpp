#include <iostream>

using namespace std; 

const int MOD = 5000011; 
int arrs[100010]; 

int main() {
	int N, K; 
	cin >> N >> K; 
	arrs[0] = 1; 
	for (int i = 1; i<= N; i++){
		arrs[i] = arrs[i-1]; 
		if (i > K+1) arrs[i] = (arrs[i]+arrs[i-K-1])%MOD; 
		else arrs[i] = (arrs[i]+1)%MOD; 
	}
	cout << arrs[N] << endl; 
}