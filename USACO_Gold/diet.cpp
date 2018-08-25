#include <iostream>

using namespace std; 

const int maxH = 45010; 
const int maxN = 510; 

int arrs[maxH][maxN]; 
int weight[maxN]; 

int main() {
	int H, N; 
	cin >> H >> N;
	for (int i = 1; i<= N; i++){
		cin >> weight[i]; 
	}	
	for (int i = 1; i<= N; i++){
		for (int j = 1; j<= H; j++){
			arrs[i][j] = arrs[i-1][j]; 
		}
	}
}