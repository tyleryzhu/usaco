/*
ID: tylerzh1
PROG: milk2 
LANG: C++11
*/

#include <iostream>
#include <fstream>
#include <string> 
#include <algorithm>
#include <queue>
#include <vector> 
#include <map> 
#include <set> 
#include <list> 

using namespace std; 

//Shortcuts for common data types in contests
typedef long long 			ll; 
typedef vector<int> 		vi; 
typedef pair<int, int> 		ii; 
typedef vector<ii> 			vii; 
typedef set<int> 			si; 
typedef map<string, int>	msi; 

//To simplify repetitions/loops, Note: Define your loop style and stick with it! 
#define REP(i,a,b) \
	for (int i = int(a); i < int(b); i++) // a to b, i is local as usual 
#define TRvi(c, it) \
	for (vi::iterator it = (c).begin(); it != (c).end(); it++)
#define TRvii(c, it) \
	for (vii::iterator it = (c).begin(); it != (c).end(); it++)
#define TRmsi(c, it) \
	for (msi::iterator it = (c).begin(); it != (c).end(); it++)

#define INF 2000000000 // 2 billion 
//If you need to recall how to use memset 
#define MEMSET_INF 127 // about 2 B
#define MEMSET_INF_HALF 63 // about 1 B
//memset(dist, MEMSET_INF, sizeof dist); // useful for shortest path distances
//memset(dp_memo, -1, sizeof dp_memo); // useful to initialize DP memoization table
//memset(arr, 0, sizeof arr); 		// useful for clearing arrays of ints

int arrs1[5000]; 
int arrs2[5000]; 

int main() {
	ofstream fout("milk2.out");
	ifstream fin("milk2.in"); 

	int N; 
	fin >> N; 
	int max = 0; //keep track of max time

	REP(i, 0, N){
		fin >> arrs1[i] >> arrs2[i]; 
		if (arrs2[i] > max) max = arrs2[i]; 
	}

	sort(arrs1.begin(), arrs1.begin()+N); 
	sort(arrs2.begin(), arrs2.begin()+N); 

	int one = 0; //counter for arrs1
	int two = 0; //counter for arrs2
	int total = 0; 			//total # of farmers milking
	int CowMax = 0; 		// longest interval for milking cows
	int noCowMax = 0; 		//longest interval for which no cow was milked
	bool milking = false; 
	int startmilk;
	int endmilk = -1; 

	REP(i, 0, 2*N){
		if (one < N && arrs1[one] < arrs2[two]){  // another farmer begins milking
			total++; 
			if (!milking){				//begins milking
				startmilk = arrs1[one]; 
				milking = true; 
				if (endmilk != -1){
					if (startmilk - endmilk >noCowMax) noCowMax = startmilk-endmilk; 
				}
			}
			one++; 
		}
		if (two < N && arrs2[two] < arrs1[one]){
			total--; 
			if (total == 0){			//ends milking
				milking = false; 
				endmilk = arrs2[two]; 
				if (endmilk-startmilk > cowMax) cowMax = endmilk-startmilk; 
			}
			two++; 
		}
		else { //two currente entries are equal
			one++; 
			two++; 
		}	
	}
	fout << cowMax << " " << noCowMax << endl; 
}
