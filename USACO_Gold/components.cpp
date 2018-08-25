//dfs search for # of components
/**
#include <iostream>

using namespace std;

int N, M;
bool arrs[2000][2000]; // adjacency matrix
int visit[2000] = {0};

void dfs(int v){
    visit[v] = 1;
    
    for (int i = 0; i < N; i++){
        if (arrs[v][i] && (visit[i] == 0)){
            dfs(i);
        }
    }
}

int main() {
    int counter = 0;
    cin >> N >> M;
    for (int i = 0; i<M; i++){
        int x, y; // temp storing
        cin >> x >> y;
        arrs[x-1][y-1] = true;
        arrs[y-1][x-1] = true;
    }
    
    for (int i = 0; i<N; i++){
        if (visit[i] == 0) {
            counter++;
            dfs(i);
        }
    }
    
    cout << counter << endl;
    
    return 0;
}
**/

//working bfs component return
#include <iostream>
#include <queue>

using namespace std;

int N, M;
bool arrs[2000][2000]; // adjacency matrix
int visit[2000] = {0};
int counter;
queue<int> q;

void bfs(int v){
    visit[v] = -1;
    q.push(v);
    while (!q.empty()){
        v = q.front();
        q.pop();
        for (int i = 0; i < N; i++){
            if (arrs[v][i] && (visit[i] == 0)){
                visit[i] = v;
                q.push(i);
            }
        }
    }
}

void process(){
    
}

int main() {
    counter = 0;
    cin >> N >> M;
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
    
    cout << counter << endl;
    
    process();
    
    return 0;
}
