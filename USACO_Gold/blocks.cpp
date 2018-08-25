#include <iostream>
#include <fstream>
#include <string> 

using namespace std; 

string arrs[2][100]; //storing
int N; 

int main() {
	ofstream fout("blocks.out"); 
	ifstream fin("blocks.in"); 

	fin >> N; 
	for (int i = 0; i<N; i++){
		fin >> arrs[0][i] >> arrs[1][i]; 
	}

	for (int i = 'a'; i<= 'z'; i++){ //loop through letters and find max occurance; 
		int sum = 0; 
		for (int j = 0; j<N; j++){  //loop through words
			int len[2] = {0,0};  
			for (int k = 0; k<2; k++){ 
				string temp = arrs[k][j]; 
				for (int l = 0; l < temp.size(); l++){
					if (temp.at(l) == char(i)) len[k]++; 
				}
			}
			sum += max(len[0], len[1]); 
		}
		fout << sum << endl; 
	}
	return 0; 
}