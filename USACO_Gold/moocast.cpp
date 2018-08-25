#include <fstream>
#include <iostream>
#include <vector>

using namespace std; 

ofstream fout("moocast.out"); 
ifstream fin("moocast.in"); 
#define REP(i, a, b) \
	for (int i = int(a); i< int(b); i++)
const int maxN = 202; 
bool arrs[maxN][maxN]; //transitive
int x[maxN];
int y[maxN];
int r[maxN]; 

bool neighbor(int a, int b){ //returns if b is a neighbor of a
	int dist = (x[b]-x[a])*(x[b]-x[a])+(y[b]-y[a])*(y[b]-y[a]); 
	if (dist <= r[a]*r[a]) return true; 
	return false; 
}


int main() {
	int N; 
	fin >> N; 
	REP(i, 0, N){
		fin >> x[i] >> y[i] >> r[i]; 
	}

	REP(i, 0, N){
		REP(j, 0, N){
			if (i == j) arrs[i][j] = true; 
			else arrs[i][j] = neighbor(i,j); 
		}
	}

	/** Transitive Closure **/
	REP(k, 0, N){
		REP(i, 0, N){
			if (arrs[i][k]) {
				REP(j, 0, N){
					if (arrs[k][j]) arrs[i][j] = true; 
				}
			}
		}
	}

	int max = 0; 
	REP(i, 0, N){
		int sum = 0; 
		REP(j, 0, N){
			if (arrs[i][j]) sum++; 
		}
		if (sum > max) max = sum; 
	}
	fout << max << endl; 
}