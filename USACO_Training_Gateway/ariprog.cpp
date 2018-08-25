/**
	ID: tylerzh1
	PROB: ariprog
	LANG: C++11
**/
#include <iostream>
#include <fstream>
#include <algorithm>
#include <queue>

using namespace std;

ofstream fout("ariprog.out"); 
ifstream fin("ariprog.in"); 

int N, M, maxM; 
bool is_bisq[150000] = {false}; //true if i is a bisquare 
int bisq[130000]; 

int main() {
	int numB = 0; 
	bool sols = false; 
	fin >> N >> M; 
	maxM = 2*M*M; 
	//generate bisquares; 
	for (int i = 0; i<=M; i++){
		for (int j = i; j<= M; j++){
			if (!is_bisq[i*i+j*j]){
				bisq[numB] = i*i+j*j; 
				numB++; 
			}
			is_bisq[i*i+j*j] = true; 
		}
	}
	sort(bisq, bisq+numB); 
	//generate sequeunces w/ dfs
	int maxDif = maxM/(N-1); 
	for (int dif = 1; dif <= maxDif; dif++){ //iterate on differences
		for (int i = 0; i<numB; i++){ //iterate on starting points
			for (int j = 0; j<N; j++){
				if (!is_bisq[bisq[i]+dif*j]){
					break; 
				}
				else if (j == N-1){
					sols = true; 
					fout << bisq[i] << " " << dif << endl;  
				}
			}
		}
	}
	//output solutions
	if (!sols) fout << "NONE\n"; 
	return 0; 
}