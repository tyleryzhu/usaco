#include <iostream>
#include <fstream>
#include <queue>
#include <string>

using namespace std; 

ofstream fout("cownav.out"); 
ifstream fin("cownav.in"); 

#define REP(i,a,b) \
	for (int i = int(a); i < int(b); i++) // a to b, i is local as usual 

#define INF 2000000000 // 2 billion 
//If you need to recall how to use memset 
#define MEMSET_INF 127 // about 2 B
#define MEMSET_INF_HALF 63 // about 1 B
int N; 
bool empty[20][20]; //storing the grid :  
int dx[4] = {0, 1, 0, -1};  //N, E, S, W; 
int dy[4] = {-1, 0, 1, 0}; 


struct hay{
	int x, y; 
	int dir; // 0 is N, 1 is E, 2 is S, 3 is W; 
	int dist; 
};

bool dest(hay c){ //at destination
	if (c.x == N-1 && c.y == N-1) return true; 
	return false; 
}

hay make_hay(int x, int y, int dir , int dist){
	hay temp = {x,y,dir, dist}; 
	return temp; 
}

int bfs(int x, int y){
	queue<hay> path1; //for taking one direction    1
	queue<hay> path2;  // for taking other direction 2 
	hay c1 = {0,0,1,0}; 
	hay c2 = {0,0,2,0}; 
	path1.push(c1); 
	path2.push(c2); 
	while (!path1.empty()){
		hay t1 = path1.front(); 
		hay t2 = path2.front(); 
		path1.pop(); path2.pop(); 
		if (dest(t1) && dest(t2)){ //found minimum path
			return t1.dist; 
		}
		cout << "t1: " << t1.x << " " << t1.y << " " << t1.dir << " " << t1.dist << endl; 
		cout << "t2: " << t2.x << " " << t2.y << " " << t2.dir << " " << t2.dist << endl; 
		//otherwise dont listen 
		if (dest(t1)){
			t1.dist++; 
			path1.push(t1); 
			t1.dist--; 
		}
		if (dest(t2)){
			t2.dist++; 
			path2.push(t2); 
			t2.dist--; 
		}
		if (!dest(t1)){ //move cows not at destiniation
		/** First try moving forward **/ 
		int nx = t1.x+dx[t1.dir]; //step forward 
		int ny = t1.y+dy[t1.dir]; 
		if (nx <0 || nx >= N || ny < 0 || ny >= N || !empty[nx][ny]){
			path1.push(make_hay(t1.x, t1.y, t1.dir, t1.dist+1)); 
		}
		else path1.push(make_hay(nx, ny, t1.dir, t1.dist+1)); 

		/** Then change direction left and then right **/ 
		path1.push(make_hay(t1.x, t1.y, (t1.dir+3)%4, t2.dist+1)); 
		path1.push(make_hay(t1.x, t1.y, (t1.dir+1)%4, t2.dist+1)); 
		}
		if (!dest(t2)){
		/** First try moving forward **/ 
		int nx = t2.x+dx[t2.dir]; //step forward 
		int ny = t2.y+dy[t2.dir]; 
		if (nx <0 || nx >= N || ny < 0 || ny >= N || !empty[nx][ny]){
			path2.push(make_hay(t2.x, t2.y, t2.dir, t2.dist+1)); 
		}
		else path2.push(make_hay(nx, ny, t2.dir, t2.dist+1)); 

		/** Then change direction left and then right **/ 
		path2.push(make_hay(t2.x, t2.y, (t2.dir+3)%4, t2.dist+1)); 
		path2.push(make_hay(t2.x, t2.y, (t2.dir+1)%4, t2.dist+1)); 
		}
	}
}

int main() {
	fin >> N; 
	for (int i = N-1; i>=0; i--){
		string temp; 
		fin >> temp; 
		REP(j, 0, N){
			if (temp.at(j) == 'E') empty[i][j] = true; 
			else empty[i][j] = false;  
		}
	}	

	fout << bfs(0,0) -1<< endl; 
}