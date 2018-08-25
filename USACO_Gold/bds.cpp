#include <iostream>
#include <algorithm> 

using namespace std; 

#define REP(i, a, b) \
	for (int i = int(a); i<int(b); i++)
int N, sum;
int arrs[10][10]; 

int main() {
	cin >> N >> sum; 

	REP(i, 0, N){
		arrs[0][i] = i+1; 
	}

	do {
		REP(i, 1 , N){
			REP(j, 0, N-i ){
				arrs[i][j] = arrs[i-1][j]+arrs[i-1][j+1]; 
			}
		}
		if (arrs[N-1][0] == sum){
			REP(i, 0, N){
				cout << arrs[0][i] << " "; 
			}
			return 0; 
		}
	}  while (next_permutation(arrs[0], arrs[0]+N)); 
}