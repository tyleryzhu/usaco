#include <iostream>
#include <iomanip> // controlling precision 
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
	for (int i = int(a); i <= int(b); i++) // a to b, i is local as usual 
#define TRvi(c, it) \
	for (vi::iterator it = (c).begin(); it != (c).end(); it++)

#define INF 2000000000 // 2 billion 
//If you need to recall how to use memset 
#define MEMSET_INF 127 // about 2 B
#define MEMSET_INF_HALF 63 // about 1 B
//memset(dist, MEMSET_INF, sizeof dist); // useful for shortest path distances
//memset(dp_memo, -1, sizeof dp_memo); // useful to initialize DP memoization table
//memset(arr, 0, sizeof arr); 		// useful for clearing arraysof ints

//controlling precision 
// cout << setprecision(3) << something << setprecision(prec) << endl; 	
int main() {

}