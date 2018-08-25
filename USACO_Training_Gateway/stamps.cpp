/**
	ID: tylerzh1
	PROB: stamps
	LANG: C++11
**/

#include <iostream>
#include <fstream>
#include <queue>

using namespace std;

ofstream fout("stamps.out"); 
ifstream fin("stamps.in"); 

int dp[2500000]; // K by maxVal; use 2 by maxVal and use sliding window
int vals[55]; 

int main() {
    int K, N; 
    queue<int> q; 
    fin >> K >> N; 
    for (int i = 0; i < N; i++){
        fin >> vals[i]; 
    }
    dp[0] = 0; 
    q.push(0); 
    int most = 0; //keep track of max just for optimization; 
    //BFS to check all of the values
    while (!q.empty()) {
        int x = q.front(); 
        most = max(most, x); 
        q.pop(); 
        if (dp[x] >= K) continue; //used too many times
        for (int i = 0; i < N; i++) {
            if (dp[x+vals[i]] == 0) { //unvisited
                dp[x+vals[i]] = dp[x]+1; 
                q.push(x+vals[i]); 
            }
        }
    }
    int best = 0;
    int ct = 0; 
    for (int i = 1; i <= most; i++){
        if (dp[i] != 0) 
            ct++; 
        else
            ct = 0; 
        best = max(ct, best); 
    }
    fout << best << endl; 
}
