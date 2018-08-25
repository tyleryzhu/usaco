/**
	ID: tylerzh1
	PROB: ttwo
	LANG: C++11
**/
/** KEEP YOUR HEAD STRAIGHT ABOUT MATRICES AND UP/DOWN **/
#include <iostream>
#include <fstream>
#include <queue>
#include <string> 

using namespace std; 

ofstream fout("ttwo.out"); 
ifstream fin("ttwo.in"); 

const int maxN = 10; 
int grid[maxN][maxN]; 
int fv, fh, fd, cv, ch, cd, dist; 
bool visit[maxN][maxN][4][maxN][maxN][4];  //keep track of values,
int dh[4] = {0,1, 0, -1};   //must be N, E, S, W
int dv[4] = {-1,0, 1, 0}; 

bool in_bounds(int v, int h){
	if (h < 0 || h > 9 || v < 0 || v > 9) return false; 
	if (grid[v][h] == -1) return false; 
	return true; 
}

void print_state(){
	cout << "FJ: " << fv << " " << fh << " " << fd << endl; 
	cout << "Cows: " << cv << " " << ch << " " << cd << endl; 
	cout << "Dist: " << dist << endl; 
}

int main() {
	for (int i = 0; i< 10; i++){
		string temp; 
		fin >> temp; 
		for (int j = 0; j< 10; j++){
			if (temp.at(j) == '*'){ //if obstacle
				grid[i][j] = -1; 
			}
			else if (temp.at(j) == 'F'){
				fv = i; 
				fh = j; 
				fd = 0; 
			}
			else if (temp.at(j) == 'C'){ // Cow's position
				cv = i; 
				ch = j; 
				cd = 0; //North
			}
		}
	}		
	while ((ch != fh) || (cv != fv)){
		if (visit[cv][ch][cd][fv][fh][fd]){
			fout << 0 << endl; //if already visited this state, means infinite loop
			return 0; 
		}
		visit[cv][ch][cd][fv][fh][fd] = true;  //visited this state
		// move Cows forward 
		if (!in_bounds(cv+dv[cd], ch+dh[cd])){ //next step not in bounds
			cd++; //move direction up
			cd %= 4; 
		}
		else {
			ch += dh[cd]; 
			cv += dv[cd]; 
		}
		// move FJ forward
		if (!in_bounds(fv+dv[fd], fh+dh[fd])){
			fd++; 
			fd %= 4; 
		}
		else {
			fh += dh[fd]; 
			fv += dv[fd]; 
		}
		dist++; 
//		print_state(); 
	}
	fout << dist << endl; 
}
