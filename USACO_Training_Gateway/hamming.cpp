/**
	ID: tylerzh1
	PROB: hamming
	LANG: C++11 
**/ 
#include <fstream>
#include <iostream>

using namespace std; 

ofstream fout("hamming.out"); 
ifstream fin("hamming.in"); 

int N, B, D; 
int maxN; 
int arrs[64]; 
bool bigHam[500][500]; 

int ham(int a, int b){ // returns Hamming distance of a and b
	int temp = (a ^ b); 
	int ct = 0; 
	int i = 0; 
	while ( temp >= (1 << i) ){
		if ((temp & (1 << i)) == (1 << i)) ct++; 
		i++; 
	}
	return ct; 
}

void dfs(int depth, int start){
//	cout << depth << " " << start << endl; 
	if (depth == N){ //process
		for (int i = 0; i<N; i++){
			if (i % 10 != 0) fout << " "; 
			fout << arrs[i]; 
			if ( (i %10 == 9) || (i == N-1)){
				fout << endl; 
			}
		}
		exit(0); 
	}
	for (int i = start; i< maxN; i++){
		for (int j = 0; j<depth; j++){
			if (!bigHam[i][arrs[j]]) break; 
			if (j == depth-1){ //j is far enough away from everything else 
				arrs[depth] = i; 
				dfs(depth+1, i+1);  
			}
		}
	}
}

int main() {
	fin >> N >> B >> D;  //want N codewords all < 2^B 
	maxN = 1 << B; 
	for (int i = 0; i<=maxN; i++){
		for (int j = 0; j<=maxN; j++){
			if (ham(i,j) < D) bigHam[i][j] = false; 
			else bigHam[i][j] = true; 
		}
	}
	arrs[0] = 0; 
	dfs(1, 1); 
}