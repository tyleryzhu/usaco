/**
	ID: tylerzh1
	PROB: dualpal
	LANG: C++11
**/
#include <fstream>
#include <iostream>
#include <string> 

using namespace std; 

ofstream fout("dualpal.out"); 
ifstream fin("dualpal.in"); 

bool palind(int n, int b){ //returns true if n is a palindrom in base b; 
	string conv = ""; 
	while (n > 0){
		char temp; 
		temp = ((n % b) +'0'); 
		conv += temp; 
		n /= b; 
	}
	int len = conv.length()-1; 
	for (int i = 0; i<len; i++){
		if (conv.at(i) != conv.at(len)) return false; 
		len--; 
	}
	return true; 
}
int main() {
	int N, S; 
	fin >> N >> S; 
	S++; 
	int counter = 0; 
	while (counter < N){
		bool mark = false; 
		for (int i = 2; i<11; i++){ // go through the bases
			if (!mark){
				if (palind(S, i)){
					mark = true; 
				}
			}
			else {
				if (palind(S, i)){
					fout << S << endl; 
					counter++; 
					break; 
				}
			}
		}
		S++;
	}
	return 0; 
}