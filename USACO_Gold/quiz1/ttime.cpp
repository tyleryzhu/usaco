#include <iostream>
#include <queue>

using namespace std;

int N, M, Q; 
bool arrs[2000][2000]; // adjacency matrix
int visit[2000] = {0};
int counter;
queue<int> q;

void bfs(int v){
    visit[v] = counter;
    q.push(v);
    while (!q.empty()){
        v = q.front();
        q.pop();
        for (int i = 0; i < N; i++){
            if (arrs[v][i] && (visit[i] == 0)){
                visit[i] = counter;
                q.push(i);
            }
        }
    }
}

void process(int x, int y){
    if (visit[x] == visit[y]) cout << "Y" << endl; 
    else cout << "N" << endl; 
}

int main() {
    counter = 0;
    cin >> N >> M >> Q;
    for (int i = 0; i<M; i++){
        int x, y; // temp storing
        cin >> x >> y;
        arrs[x-1][y-1] = true;
        arrs[y-1][x-1] = true;
    }
    
    for (int i = 0; i<N; i++){
        if (visit[i] == 0) {
            counter++;
            bfs(i);
        }
    }
        
    for (int i = 0; i<Q; i++){
    	int x, y; // temp
    	cin >> x >> y; 
    	x--; y--;  // shift
    	process(x,y); 
    }
    
    return 0;
}