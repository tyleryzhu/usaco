/**
	ID: tylerzh1
	PROB: numtri
	LANG: C++11 
**/
#include <fstream>

using namespace std; 

ofstream fout("numtri.out"); 
ifstream fin("numtri.in"); 

int R; 
int arrs[1000][1000]; 

int main() {
	fin >> R; 
	for (int i = 0; i<R; i++){
		for (int j = 0; j<=i; j++){
			fin >> arrs[i][j]; 
		}
	}
	/** Iterate bottom up **/ 
	for (int i = R-1; i--;){
		for (int j = 0; j <= i; j++){
			arrs[i][j] += max(arrs[i+1][j], arrs[i+1][j+1]); 
		}
	}
	fout << arrs[0][0] << endl; 
}