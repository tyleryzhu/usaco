#include <iostream>
#include <fstream> 
#include <algorithm>

using namespace std; 

#define REP(i,a,b) \
	for (int i = int(a); i<int(b); i++)

int arrs[50000]; 
int N, K, max;

bool good(int R){
	int temp = 2*R+ arrs[0]; 
	int use = 1; 
	REP(i, 0, N){
		if (arrs[i] <= temp) 
			continue; 
		temp = arrs[i] + 2*R; 
		use++; 
		if (use > K) 
			return false; 
	}
	return true; 
}

int main() {
	ofstream fout("angry.out"); 
	ifstream fin("angry.in"); 

	fin >> N >> K; 
	REP(i, 0, N){
		fin >> arrs[i]; 
	}	
	sort(arrs, arrs+N); 

	int low = 1; 
	int high = arrs[N-1]; 
	int mid; 
	//binary search
	while (low < high) {
		mid = low + (high - low)/2; 
		if (good(mid) == true) 
			high = mid; 
		else 
			low = mid+1; 
	}

	fout << low << endl; 
}