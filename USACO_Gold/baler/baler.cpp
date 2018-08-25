//usaco week 05
//problem 1
//baler
#include <iostream>

using namespace std;
int N, Xt, Yt, s, t; // Xt,Yt are power roller, s and t are index of the driver and power resp.

int x[1050];
int y[1050];
int r[1050];
double p[1050];
bool visit[1050] = {false};

bool tangent(int a, int b) {
    int dist = (x[a]-x[b])*(x[a]-x[b]) + (y[a]-y[b])*(y[a]-y[b]);
    return (dist == ((r[a]+r[b])*(r[a]+r[b])));
}

void power(int transfer, int receiver){ //transfer is roller transferring, etc.
    p[receiver] = p[transfer] * r[transfer] / ((double) r[receiver]);
}

void dfs(int ind, double pow){ // index of roller and current passed power
    if (ind == t) { // end condition
        cout << (int) pow << endl; 
        return;
    }
    for (int i = 0; i<N; i++){
        if (tangent(ind, i) && !visit[i]){
            visit[i] = true; 
            power(ind, i); 
            dfs(i, pow+p[i]); 
        }
    }
}

int main() {
    cin >> N >> Xt >> Yt;
    for (int i = 0; i<N; i++){
        cin >> x[i] >> y[i] >> r[i];

        if ((x[i] == 0) && (y[i] == 0)){
            s = i;
        }
        if ((x[i] == Xt) && (y[i] == Yt)){
            t = i;
        }
    }

    p[s] = 10000; 
    visit[s] = true;

    dfs(s, p[s]);
}