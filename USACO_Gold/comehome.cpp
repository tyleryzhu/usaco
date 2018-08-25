#include <iostream>

using namespace std; 
int P; 

int mat[125][125]; 

int main() {
	cin >> P; 
	for (int i= 'A'; i< 'z'+1; i++){			//initialize all values to infinity except for diagonal 
		for (int j = 'A'; j<'z'+1; j++){
			mat[i][j] = 1 << 20; 
			if (i == j) mat[i][j] = 0; 
		}
	}

	for (int i= 0 ; i<P; i++){
		char start, end;
		int temp;  
		cin >> start >> end >> temp; 
		if (mat[start][end] > temp) {
			mat[start][end] = temp;  // if writen value is greater than potential value overwrite 
			mat[end][start] = temp; 
		}	
	}

	//Floyd-Warshall
	for (int k = 'A'; k < 'z'+1; k++){
		for (int i = 'A'; i < 'z'+1; i++){
			for (int j = 'A'; j< 'z'+1; j++){
				// check for conditions
				if ((mat[i][k] > 0) && (mat[k][j]>0) ){ // stopping condition
					if (mat[i][j] > mat[i][k] + mat[k][j]){
						mat[i][j] = mat[i][k]+mat[k][j]; 
					}
				}

			}
		}
	}

	char best; 
	int dist = 1<<20; 

	for (int i = 'A'; i<'Z'; i++){
		if (mat[i]['Z'] > 0){ // if distance is more than 0
			if ( mat[i]['Z'] < dist){
				dist = mat[i]['Z']; 
				best = i; 
			}
		}
	}
	cout << best << " " << dist << endl; 

}