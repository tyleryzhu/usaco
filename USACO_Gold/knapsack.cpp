//unbounded knapsack implementation
/**
#include <iostream>

using namespace std; 

const int INF = 2010; 
int V[INF]; 
int W[INF]; 
int memo[INF]; 
int S, N;

int Knapsack(int C){
	if (memo[C] > -1) return memo[C]; 
	for (int i = 0; i< N; i++){
		if (W[i] <= C){
			memo[C] = max(memo[C], Knapsack(C-W[i])+V[i]); 
		}
	}
	return memo[C]; 
} 

int main() {
	cin >> S >> N;

	for (int i = 0; i<N; i++){
		cin >> W[i] >> V[i]; 
	}
	for (int i = 1; i<S+1; i++){
		memo[i] = -1; 
	}
	memo[0] = 0; 
	cout << Knapsack(S) << endl; 
}
**/

//0-1 knapsack Top-Down 
/**
#include <iostream>

using namespace std; 

const int MAXN = 2000; 
const int MAXC = 2000; 
int memo[MAXN][MAXC]; 
int V[MAXN]; 
int W[MAXN]; 
int S, N; 

int Knapsack(int i, int w){
	if (memo[i][w] > -1) return memo[i][w]; 
	if (W[i] > w) memo[i][w] = Knapsack(i-1, w); // ith item can't fit
	else memo[i][w] = max(Knapsack(i-1,w),Knapsack(i-1,w-W[i])+V[i]); 
	return memo[i][w]; 
}

int main() {
	cin >> S >> N; 
	for (int i = 1; i<N+1; i++){
		cin >> W[i] >> V[i]; 
	}

	for (int i = 0; i<N+1; i++){
		for (int j = 0; j<S+1; j++){
			memo[i][j] = -1; 
			if (i == 0) memo[i][j] = 0; 
		}
	}

	cout << Knapsack(N,S) << endl; 
}
**/

//0-1 Knapsack Bottoms Up
#include <iostream>

using namespace std; 

const int MAXN = 2000; 
const int MAXC = 2000; 
int memo[MAXN][MAXC]; 
int V[MAXN]; 
int W[MAXN]; 
int S, N; 

int main() {
	cin >> S >> N; 
	for (int i = 1; i<N+1; i++){
		cin >> W[i] >> V[i]; 
	}

	for (int i = 0; i<S+1; i++){
		memo[0][i] = 0; 
	}

	for (int i = 1; i<N+1; i++){
		for (int j = 0; j < S+1; j++){
			if (j == 0) memo[i][j] = 0; 
			else if (W[i] > j) memo[i][j] = memo[i-1][j]; 
			else memo[i][j] = max(memo[i-1][j], memo[i-1][j-W[i]]+V[i]); 
		}	
	}
	cout << memo[N][S] << endl; 
}
