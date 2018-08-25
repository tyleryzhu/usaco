/**
	ID: tylerzh1
	PROB: runround
	LANG: C++11 
**/
#include <iostream>
#include <fstream>
#include <vector> 

using namespace std; 

ofstream fout("runround.out"); 
ifstream fin("runround.in"); 

bool is_round(long long N){ //returns if N is a runround integer
	int arrs[20];  //store N in array form 
	int dig = 0; 
	bool digUse[10] = {false}; 
	while (N > 0){
		if (N % 10 == 0) return false; //runrounds have no 0's
		arrs[dig] = N%10; 
		if (digUse[N%10]) return false; //need unique digits
		else digUse[N%10] = true; 
		dig++; 
		N/= 10; 
	}
	for (int i = 0; i<dig/2; i++){
		int temp = arrs[dig-i-1]; 
		arrs[dig-i-1] = arrs[i]; 
		arrs[i] = temp; 
	}

	bool mark[20]; 
	for (int i = 0; i<dig; i++){
		mark[i] = false; 
	}
	int ind = 0; //start form left most index
	while (!mark[0]){ //first one is unvisited
		ind += arrs[ind]; 
		ind %= dig; 
		if (mark[ind]){ //new number is already marked
			return false; //not runround since visitnig something twice
		}
		mark[ind] = true; 
	}
	for (int i = 0; i < dig; i++){
		if (!mark[i]) return false; 
	}
	return true; 
}

int main() {
	long long N; 
	fin >> N; 
	N++; 
	for (; !is_round(N); N++)
		; 
	fout << N << endl; 
	return 0; 
}
