/*
ID: tylerzh1
PROG: beads 
LANG: C++11
*/

#include <fstream>
#include <iostream>
#include <string> 

using namespace std; 

int main() {
	ofstream fout("beads.out"); 
	ifstream fin("beads.in"); 
	int N; 
	string bead; 
	fin >> N >> bead; 
	bool blue = false;
	bool red = false; 
	int leng = bead.length(); 
	int ct = 0; 
	while (!(blue && red) && (ct < bead.length())){
		if (bead.at(ct) == 'b') blue = true; 
		else if (bead.at(ct) == 'r') red = true; 
		ct++; 
		if (blue && red) break; 
	}	
	string beads = bead.substr(0,ct); 
	bead += beads; 
	int max = 0; 
	for (int i = 0; i<bead.length()-1; i++){
		int left = i; 
		int right = i+1; 
		int counter = 0; 
		char lBead;
		char rBead; 
			int x = left; 
			while (x >= 0 && bead.at(x) == 'w' ){
				x--; 
			}
			if (x  < 0) x++; 
			lBead = bead.at(x); 
			x = right; 
			while (x <bead.length() && bead.at(x) == 'w') x++; 
			if (x >= bead.length()) x--; 
			rBead = bead.at(x); 

		while (left >= 0){
			if (counter >= leng) break; 
			if ((bead.at(left) == 'w') || (bead.at(left) == lBead)){ // if we find an okay color bead
				counter++; 
			}
			else {
				break; 
			}
			left--; 
		}
		while (right < bead.length()){
			if (counter >= leng) break; 
			if ((bead.at(right) == 'w') || (bead.at(right) == rBead)){
				counter++; 
			}
			else {
				break; 
			}
			right++; 
		}
		if (counter > max) max = counter; 
	}
	fout << max << endl; 
}