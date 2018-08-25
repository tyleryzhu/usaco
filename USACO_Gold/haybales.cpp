#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector> 

using namespace std; 

ofstream fout("haybales.out"); 
ifstream fin("haybales.in"); 
const int maxN = 100010; 
vector<int> arrs(maxN);  //prefix sum in this array

int main() {
	int N, Q; 
	fin >> N >> Q; 
	arrs[0] = -1; //for prefix sum; 
	for (int i = 1; i <= N; i++){
		fin >> arrs[i]; 
	}	

	sort(arrs.begin(), arrs.begin()+N+1); 

	for (int m = 0; m<Q; m++){ //queries
		int A, B; 
		fin >> A >> B; 
		vector<int>::iterator low,high; 
		low = lower_bound(arrs.begin(), arrs.begin()+N+1, A); 
		high = upper_bound(arrs.begin(), arrs.begin()+N+1, B); 
		int left = low - arrs.begin(); 
		int right = high - arrs.begin(); 
		fout << right-left << endl; 
	}
	return 0; 
}