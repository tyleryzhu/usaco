#include <iostream>
#include <cstring> 

using namespace std; 

int N, K, num; 
const int maxN = 20; 
const int maxNum = 400010; 
int vals[maxN]; 
bool arrs[maxNum];  //use sliding window 

int main() {
	memset(arrs, false, sizeof(arrs)); 
	int largest = 0; 
	cin >> K >> N; 
	for (int i = 1; i<= N; i++){
	 	cin >> vals[i]; 
	 	largest = max(largest, vals[i]); 
	}
	num = largest * K; //maximum value 
	//Base Case: first column is all true;, in this case just the first value 
	arrs[0] = true; 
	for (int j = 1; j <= K; j++){//iterate on the # of coins used 
		for (int i = num; i >= 1; i--){
			for (int v = 1; v <= N; v++){ //go through all voin values 
				if (i >= vals[v]) { //to make sure not negative 
					if (arrs[i-vals[v]]) arrs[i] = true; //if prev value is true then so is this one 
				}
			}
		}
	}	

	/** Find the longest occurence of continuous stuff **/ 
	int longest = 0; 
	int curr = 0; 
	for (int i = 1; i<= num; i++){
		if (arrs[i]){
			curr++; 
			longest = max(longest, curr); 
		}
		else { //value i not attainable 
			curr = 0; 
		}
	}
	cout << longest << endl; 
}