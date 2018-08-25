#include <iostream>
#include <stdlib.h> 

using namespace std; 

bool dig(int k){
	while (k > 9){
		k /= 10; 
	}
	if (k % 10 == 1) return true; 
	return false; 
}

int main() {
	int N;
	cin >> N; 
	
	for (int i = 0; i<N; i++){
		int x = 1 << i; 
		if (dig(x)) cout << x << " " << i << endl; 
	}	
}