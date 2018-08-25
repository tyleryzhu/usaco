/**
	ID: tylerzh1
	PROB: barn1
	LANG: C++11
**/
#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std; 

ofstream fout("barn1.out"); 
ifstream fin("barn1.in"); 

bool occ[201] = {false}; 
int block[200]; 

bool comp(int a, int b){
	return a > b; 
}

int main() {
	int M, S, C; 
	fin >> M >> S >> C; 
	int left = S; 
	int right = 0;  
	for (int i = 0; i<C; i++){
		int temp; 
		fin >> temp; 
		temp--; 
		if (temp < left) left = temp; 
		if (temp > right) right = temp; 
		occ[temp] = true; //cow in temp-1 (shift)
	}
	int numBlock = 0; 
	int gap = 0; 
	for (int i = left; i<right+1; i++){ //iterate through boards, see length of gaps 
		if (i == S){
			block[numBlock] = gap; 
			numBlock++; 
		}
		if (occ[i]){
			if (gap > 0){ 
				block[numBlock] = gap; 
				numBlock++; 
				gap = 0; 
			}
		}
		else { // empty
			gap++; 
		}
	}
	sort(block, block+numBlock, comp); 
/**	for (int i = 0; i<numBlock; i++){
		cout << block[i] << " ";
	}
**/	int tot = 0; 
	for (int i = 0; i<M-1; i++){
		tot += block[i]; 
		if (i >= numBlock) break; 
	}
	fout << right - left -tot +1 << endl; 
}