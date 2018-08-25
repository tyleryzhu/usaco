#include <iostream>
#include <fstream> 
#include <cmath>

using namespace std; 

ofstream fout("friendcross.out"); 
ifstream fin("friendcross.in"); 

int const maxN = 100010; 
int K; 
int A[maxN]; 
int B[maxN]; //keep track of index of top and bottom fields 

int main() {
	int N; 
	fin >> N >> K; 	
	for (int i = 1; i<= N; i++){
		int temp;
		fin >> temp; 
		A[temp] = i; 
	}
	for (int i = 1; i<= N; i++){
		int temp;
		fin >> temp;
		B[temp] = i; 
	}
	int tot = 0; 
	for (int i = 1; i<= N; i++){ //iterate on the cow type 
		for (int j = 1; j<= N; j++){ //iterate on unfriendly cows
			if (i == j || abs(i-j) <= K) continue; 
			if (A[i] < A[j] && B[j] < B[i]) tot++; 
			else if (A[j] < A[i] && B[i] < B[j]) tot++; 
		}
	}
	fout << tot/2 << endl; 
}