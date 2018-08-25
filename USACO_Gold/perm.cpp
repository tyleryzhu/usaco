#include <iostream>

using namespace std;

#define REP(i, a, b) \
	for (int i = int(a); i < int(b); i++)
	
int N, sum; 
int arrs[100][100]; 
int choice[100]; 
bool mark[100]; 
int num[100]; //array to keep values form input

void process() {
	REP(i, 0, N){
		//cout << num[choice[i]] << " "; 
	}	
	//cout << endl; 
}

void perm(int k){
	if (k == N) process(); 
	REP(i, 0, N){
		if (!mark[i]){
			choice[k] = i; 
			mark[i] = true; 
			perm(k+1); 
			mark[i] = false; 
		}
	}
}

int main() {	
	cin >> N; 
	REP(i, 0, N){
		num[i] = i+1; 
	}
	perm(0); 
}