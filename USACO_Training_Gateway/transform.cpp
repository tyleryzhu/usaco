/*
ID: tylerzh1
PROG: transform 
LANG: C++11
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std; 

#define REP(i, a, b) \
	for (int i = int(a); i < int(b); i++)

int N; 

ofstream fout("transform.out"); 
ifstream fin("transform.in"); 

bool trans(int arrs[10][10], int end[10][10], int t){
	int tran[10][10]; 
	if (t == 1){				//rotate by 90
		for (int i = 0; i<N; i++){
			for (int j = 0; j<N; j++){
				if (end[i][j] != arrs[N-1-j][i]){
					return false; 
				}
			}
		}
		return true; 
	}
	else if (t == 2){
		for (int i = 0; i<N; i++){
			for (int j = 0; j<N; j++){
				if (end[i][j] != arrs[N-1-i][N-1-j]){
					return false; 
				}
			}
		}
		return true; 
	}
	else if (t == 3){
		for (int i = 0; i<N; i++){
			for (int j = 0; j<N; j++){
				if (arrs[i][j] != end[N-1-j][i]){
					return false; 
				}
			}
		}
		return true; 
	}
	else if (t == 4){
		for (int i = 0; i<N; i++){
			for (int j = 0; j<N; j++){
				if (end[i][j] != arrs[i][N-1-j]){
					return false; 
				}
			}
		}
		return true; 
	}
	else if (t == 5){
		int hor[10][10]; 
		for (int i = 0; i<N; i++){
			for (int j = 0; j<N; j++){
				hor[i][j] = arrs[i][N-1-j]; 
			}
		}
		for (int i = 1; i< 4; i++){
			if (trans(hor, end, i)){
				return true; 
			}
		}
		return false; 
	}
	else if (t == 6){
		for (int i = 0; i<N; i++){
			for (int j = 0; j<N; j++){
				if (arrs[i][j] != end[i][j]){
					return false; 
				}
			}
		}
		return true; 
	}

	return false; 
}

int main() { 
	int arrs[10][10]; 
	int end[10][10]; 
	fin >> N; 
	for (int i = 0; i<N; i++){
		string temp; 
		fin >> temp; 
		for (int j = 0; j<N; j++){
			if (temp.at(j) == '@') arrs[i][j] = 1; 
			else arrs[i][j] = 0; 
		}
	}

	for (int i = 0; i<N; i++){
		string temp; 
		fin >> temp; 
		for (int j = 0; j<N; j++){
			if (temp.at(j) == '@') end[i][j] = 1; 
			else end[i][j] = 0; 
		}
	}
	/**
	REP(i, 0, N){
		REP(j, 0, N){
			fout << arrs[i][j] << " "; 
		}
		fout << endl; 
	}
	**/

	for (int i = 1; i< 7; i++){
		if (trans(arrs, end, i)) {
			fout << i << endl; 
			return 0; 
		}
	}
	fout << 7 << endl; 
	return 0; 
}
