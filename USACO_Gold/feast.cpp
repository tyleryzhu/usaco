//wow fast! runs in 1ms for all btu 3 test cases
#include <iostream>
#include <fstream>

using namespace std;

#define REP(i,a,b) /
	for (int i = int(a); i<int(b); i++)

int T, A, B; 
bool arrs[2][5000001] = {false}; //array of vals

int main(){
	ofstream fout("feast.out");
	ifstream fin("feast.in"); 

	fin >> T >> A >> B; 

	arrs[0][0] = true; 

	// first knapsack on normal values. 
	REP(i, 1, T+1){
		if ((i-A)>= 0){
			if (arrs[0][i-A] == true) {
				arrs[0][i] = true; 
				arrs[1][i/2] = true; 
			}
		}
		if ((i-B)>=0){
			if (arrs[0][i-B] == true) {
				arrs[0][i] = true; 
				arrs[1][i/2] = true; 
			}
		}
	}

	REP(i, 1, T+1){
		if (i-A>= 0){
			if (arrs[1][i-A] == true){
				arrs[1][i] = true; 
			}
		}
		if ((i-B)>= 0){
			if (arrs[1][i-B] == true){
				arrs[1][i] = true; 
			}
		}
	}

	bool found = false; 
	int most = T;
	while (!found){
		if (!(arrs[0][most] || arrs[1][most])){//if !(either drink or no drink is good)
			most--; 
		}
		else{
			found = true; 
		}
	}
	fout << most << endl; 
}

