#include <iostream>
#include <fstream> 
#include <cmath>

using namespace std; 

ofstream fout("nocross.out"); 
ifstream fin("nocross.in"); 

int const maxN = 1010; 
int dp[maxN][maxN]; 
int cross[2][maxN]; 

bool friendly(int i, int j){
	if (abs(cross[0][i] - cross[1][j]) <= 4) return true; 
	else return false; 
}

int main() {
	int N; 
	fin >> N; 	
	for (int i = 1; i<= N; i++){
		fin >> cross[0][i]; 
	}
	for (int i = 1; i<= N; i++){
		fin >> cross[1][i]; 
	}

	for (int i = 1; i<= N; i++){
		for (int j = 1; j<= N; j++){
			if (friendly(i, j)){
				dp[i][j] = 1 + dp[i-1][j-1]; 
			}
			dp[i][j] = max(dp[i][j], max(dp[i-1][j], dp[i][j-1])); 
		}
	}
	fout << dp[N][N] << endl; 
}