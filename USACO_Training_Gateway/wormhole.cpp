/**
	ID: tylerzh1
	PROB: wormhole
	LANG: C++11
**/

#include <iostream>
#include <fstream>
#include <algorithm>
#include <cstring>

using namespace std; 

ofstream fout("wormhole.out"); 
ifstream fin("wormhole.in"); 

int N; 
int x[13]; 
int y[13]; 
int perm[13]; 
int nbr[13]; //keep track of paired wormholes
int onRight[13]; 

bool cycle(void){
	for (int i = 0; i<N; i++){
		int start = i; 
		if (onRight[start] == -1) continue; 
		start = nbr[onRight[start]];  //represents warping to a new location
		while (onRight[start] != -1){
			start = nbr[onRight[start]]; 
			if (start == i) return true; 
		}
	}
	return false; 
}

int main() {
	fin >> N; 
	for (int i = 0; i<N; i++){
		fin >> x[i] >> y[i]; 
		perm[i] = i; 
		onRight[i] = -1; 
	}

	for (int i = 0; i<N; i++){ //figure out wormholes that are on the right of other wormholes
		for (int j = 0; j<N; j++){
			if ((y[j] == y[i]) && (x[i] < x[j])){ //if on the right and in the same line
				if (onRight[i] == -1) onRight[i] = j; 
				else {
					if (x[j] < x[onRight[i]]) onRight[i] = j;  //if closer 
				}
			}
		}
	}

	int tot = 0; 
	do {
		//makes a unique pairing
		if (perm[0] != 0) break; 
		int i; 
		for (i = 0; i<N/2; i++){ //check if pairing is unique
			if (perm[2*i] > perm[2*i+1]) break; //check if pairs are ascending
			if ((i < (N/2)-1) && perm[2*(i+1)] < perm[2*i]) break;  //check if pstarting of pairs are increasing 
		} 
		if (i != N/2) continue; 
		for (i = 0; i<N/2; i++){
			nbr[perm[2*i]] = perm[2*i+1]; 
			nbr[perm[2*i+1]] = perm[2*i]; 
		}
		if (cycle()) tot++; 
	} while(next_permutation(perm, perm+N)); 
	fout << tot << endl; 
}