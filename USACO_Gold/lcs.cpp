/**
#include <iostream>
#include <string> 

using namespace std; 

string s1, s2; 
const int maxL = 1010; 
int lcs[maxL][maxL]; 

int main() {
	cin >> s1 >> s2; 
	for (int i = 0; i< s1.size(); i++){
		for (int j = 0; j< s2.size(); j++){
			lcs[i+1][j+1] = max(lcs[i+1][j], lcs[i][j+1]); 
			if (s1.at(i)== s2.at(j)) lcs[i+1][j+1] = max(lcs[i+1][j+1], 1+lcs[i][j]); 
		}
	}
	cout << lcs[s1.size()][s2.size()] << endl; 
}

**/
//pretty fast implement
#include <iostream>
#include <fstream> 
#include <cmath>
#include <algorithm>
#include <vector> 

using namespace std; 

ofstream fout("nocross.out"); 
ifstream fin("nocross.in"); 

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

void find_match(){
	sort(A, A+N+1, comp); //sort ascending but keep their indicies to make a matches array
	sort(B, B+N+1, comp); 
//	printA(N); 
//	printB(N); 
	int i = 1; int j = 1; 
	while (i <= N && j <= N){ //could be < vs <=, double check 
		if (A[i].id < B[j].id){
			i++; 
		}
		else if (A[i].id > B[j].id){
			j++;
		}
		else { //matching
			int ii = i; 
			int jj = j; 
			while (A[ii].id == A[i].id){
				while (B[jj].id == B[j].id){
					matches.push_back(make_pair(A[ii].ind, B[jj].ind)); 
					jj++; 
				}
				ii++; 
			}
			i = ii; 
			j = jj; 
		}
	}
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
	cout << lcs() << endl; 
}