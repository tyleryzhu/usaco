/**
	ID: tylerzh1
	PROB: cowtour
	LANG: C++11
**/

#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>
#include <string>
#include <set>
#include <cstring>

using namespace std;


ofstream fout("cowtour.out"); 
ifstream fin("cowtour.in"); 

const int INF = 1<<20; 

int N; 
int x[150]; //x values
int y[150]; //y values

double arrs[150][150]; //shortest distances
double far[150]; //distance of the farthest shortest path from point i
double diam[150];

double distance(int i, int j){
    return sqrt( (x[i]-x[j])*(x[i]-x[j])
            +(y[i]-y[j])*(y[i]-y[j]) ); 
}

void printarr(int n, double a[150][150]){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cout << a[i][j] << " "; 
        }
        cout << endl; 
    }
    cout << endl; 
}

int main() {
    fin >> N; 
    for (int i = 0; i < N; i++){
        fin >> x[i] >> y[i]; 
    }
    
    fin.ignore();
    string temp; 
    for (int i = 0; i < N; i++){
        getline(fin, temp); 
        for (int j = 0; j < N; j++){
            arrs[i][j] = (i == j) ? 0 : INF; 
            if (temp.at(j) == '1') arrs[i][j] = distance(i,j); 
        }
    }
    
    //Floyd
    for (int k = 0; k < N; k++){
        for (int i = 0; i < N; i++){
            for (int j = 0 ; j < N; j++){
                if (arrs[i][j] > arrs[i][k]+arrs[k][j])
                    arrs[i][j] = arrs[i][k]+arrs[k][j]; 
            }
        }
    }

    for (int i = 0; i < N; i++){//just in case?
        arrs[i][i] = INF; 
    }
    
    //Fill Far & diams
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            if (arrs[i][j] < INF) {
                far[i] = max(far[i], arrs[i][j]); 
            }
        }
    }

    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            if (arrs[i][j] < INF) {
                diam[i] = max(diam[i], far[j]);
            }
        }
    }
    
    double ans = INF-1; 
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            if (i != j && arrs[i][j] == INF) {
                double cross = far[i] + distance(i,j) + far[j]; //connect 2
                double best = max(diam[i], diam[j]); //also check this
                ans = min(ans, max(cross, best)); 
            }
        }
    }
    
    fout << fixed << setprecision(6) << ans << endl; 
  
    return 0; 
}
