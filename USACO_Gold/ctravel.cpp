#include <iostream>
#include <string> 

using namespace std; 

const int maxN = 110; 
const int maxM = 110; 
const int maxT = 20; 
int N, M, T, r1, c1, r2, c2; 
bool grid[maxN][maxM];  //true if visitable, false else 
long long dp[maxN][maxM][maxT]; // keeps the # of paths to (n, m) in T steps 
int dx[4] = {-1,1,0,0}; 
int dy[4] = {0,0,-1,1}; 

bool legal(int i, int j){
	if (i < 1 || i > N || j < 1 || j > M) return false; 
	else return grid[i][j];  
}

int main() {
	cin >> N >> M >> T;
	for (int i = 1; i<= N; i++){
		string temp; 
		cin >> temp; 
		for (int j = 1; j<= M; j++){
			grid[i][j] = (temp.at(j-1) == '.') ? true : false; 
		}
	}	
	cin >> r1 >> c1 >> r2 >> c2; 
	dp[r1][c1][0] = 1; 
	for (int time = 1; time <= T; time++){
		for (int i = 1; i<= N; i++){
			for (int j = 1; j<= M; j++){
				for (int m = 0; m<4; m++){
					int nx = i + dx[m]; 
					int ny = j + dy[m]; 
					if (legal(nx,ny)){
						dp[i][j][time] += dp[nx][ny][time-1]; 
					}
				}
			}
		}
	}
	cout << dp[r2][c2][T] << endl; ; 
}