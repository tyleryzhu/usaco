/**
	ID: tylerzh1
	PROB: lamps
	LANG: C++11
**/ 
#include <fstream>
#include <iostream>
#include <algorithm>
#include <string> 

using namespace std; 

ofstream fout("lamps.out"); 
ifstream fin("lamps.in"); 

int N, C; 
int onC, offC; //on/off counters; 
int lamps[110]; 
int on[110]; 
int off[110]; 
string sol[100]; 
bool choice[4] = {false}; 
int solEx = 0; 

void flip(int num){
	lamps[num]++; 
	lamps[num] %= 2; 
}

void dfs(int depth, int sum){
	if (depth == 4){ //process
		for (int i = 1; i<=N; i++){ //reset lamps
			lamps[i] = 1;  //initialize as ON
		}
		if (sum%2 != C%2) return; 
		//create according to choices
		if (choice[0]){ //flip all 
			for (int i = 1; i<=N; i++){
				flip(i); 
			}
		}
		if (choice[1]){ //flip odd 
			for (int i = 0; 2*i+1 <= N; i++){
				flip(2*i+1); 
			}
		}
		if (choice[2]){
			for (int i = 1; 2*i <= N; i++){
				flip(2*i); 
			}
		}
		if (choice[3]){
			for (int i = 0; 3*i+1 <= N; i++){
				flip(3*i+1); 
			}
		}
		string temp = ""; 
		for (int i = 1; i<=N; i++){
			if (lamps[i] == 0) temp += "0"; 
			else temp += "1"; 
		}
/**		for (int i = 0; i<4; i++){
			cout << ((choice[i]) ? "yes " : "no "); 
		}
		cout << endl; 
		cout << temp << endl; 
**/		//check 
		for (int i = 0; i<onC; i++){
			if (lamps[on[i]] == 0) return; 
		}
		for (int j = 0; j<offC; j++){
			if (lamps[off[j]] == 1) return;
		}
		//good
		if (solEx == 0){
			sol[solEx] = temp; 
			solEx++; 
		}
		for (int i = 0; i<solEx; i++){
			if (sol[i].compare(temp) == 0) return; 
			if ( i == solEx-1) {
				sol[solEx] = temp; 
				solEx++; 
			}
		}
		return; 
	}
	choice[depth] = true; 
	dfs(depth+1, sum+1); 
	choice[depth] = false; 
	dfs(depth+1, sum); 
}

int main() {
	fin >> N >> C; 
	onC = 0; 
	offC = 0; 
	int temp; 
	fin >> temp; 
	while (temp != -1){
		on[onC] = temp; 
		onC++; 
		fin >> temp;
	}
	fin >> temp; 
	while (temp != -1){
		off[offC] = temp; 
		offC++; 
		fin >> temp; 
	}
 
	//deal with C = 0 mod4 as a special case 
	if (C%4 == 0){
		if (offC == 0){ //one solution is when nothing happesn basically 
			string temper = ""; 
			for (int i = 0; i<N; i++){
				temper += "1"; 
			}
			sol[solEx] = temper; 
			solEx++; 	
		}
	}
	if (C > 0 && (C%4 == 0)) C = 4; 
	if (C>0) dfs(0,0); 
	if (solEx == 0) fout << "IMPOSSIBLE" << endl; 
	else {
		sort(sol, sol+solEx); 
		for (int i = 0; i<solEx; i++){
			fout << sol[i] << endl; 
		}
	}
}