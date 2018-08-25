#include <iostream>
#include <fstream>

using namespace std; 

ofstream fout("checklist.out"); 
ifstream fin("checklist.in"); 

#define REP(i, a, b) \
	for (int i = int(a); i<int(b); i++)
const int INF = 1 << 29; 
const int maxH = 1010; 
const int maxG = 1010; 

long dp[maxH][maxG][2]; //char is what FJ is on right now, 0 is H 1 is G
int H, G; 
int arrs[maxH+maxG][maxH+maxG]; 
int xH[maxH]; 
int yH[maxH]; 
int xG[maxG]; 
int yG[maxG]; 

long energy(int h, int g, int k1, int k2){ //k1,k2  mean that h is of type k1, g is of type k2 moving to g from h
	if (k1 == 0){
		if (k2 == 0){ //horse to horse
			return ((xH[g]-xH[h])*(xH[g]-xH[h])+(yH[g]-yH[h])*(yH[g]-yH[h])); 
		}
		else { //  horse to goat
			return ((xG[g]-xH[h])*(xG[g]-xH[h])+(yG[g]-yH[h])*(yG[g]-yH[h])); 
		}
	}
	else { //from goat
		if (k2 == 0){ //goat to horse
			return ((xH[g]-xG[h])*(xH[g]-xG[h])+(yH[g]-yG[h])*(yH[g]-yG[h])); 
		}
		else {  //goat to goat
			return ((xG[g]-xG[h])*(xG[g]-xG[h])+(yG[g]-yG[h])*(yG[g]-yG[h]));  
		}
	}
	return -1; 
}

long solve(int h, int g, int k){ //solve (h,g,k)
//	cout << h << " " << g << " " << k << endl; 
	if (dp[h][g][k] < INF) return dp[h][g][k]; 
	if (h == 1 && k == 0) return dp[h][g][k]; //if move on horse
	if (g == 0 && k == 1) return dp[h][g][k]; //can't happen 
	if ( k == 0) { //want ot end at horse
		long dist1 = solve(h-1,g,0) + energy(h-1, h, 0, 0); // horse to horse
		long dist2 = solve(h-1,g,1) + energy(g, h, 1, 0); //goat to horse
		dp[h][g][k] = min(dist1, dist2); 
//		cout << h << " " << g << " " << k << " " << dist1 << " " << dist2 << endl; 
	}
	else { // k == 1, want to end at goat
		long dist1 = solve(h, g-1, 0) + energy(h, g, 0, 1);  //horse to goat
		long dist2 = solve(h, g-1, 1) + energy(g-1, g, 1, 1); //goat to goat
//		cout << h << " " << g << " " << k << " " << dist1 << " " << dist2 << endl; 
		dp[h][g][k] = min(dist1, dist2); 
	}
//	cout << h << " "<< g << " " << k << " " << dp[h][g][k] << endl;  
	return dp[h][g][k]; 
}

int main() {
	fin >> H >> G; 
	REP(i, 1, H+1){
		fin >> xH[i] >> yH[i]; 
	}
	REP(i, 1, G+1){
		fin >> xG[i] >> yG[i]; 
	}
	
	REP(i, 1, H+1){
		REP(j, 0, G+1){
			dp[i][j][0] = INF; 
			dp[i][j][1] = INF; 
		}
	}
	dp[1][0][0] = 0; 
	
	fout << solve(H, G, 0) << endl;
}	