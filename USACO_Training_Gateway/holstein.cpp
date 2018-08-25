/**
	ID: tylerzh1
	PROB: holstein
	LANG: C++11 
**/ 
#include <fstream>
#include <iostream>

using namespace std;

ofstream fout("holstein.out"); 
ifstream fin("holstein.in"); 

int v, m;  // m should be the # of diff feeds, aka g in this problem, v is # of diff vits.
int arrs[15][25];// [i][0-24] will keep the vitamin#'s for feed #i+1
int cows[25];
bool subsets[15]; // feeds are out of g
int sums[25] = {0};
bool ans[15] = {0};
int counter = 0;
int num = 0;
bool good = true;

void process(int e){
	if ( counter != 1){
	for (int i =0; i<m; i++){
		if (subsets[i]) { //if including in the subset
			for (int j = 0; j<v; j++){ //
				sums[j] += arrs[i][j];
			}
		}
	}

	for (int i = 0; i<v; i++){  // check if nutrition min is met
		if ( cows[i] > sums[i]) good = false;
	}

	if (good){
		for (int i =0; i<m; i++){
			ans[i] = subsets[i];
		}
		counter = 1;
	}
	else{
		for (int i= 0; i<v; i++){
			sums[i] = 0;
		}
	}
	}
	good = true;

}

void fill(int x, int e, int j){ // e is a counter
	if (x == m && e == j){
		process(j);
	}
	else if (x ==m){
		cout << "";
	}
	else if ( e < j){
		subsets[x] = true;
		fill(x+1,e+1, j);
		subsets[x] = false;
		fill(x+1,e, j);
	}

	else {
		subsets[x] = false;
		fill(x+1,e, j);
	}
}

int main(void) {
	fin >> v;
	for (int i =0; i<v; i++){
		fin >> cows[i];
	}

	fin >> m;
	for (int i= 0; i<m; i++){
		for (int j =0; j<v; j++){
			fin >> arrs[i][j]; // fully stored now
		} // row [i] is the ith feed
	}


	for (int j = 1; j<m+1; j++){
		if (counter == 1) break;
		fill(0,0, j);
	}

	int count = 0;
	for (int i =0; i<m; i++){
		if (ans[i]) count++;
	}
	fout << count << " ";
	bool printed = false; 
	for (int i =0; i<m; i++){
			if (ans[i] && !printed) {
				fout << i+1;
				printed = true; 
			}
			else if (ans[i]) fout << " " << i+1; 
	}
	fout << endl; 
	return 0;
}