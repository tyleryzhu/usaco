#include <iostream>
#include <algorithm>

using namespace std;

const int maxK = 10010; 

int main() {
    int N, K; 
    cin >> N >> K; 
    int arrs[maxK]; 
    for (int i = 0; i<K; i++){
        cin >> arrs[i]; 
    }
    sort(arrs, arrs+K); 
    int best = arrs[0]; //either smallest (all true) 
    best = max(best, N-arrs[K-1]); //or largest (all false) 
    for (int i = 0; i < K-1; i++){ //or found by a difference 
        best = max(best, (arrs[i+1]-arrs[i])/2); 
    }
    cout << best << endl; 
}
