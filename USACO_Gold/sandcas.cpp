#include <iostream>
#include <algorithm> 

using namespace std; 

const int maxN = 25010; 
int N, X, Y; 
int o[maxN]; 
int n[maxN]; 

bool comp(int a, int b){
	return a < b; 
}

int main() {
	cin >> N >> X >> Y; 
	for (int i = 0; i<N; i++){
		cin >> o[i] >> n[i]; 
	}	
	sort(o, o+N, comp); 
	sort(n, n+N, comp); 
	int curr = 0; 
	for (int i = 0; i<N; i++){
		int temp = o[i] - n[i]; 
		if (temp > 0){
			curr += temp*Y; 
		}
		else {
			curr -= temp*X; 
		}
	}
	cout << curr << endl; 
}