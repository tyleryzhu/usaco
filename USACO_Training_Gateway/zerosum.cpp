/**
	ID: tylerzh1
	PROB: zerosum 
	LANG: C++11
**/
#include <iostream>
#include <fstream>
#include <string> 

using namespace std; 

ofstream fout("zerosum.out"); 
ifstream fin("zerosum.in"); 

int N; 

void process(string ops){
	int sum = 0; 
	int curr = 1; //keeps track of current number to be added/subtracted
	for (int i = 0; i<N-1; i++){
		if (ops.at(i) == '+'){
			sum += curr; 
			curr = i+2; 
		}
		else if (ops.at(i) == '-'){
			sum += curr; 
			curr = -i-2; 
		}
		else { //space 
			curr *= 10; 
			if (curr < 0) curr -= i+2;
			else curr += i+2; 
		}
	}
	sum += curr; 
	if (sum == 0){
		fout << "1";  
		for (int i = 0; i<N-1; i++){
			fout << ops.at(i) << i+2; 
		}
		fout << endl; 
	}
}

void dfs(string ops){ //generate the possible operations
	if (ops.length() == N-1){
		process(ops); 
		return; 
	}
	dfs(ops+" "); 
	dfs(ops+"+"); 
	dfs(ops+"-"); 
}

int main() {
	fin >> N; 
	dfs(""); 	
}
