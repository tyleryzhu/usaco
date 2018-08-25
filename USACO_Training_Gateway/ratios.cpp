/**
	ID: tylerzh1
	PROB: ratios
	LANG: C++14
**/

#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

using namespace std;

ofstream fout("ratios.out"); 
ifstream fin("ratios.in"); 

vector<double> gauss(vector< vector<double> > A) {
    int n = A.size();

    for (int i=0; i<n; i++) {
        // Search for maximum in this column
        double maxEl = abs(A[i][i]);
        int maxRow = i;
        for (int k=i+1; k<n; k++) {
            if (abs(A[k][i]) > maxEl) {
                maxEl = abs(A[k][i]);
                maxRow = k;
            }
        }

        // Swap maximum row with current row (column by column)
        for (int k=i; k<n+1;k++) {
            double tmp = A[maxRow][k];
            A[maxRow][k] = A[i][k];
            A[i][k] = tmp;
        }

        // Make all rows below this one 0 in current column
        for (int k=i+1; k<n; k++) {
            double c = -A[k][i]/A[i][i];
            for (int j=i; j<n+1; j++) {
                if (i==j) {
                    A[k][j] = 0;
                } else {
                    A[k][j] += c * A[i][j];
                }
            }
        }
    }

    // Solve equation Ax=b for an upper triangular matrix A
    vector<double> x(n);
    for (int i=n-1; i>=0; i--) {
        x[i] = A[i][n]/A[i][i];
        for (int k=i-1;k>=0; k--) {
            A[k][n] -= A[k][i] * x[i];
        }
    }
    return x;
}

int main() {
    int n = 3; 

    vector<double> line(n+1,0);
    vector< vector<double> > A(n,line);

    // Read input data
    for (int i=0; i<n; i++) {
        cin >> A[i][n];
    }

    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cin >> A[j][i];
        }
    }

    // Calculate solution
    vector<double> x(n);
    x = gauss(A);
    cout << x[0] << "" << x[1] << " " << x[2] << endl; 
    //no sol
    if ( (x[0] <= 0) && (x[1] <= 0) && (x[2] <= 0)) {
        x[0] *= -1; 
        x[1] *= -1; 
        x[2] *= -1; 
    }
    if ( (x[0] < 0) || (x[1] < 0) || (x[2] < 0) ) {
        cout << "NONE" << endl; 
        return 0; 
    }

    // Integer-ize results
    int m = 1; 
    while (true) {
        bool god = false; 
        for (int i = 0; i < n; i++){
            if (x[i] < 1e-5) x[i] = 0; 
            if ( (x[i] > 1e-3)  && (abs(x[i]*m-int(x[i]*m+0.5)) > 1e-3) ) break; 
            if (i == n-1) god = true; 
        }
        if (god) break; 
        m++; 
    }

    // Print result
    for (int i=0; i<n; i++) {
        cout << (int) m*x[i] << " ";
    }
    cout << m << endl; 
}

