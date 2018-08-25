#include <iostream>
#include <map> 

using namespace std; 

const int maxN = 50010; 

int arrs[maxN]; //for keeping the breed IDs 

int main() {
	int N, K; 
	cin >> N >> K; 
	map<int, int> mymap; 
	for (int i = 1; i<= N; i++){
		cin >> arrs[i]; 
		if (i <= K+1) {//create a sliding window 
			if (mymap.insert(make_pair(arrs[i], 0)).second == true) mymap[arrs[i]] = 0; 
			mymap[arrs[i]]++;  //add to value
		}
	}
	int best = -1; 
	for (int i = 1; i<= N; i++){
		if (mymap[arrs[i]] > 1) best = max(best, arrs[i]); //if arrs[i] is crowded, update best as needed
		mymap[arrs[i]]--; 
		if (i >= N-K) continue;  //allows you to check last K IDs 
		if (mymap.insert(make_pair(arrs[i+K+1], 0)).second == true) mymap[arrs[i+K+1]] = 0;  //not in map 
		mymap[arrs[i+K+1]]++; 
	}
	cout << best << endl; 
}