#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M; 
int arrs[7000][7000]; 

bool cycle(int v) {
    

}

int main() {
    cin >> N >> M; 
    for (int i = 0; i < M; i++){
        int num; 
        cin >> num; 
        int obs[num]; 
        for (int j = 0; j < num; j++){
            cin >> obs[j]; 
        }
        for (int j = 0; j < num; j++){
            if (j == num-1) 
                arrs[obs[j]][obs[0]] = 1; 
            else 
                arrs[obs[j]][obs[j+1]] = 1; 
        }
        // Adj is made, now check for cycles. 
        bool cycleFound = false; 
        for (int v = 1; v <= N; v++){
            if (cycle(v)) { //Bad, b/c cycle
                cycleFound = true; 
                //Remove the edges we just put in
                for (int j = 0; j < num; j++){
                    if (j == num-1) 
                        arrs[obs[j]][obs[0]] = 0; 
                    else 
                        arrs[obs[j]][obs[j+1]] = 0; 
                }
                break; 
            }
        }
        if (cycleFound) break; 
    }
    vector<vector<int> > l(N+1); 
    for (int i = 1; i <= N; i++){
        bool nun = true; 
        for (int j = 1; j <= N; j++){
            if (arrs[j][i] == 1) // There is a parent to i
                nun = false; 
        }
        if (nun) l[0].push_back(i); 
    }
    
    // Now perform a BFS to fill up l 
    queue<pair<int, int> > q; 
    for (int i = 0; i < l[0].size(); i++){
        q.push(make_pair(l[0][i], 0)); 
    }
    while (!q.empty()) {
        


    }
}
