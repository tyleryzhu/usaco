/**
	ID: tylerzh1
	PROB: inflate
	LANG: C++11
**/

#include <iostream>
#include <fstream>

using namespace std;

ofstream fout("inflate.out"); 
ifstream fin("inflate.in"); 

const int maxN = 10010; 
const int maxM = 10010; 

int pts[maxN]; 
int t[maxN]; 
int dp[maxM]; 

int main() {
    int M, N; // mins and # of categories 
    fin >> M >> N; 
    for (int i = 0; i < N; i++){
        fin >> pts[i] >> t[i];  
    }

    //Knapsack 
    for (int i = 0; i < N; i++){ //iterate through categories 
        for (int j = t[i]; j <= M; j++){
            dp[j] = max(dp[j], dp[j-t[i]]+pts[i]);  
        }
    }

    fout << dp[M] << endl; 
}
