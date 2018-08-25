#include <iostream>
#include <fstream> 
#include <queue> 
#include <climits>

using namespace std; 

ofstream fout("visitfj.out"); 
ifstream fin("visitfj.in"); 

const int maxN = 105; 
const int INF = 1 << 30; //smaller than memset(64)
int N, T;
int arrs[maxN][maxN]; 
int visit[maxN][maxN][3]; //mod 3 for steps
int dx[4] = {1,-1,0,0}; 
int dy[4] = {0,0,1,-1}; 

bool in_bounds(int i, int j){
	if (i < 1 || i > N || j < 1 || j > N) return false;
	return true; 
}

class prioritize{public: bool operator ()(pair<pair<pair<int, int>, int>, int>&p1 ,pair<pair<pair<int, int>, int>, int>&p2){return p1.second>p2.second;}};
//(i,j, steps mod 3, dist)

int main() {
	fin >> N >> T;
	for (int i = 1; i<= N; i++){
		for (int j = 1; j<= N; j++){
			fin >> arrs[i][j]; 
			visit[i][j][0] = INF; 
			visit[i][j][1] = INF; 
			visit[i][j][2] = INF; 
		}
	}

	priority_queue< pair<pair<pair<int, int>, int>, int>, vector<pair<pair<pair<int, int>, int>, int> >, prioritize> pq; 
	pq.push(make_pair(make_pair(make_pair(1,1), 0),0)); 
	while (!pq.empty()){
		int x = pq.top().first.first.first;   //node at the top
		int y = pq.top().first.first.second; 
		int s = pq.top().first.second;  //steps mod 3; 
		int d = pq.top().second; //time 
		pq.pop(); 

		if (x == N && y == N) {
			fout << d << endl; 
			return 0; 
		}
		if (visit[x][y][s] != INF) continue; 
		visit[x][y][s] = d; 

		for (int i = 0; i<4; i++){
			int nx = x + dx[i]; 
			int ny = y + dy[i]; 
			int ns = s+1; 
			ns %= 3; 
			int nd = d + T; 

			if (!in_bounds(nx, ny)) continue; 

			if (ns == 0){ // third move
				nd += arrs[nx][ny]; 
			}
			if (visit[nx][ny][ns] < nd) continue; 
//			cout << nx << " " << ny << " " << ns << " " << nd << endl; 
			pq.push(make_pair(make_pair(make_pair(nx,ny),ns),nd)); 
		}
	}

}