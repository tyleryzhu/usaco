#include <iostream>
#include <string> 

using namespace std; 

string s1, s2; 
const int maxL = 1010; 
int lcs[maxL][maxL]; 

int main() {
	cin >> s1 >> s2; 
	int best = 0; 
	for (int i = 0; i< s1.size(); i++){
		for (int j = 0; j< s2.size(); j++){
			if (s1.at(i)== s2.at(j)) lcs[i+1][j+1] = 1+lcs[i][j]; 
			best = max(best, lcs[i+1][j+1]); 
		}
	}
	cout << best << endl; 
}