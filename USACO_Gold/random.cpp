#include <iostream> 

using namespace std; 

int larg_div(int N){
	int x = 2; 
	while (x <= N){
		if ( (N % x) == 0) N /= x; 
		else x++; 
	}	
	return x; 
}

int main() {
	int N; 
	cin >> N; 

	cout << larg_div(N) << endl; 
}