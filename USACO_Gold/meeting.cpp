#include <iostream>
#include <cstring>

using namespace std; 

const int maxN = 110; 
const int maxT = 10010; 
const int INF = 1 << 24; 
int grid[maxN][maxN][2];  //0 is bessie, 1 is elsie
int dp[maxN][maxT][2]; //0 is unvisited, 1 is true, 2 is false  

bool solve(int n, int t, int cow){ //dp[n][t][cow], representts minimum time to be at node n in time T
	if (t < 0) return false; 
	if (n == 1 && t == 0) return true; 
	if (n == 1 && t != 0) return false;  //leave at same time
	if (dp[n][t][cow] > 0) return ( (dp[n][t][cow] == 1) ? true : false); 
	bool mark = false; 
	for (int i = 1; i< n; i++){
		if (solve(i, t-grid[i][n][cow], cow)) mark = true; 
	}
	dp[n][t][cow] = ( mark ? 1 : 2); 
	return mark;  
}

int main() {
	int N, M; 
	cin >> N >> M;
	memset(grid, 63, sizeof(grid));  //for infinity
	for (int i = 1; i<=M; i++){ //input bessie times and elsie times
		int x, y; 
		cin >> x >> y; 
		cin >> grid[x][y][0] >> grid[x][y][1]; 
	}	
	int time = 0; 
	while (true){
		if (solve(N, time, 0) && solve(N, time, 1)) {
			cout << time << endl; 
			return 0; 
		}	
		if (time > 10000){
			cout << "IMPOSSIBLE" << endl; 
			return 0; 
		}
		time++; 
	}
}