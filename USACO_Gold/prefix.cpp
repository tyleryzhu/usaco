#include <iostream>
#include <fstream>
#include <string>

using namespace std;
ifstream fin("prefix.in");  

const int maxN = 210; 
const int maxL = 200010; 
int N, L; 
string S; 
string prim[maxN]; 
bool dp[maxL]; 

int main() {
    string temp; 
    fin >> temp; 
    while (temp.compare(".") != 0) {
        prim[N] = temp; 
        N++; 
        fin >> temp; 
    }
    while (fin >> temp) {
        S += temp; 
    }
    L = S.size(); 
    dp[0] = true; 
    int best = 0; 
    for (int i = 1; i <= L; i++){
        for (int j = 0; j < N; j++){ //going through our prefix set 
            int b = i-prim[j].size(); //represents index we need to retrieve from
            if (b < 0) continue; 
            if ( (S.substr(b,prim[j].size()).compare(prim[j]) == 0) &&  //if last part is a primitive
                 (dp[b]) ) { //and before is true
                dp[i] = true; 
                break; 
            }
        }
        cout << i << endl; 
        if (dp[i])  best = i; 
    }
    cout << best << endl; 
}
