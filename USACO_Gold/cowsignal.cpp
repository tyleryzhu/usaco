#include <iostream>
#include <fstream>
#include <string>

using namespace std; 

int main() {
	ofstream fout("cowsignal.out"); 
	ifstream fin("cowsignal.in"); 
	int M, N, K; 

	fin >> M >> N >> K; 
	for (int i = 0; i<M; i++){
		string temp; 
		fin >> temp; 
		for (int l = 0; l<K; l++){
		for (int j = 0; j<N; j++){ //for each character
			for (int m = 0; m<K; m++){ //output k times
				fout << temp.at(j); 
			}
		}
		fout << endl; 
	}
	}
	return 0; 
}