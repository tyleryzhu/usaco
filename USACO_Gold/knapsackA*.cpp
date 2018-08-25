#include <iostream>

using namespace std; 

int arrs[1010][5010]; 
int vals[1010]; 
int size[1010]; 

int main() {
	int N, C; 
	cin >> N >> C; 
	for (int i = 1; i<=N; i++){
		cin >> size[i] >> vals[i]; 
	}	
	for (int i = 1; i<= N; i++){
		for (int j = 1; j <= C; j++){
			arrs[i][j] = arrs[i-1][j]; 
			if (j >= size[i]) arrs[i][j] = max(arrs[i][j], arrs[i-1][j-size[i]]+vals[i]); 
		}
	}
	cout << arrs[N][C] << endl; 
}