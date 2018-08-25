/**
	ID: tylerzh1
	PROB: castle
	LANG: C++11
**/ 
#include <fstream>
#include <iostream>

using namespace std; 

ofstream fout("castle.out"); 
ifstream fin("castle.in"); 

int M, N; 
int dx[4] = {0, -1, 0, 1}; 
int dy[4] = {-1, 0, 1, 0}; 
int arrs[50][50]; 
int visit[50][50]; //fill with -1 for unvisit, then fill w/ component
int compSize[2500]; 

void dfs(int comp, int x, int y){ //floodfills component including arrs[x][y]; 
	for (int i = 0; i<4; i++){
		int nx = x+dx[i]; //newx
		int ny = y+dy[i]; //newy
		if ((nx >= 0) && (nx < N) && (ny >= 0) && (ny < M) && //in bounds
			(visit[nx][ny] == -1) &&  //unmarked/unvisited
			((arrs[x][y] & (1 << i)) == 0)){ //no wall 
			compSize[comp]++; 
			visit[nx][ny] = comp; 
			dfs(comp, nx, ny); 
		}
	}
}

int main() {
	fin >> M >> N; 
	for (int i = 0; i<N; i++){
		for (int j = 0; j<M; j++) {
			fin >> arrs[i][j]; 
			visit[i][j] = -1; 
		}
	}

	int numComp = 0; 
	int maxComp = 0; 
	for (int i = 0; i<N; i++){
		for (int j = 0; j<M; j++){
			if (visit[i][j] == -1){
				compSize[numComp] = 1; 
				visit[i][j] = numComp; 
				dfs(numComp, i, j); 
				maxComp = max(maxComp, compSize[numComp]);  //update max
				numComp++; 
			}
		}
	}

	for (int i = 0; i<N; i++){
		for (int j = 0; j<M; j++){
			cout << visit[i][j] << " "; 
		}
		cout << endl; 
	}
	fout << numComp << endl; // output requirements 
	fout << maxComp << endl; 

	int maxA = 0;  //keep area of new boundaires
	int x = -1; 
	int y = -1; // keep position of wall 
	char dir = 'A';  //initialize

	/**Sweep Horizontally to look for wall to break **/ 
	for (int i = 0; i<N; i++){
		for (int j = 0; j<M-1; j++){
			int comp1 = visit[i][j]; 
			int comp2 = visit[i][j+1]; 
			if (comp1 != comp2) { //different components
				if (compSize[comp1]+compSize[comp2] > maxA){ // strictly update
					maxA = compSize[comp1]+compSize[comp2]; 
					x = i; 
					y = j; 
					dir = 'E'; 
				}
				else if (compSize[comp1]+compSize[comp2] == maxA){ //equal in case we need to update south/east
					if (j < y){ 
						x = i; 
						y = j; 
						dir = 'E'; 
					}
					else if (j == y){
						if (i > x){
							x = i; 
							y = j; 
							dir = 'E'; 
						}
					}
				}
			} 
		}
	}

	/**Sweep Vertically **/ 
	for (int j = 0; j<M; j++){
		for (int i = 0; i<N-1; i++){
			int comp1 = visit[i][j]; 
			int comp2 = visit[i+1][j]; 
			if (comp1 != comp2){
				if (compSize[comp1]+compSize[comp2] > maxA){ //strict update
					maxA = compSize[comp1]+compSize[comp2]; 
					x = i+1; 
					y = j; 
					dir = 'N'; 
				}
				else if (compSize[comp1]+compSize[comp2] == maxA){
					if (j < y){
						x = i+1; 
						y = j; 
						dir = 'N'; 
					}
					else if (j == y){
						if (i+1 >= x){
							x = i+1; 
							y = j; 
							dir = 'N'; 
						}
					}
				}
			}
		}
	}
	fout << maxA << endl; 
	fout << x+1 << " " << y+1 << " " << dir << endl; 
}