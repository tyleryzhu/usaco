#include <iostream>
#include <fstream> 
#include <cmath>
#include <algorithm>
#include <vector> 

using namespace std; 

ofstream fout("nocross.out"); 
ifstream fin("nocross.in"); 

/** 

struct cow{
	int id, ind; 
	cow () {}; 
	cow (int x, int y) : id(x), ind(y) {}	 //constructor
};

int const maxN = 100010; 
int const last = 200000; 
int N; 
int dp[maxN]; 
cow A[maxN]; 
cow B[maxN];
vector<pair<int, int> > matches;  

bool comp(cow a, cow b){
	return a.id < b.id; 
}

bool matchSort(pair<int, int> a, pair<int, int> b){
	return a < b; 
}
ostream &operator<<(ostream &os, const cow &p) {
	os << "(id: " << p.id << ",ind: " << p.ind << ")";
}
void printA(int k){
	cout << "Printing A" << endl; 
	for (int i = 0; i<= k; i++){
		cout << A[i]; 
		cout << " "; 
	}
	cout << endl; 
}

void printB(int k){
	cout << "Printing B" << endl; 
	for (int i = 0; i<= k; i++){
		cout << B[i]; 
		cout << " "; 
	}
	cout << endl; 
}


void printM(int k){
	for (int i = 0; i<= k; i++){
		cout << "(" << matches[i].first << ", " << matches[i].second << ")\n";
	}
}

void find_match(){
	sort(A, A+N+1, comp); //sort ascending but keep their indicies to make a matches array
	sort(B, B+N+1, comp); 
//	printA(N); 
//	printB(N); 
	int i = 1; int j = 1; 
	//Increment i, but change j to be within 4 of A[i].id
	while (i <= N && j <= N){ //could be < vs <=, double check 
		if (A[i].id < B[j].id - 4){
			i++; 
		}
		else if (A[i].id > B[j].id + 4){ //4 is to account for friendly
			j++;
		}
		else { //matching
			int jj = j; 
				while (jj <= N && abs(B[jj].id - A[i].id) <= 4) {
					matches.push_back(make_pair(A[i].ind, B[jj].ind)); 
					jj++; 
				}
				i++;
//			j = jj; 
		}
	}
//	printM(matches.size()-1); 
}

int lcs(){
	int K = matches.size()-1; 
	matches.push_back(make_pair(N+1, N+1)); 
	sort(matches.begin(), matches.end(), matchSort); 

	for (int k = 1; k <= K+1; k++){
		pair<int, int> temp = matches[k]; 
		dp[k] = 1; 
		for (int l = 1; l < k; l++){
			if (matches[l].first < temp.first && matches[l].second < temp.second){
				dp[k] = max(dp[k], 1 + dp[l]); 
			}
		}
	}
	return dp[K+1]-1; 
}

int main() {
	fin >> N; 	
	A[0] = cow(0,0); 
	for (int i = 1; i<= N; i++){
		fin >> A[i].id; 
		A[i].ind = i; 
	}
	B[0] = cow(0,0); 
	for (int i = 1; i<= N; i++){
		fin >> B[i].id; 
		B[i].ind = i; 
	}
	matches.push_back(make_pair(0,0)); 
	find_match(); 
	fout << lcs() << endl; 
}
**/


int const maxN = 100010; 
int dp[maxN][2]; 
int cross[2][maxN]; 

bool friendly(int i, int j){
	if (abs(cross[0][i] - cross[1][j]) <= 4) return true; 
	else return false; 
}

int main() {
	int N; 
	fin >> N; 	
	for (int i = 1; i<= N; i++){
		fin >> cross[0][i]; 
	}
	for (int i = 1; i<= N; i++){
		fin >> cross[1][i]; 
	}

	for (int j = 1; j<= N; j++){
		for (int i = 1; i<= N; i++){
			if (j % 2 == 1){
				if (friendly(i, j)){
					dp[i][1] = 1 + dp[i-1][0]; 
				}
				else dp[i][1] = max(dp[i-1][1], dp[i][0]); 
			}
			else { //j iieven
				if (friendly(i, j)){
					dp[i][0] = 1 + dp[i-1][1]; 
				}
				else dp[i][0] = max(dp[i-1][0], dp[i][1]); 
			}
		}
	}
	fout << dp[N][N%2] << endl; 
}