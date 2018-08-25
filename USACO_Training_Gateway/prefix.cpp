/**
	ID: tylerzh1
	PROB: prefix 
	LANG: C++11
**/
#include <iostream>
#include <fstream>
#include <string>

using namespace std; 

ofstream fout("prefix.out"); 
ifstream fin("prefix.in"); 

int numPrim = 0; 
string prim[200]; //primitives
bool dp[200010] = {false}; //if prefix of length i is prim, dp[i] is true 
string sequence = ""; 

int main() {
	string temp; 
	fin >> temp; 
	while (temp.compare(".") != 0){
		prim[numPrim] = temp; 
		numPrim++; 
		fin >> temp; 
	}
	while (fin >> temp){
		sequence += temp; 
	}
	dp[0] = true; //no prefix, vacuously true 
	int maxPref = 0; 
	for (int i = 0; i<sequence.length(); i++){ //iterate from first one to last 
		if (!dp[i]) continue; // prefix isn't good 
		for (int j = 0; j<numPrim; j++){ //check all primitives
			if ( (i+prim[j].length() <= sequence.length()) && 
				(sequence.substr(i, prim[j].length()).compare(prim[j]) == 0)){ //first prim[j].lenght() prefix equals prim[j]
				dp[prim[j].length()+i] = true; //prefix is good 
				if (prim[j].length()+i > maxPref) maxPref = prim[j].length()+i; 
			}
		}
	}
	fout << maxPref << endl; 
}
