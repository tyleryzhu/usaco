/**
	ID: tylerzh1
	PROB: milk3
	LANG: C++11
**/
#include <fstream>
#include <iostream>

using namespace std; 

ofstream fout("milk3.out"); 
ifstream fin("milk3.in"); 

int A,B,C; 
bool mark[21] = {false}; 
bool visit[21][21][21]; 

void dfs(int X, int Y, int Z){ //do this for now, X is jug A, Y is jug B, Z is jug C
	if (visit[X][Y][Z]) return; 
	visit[X][Y][Z] = true; 
	if (X == 0){
		if (mark[Z]) return; //kill
		if (!mark[Z]) mark[Z] = true; 
	}
 	//pour X into Y 
 	if (X+Y <= B) dfs(0, X+Y, Z); 
 	else dfs(X+Y-B, B, Z); //B is full
 	//pour X into Z 
 	if (X+Z <= C) dfs(0, Y, X+Z); 
 	else dfs(X+Z-C, Y, C);  //C is full 
 	//pour Y into X
 	if (Y+X <= A) dfs(Y+X, 0, Z); 
 	else dfs(A, X+Y-A, Z); 
 	//pour Y into Z 
 	if (Y+Z <= C) dfs(X, 0, Y+Z); 
 	else dfs(X, Y+Z-C, C); 
 	//pour Z into X
 	if (Z+X <= A) dfs(Z+X, Y, 0); 
 	else dfs(A, Y, Z+X-A); 
 	//pour Z into Y
 	if (Z+Y <= B) dfs(X, Z+Y, 0); 
 	else dfs(X, B, Z+Y-B); 
}

int main() {
	fin >> A >> B >> C; 
	for (int i = 0; i<= A; i++){
		for (int j = 0; j<=B; j++){
			for (int k = 0; k<= C; k++){
				visit[i][j][k] = false; 
			}
		}
	}
	dfs(0,0,C); 
	for (int i = 0; i< C; i++){
		if (mark[i]) fout << i << " "; 
	}
	fout << C << endl; 
}