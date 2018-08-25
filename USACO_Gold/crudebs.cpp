//implementing binary search
#include <iostream>

using namespace std; 

int arrs[1000]; 

int bin_search(int N, int K){
	int lo = 0; 
	int hi = N-1; 
	while ( lo <= hi){
		int  mid = lo + (hi-lo)/2; 
		if (arrs[mid] == K){
			return mid+1; 
		}
		else if (arrs[mid] < K){
			lo = mid+1; 
		}
		else {     // upper bound
			hi = mid-1; 
		}
	}
	return -1; 
}

int main() {
	int N, K; 
	cin >> N >> K;

	for (int i = 0; i<N; i++){
		cin >> arrs[i]; 
	}		

	sort(arrs,arrs+N); 

	cout << bin_search(N,K) << endl; 

}