/**
	ID: tylerzh1
	PROB: skidesign
	LANG: C++11 
**/
#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std; 

ofstream fout("skidesign.out"); 
ifstream fin("skidesign.in"); 

int arrs[1000]; 

int main() {
	int N; 
	fin >> N;
	int lo = 100; 
	int hi = 0; 
	for (int i = 0; i<N; i++){
		fin >> arrs[i]; 
		if (arrs[i] < lo) lo = arrs[i]; 
		if (arrs[i] > hi) hi = arrs[i]; 
	}
	sort(arrs, arrs+N); 
	int minCost = 1<<29; 
	for (int i = lo; i < hi-16; i++){
		int cost = 0; 
		int ind = 0; 
		while ( arrs[ind] < i){ //less than lower bound
			cost += (i-arrs[ind])*(i-arrs[ind]); 
			ind++; 
		}
		ind = N-1; 
		while ( arrs[ind] > i+17){
			cost += (arrs[ind]-(i+17))*(arrs[ind]-(i+17)); 
			ind--; 
		}
		if (cost < minCost) minCost = cost; 
	}
	fout << minCost << endl; 
}