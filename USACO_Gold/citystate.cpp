#include <fstream>
#include <iostream>
#include <algorithm>
#include <vector> 

using namespace std; 

#define REP(i, a, b) \
	for (int i = int(a); i < int(b); i++)
ofstream fout("citystate.out");
ifstream fin("citystate.in"); 
const int maxN = 200010; 
vector<pair<string, string> > arrs(maxN);  //keep cities first, state second

int main () {
	int N; 
	fin >> N; 

	REP(i, 0, N){
		string temp1, temp2; 
		fin >> temp1 >> temp2; 
		temp1 = temp1.substr(0, 2);  
		arrs[i] = make_pair(temp1, temp2); 
	}

	sort(arrs.begin(), arrs.begin() +N); 
/**
	REP(i, 0, N){
		cout << arrs[i].first << " " << arrs[i].second << endl; 
	}
**/
	int counter = 0; 
	REP(i, 0, N){
		pair<string, string> state = make_pair(arrs[i].second, arrs[i].first); //searching for the state first. 
		vector<pair<string, string> >::iterator low, high; 
		low = lower_bound(arrs.begin(), arrs.begin() + N, state); 
		high = upper_bound(arrs.begin(), arrs.begin() + N, state); 
		int left = low-arrs.begin(); 
		int right = high-arrs.begin(); 
//		cout << left << " " << right << endl; 	
		REP(j, left, right){
			if (arrs[i].first == arrs[j].second && arrs[i].second != arrs[j].second) counter++; 
		}
	}
	fout << counter/2 << endl; 
}