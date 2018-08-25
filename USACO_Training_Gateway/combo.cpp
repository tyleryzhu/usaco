/** 
	ID: tylerzh1
	PROB: combo
	LANG: C++11
**/
#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>

using namespace std;

ofstream fout("combo.out"); 
ifstream fin("combo.in"); 
int n;

bool close(int a, int b){ // dial 1&2numbers, n is # of numbers, x is target
	if (abs(a-b) <= 2) return true;
	if (abs(a-b) >= n-2) return true;
	return false;
}

bool close_enough(int n1, int n2, int n3, int c1, int c2, int c3){
	return close(n1,c1) && close(n2,c2) && close(n3,c3);
}

int main() {
	fin >> n;
	int f[3];
	int m[3];
	fin >> f[0] >> f[1] >> f[2];
	fin >> m[0] >> m[1] >> m[2];

	int total = 0;

	for (int n1 = 1; n1<=n; n1++){
		for (int n2 = 1; n2<=n; n2++){
			for (int n3 = 1; n3<= n; n3++){
				if (close_enough(n1,n2,n3,f[0],f[1],f[2]) || close_enough(n1,n2,n3,m[0],m[1],m[2])){
					total++;
				}
			}
		}
	}
	fout << total << endl;
}
