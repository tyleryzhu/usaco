/**
	ID: tylerzh1
	PROB: milk
	LANG: C++11 
**/
#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std; 

ofstream fout("milk.out");
ifstream fin("milk.in"); 

pair<int, int> arrs[5001]; //keep farmers

bool comp(pair<int, int> a, pair<int, int> b){
	return (a.first < b.first); 
}


int main() {
	int N, M; 
	fin >> N >> M; 
	for (int i = 0; i<M; i++){
		int x, y; 
		fin >> x >> y; 
		arrs[i] = make_pair(x, y); 
	}		
	sort(arrs, arrs+M, comp); 
	int totM = 0;
	int totP = 0; 
	int i = 0; 
	while (totM < N){
		int price = arrs[i].first; 
		int amount = arrs[i].second; 
		if (totM+amount <= N){
			totP += price*amount; 
			totM += amount; 
		}
		else { // adding will fill 
			totP += price * (N-totM); 
			totM +=  (N-totM);  //full
		}
		i++; 
	} 
	fout << totP << endl; 
}