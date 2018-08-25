#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

#define REP(i,a,b) \
	for (int i = int(a); i < int(b); i++)


int N;
int arrs[50000]; 
int darn[50000]; 
int bessie[50000]; 

int main() {
	ofstream fout("cardgame.out");
	ifstream fin("cardgame.in"); 
	fin >> N; 
	int total = 0; 
	REP(i,0,N){
		fin >> arrs[i]; 
		darn[i] = arrs[i]; 
	}
	sort(arrs, arrs+(N/2)); 
	sort(arrs+(N/2), arrs+N); 
	sort(darn, darn+N); 

	int counter = 0; 
	int counter_bes = 0; 
	REP(i,1,2*N+1){				//finds bessie's cards
		if (i == darn[counter] && (counter < N)) counter++; 
		else {
			bessie[counter_bes] = i; 
			counter_bes++; 
		}	
	}
	counter = N/2; //use to keep counter for bessie's cards
	REP(i, 0, N/2){ //high card
		if (counter == N){
			break; 
		}

		if (arrs[i] < bessie[counter]){
			total++; 
			counter++; 
		} 
		else { //  
			while (counter < N && arrs[i] > bessie[counter]){
				counter++; 
			}
			if (counter == N){ 
				break; 
			}
			total++; 
			counter++; 
		}
	}
	counter = 0;  //keep counter for bessie's low cards 
	REP(i, N/2, N){ //lowcard
		if (counter == N/2) break; 

		if (arrs[i] > bessie[counter]){
			total++;
			counter++; 
		}
		else {
			while (i < N && arrs[i] < bessie[counter]){
				i++; 
			}
			if (i == N) break; 
			total++; 
			counter++; 
		}
	}
	fout << total << endl; 
}
