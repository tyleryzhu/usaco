#include <iostream>
#include <fstream>
#include <queue>
#include <vector>
#include <map> 

using namespace std; 

typedef pair<int, int> 		ii; 
typedef vector<ii> 			vii; 

#define REP(i,a,b) \
	for (int i = int(a); i<int(b); i++)

int dx[4] = {1,-1,0,0}; 
int dy[4] = {0,0,1,-1}; 
int N, M;
vii arrs[100][100]; 
bool light[100][100] = {false}; 
bool mark[100][100] = {false}; 
queue<int> qx; 
queue<int> qy; 

bool legal_1(int x, int y){
	if (x <0 || x >= N || y < 0 || y >= N) return false; 
	if (mark[x][y] == true) return false; 
	if (light[x][y] == false) return false; 
	return true; //basically lit but unvisited
}

bool legal_2(int x, int y){ // basically if the neighbor is marked
	if (x<0 || x >= N || y < 0 || y >= N) return false; 
	if (mark[x][y]) return true; 
	return false; 
}

int bfs() {
	int counter = 0; //keep track of how many rooms are lit
	qx.push(0); 
	qy.push(0); 
	light[0][0] = true; 
	mark[0][0] = true; 
	counter++; 
	while (!qx.empty()){
		int x = qx.front(); int y = qy.front(); 
		qx.pop(); qy.pop(); 

		//checking neighbors of x,y for lit but unvisited
		REP(i,0,4){
			int nx = x+dx[i]; 
			int ny = y+dy[i]; 
			if (legal_1(nx,ny)){
				qx.push(nx); 
				qy.push(ny); //simply marking, not lighting
				mark[nx][ny] = true; 
			}
		}

		//now check for which rooms x,y makes lit
		for (int m = 0; m < arrs[x][y].size(); m++){ // traversing the vector
			int nx = arrs[x][y][m].first; 
			int ny = arrs[x][y][m].second; //get the x and y of whatever room this thing makes lit 
			if (!light[nx][ny]){
				light[nx][ny] = true; //lit 
				counter++; 
				REP(i, 0, 4){				//seeing if any neighbors are good
					if (legal_2(nx+dx[i],ny+dy[i]) && !mark[nx][ny]){ // if any neighbors are marked and spot itself is unmarked
						qx.push(nx); 
						qy.push(ny); 
						mark[nx][ny] = true; 
					}
				}
			}
		}
	}
	return counter; 
}

int main() {
	ofstream fout("lightson.out");
	ifstream fin("lightson.in"); 

	fin >> N >> M; 

	int x,y, a,b; 
	REP(i, 0, M){
		fin >> x >> y >> a >> b; 
		x--; y--; a--; b--; 

		arrs[x][y].push_back(make_pair(a,b));  
	}

	fout << bfs() << endl; 
}