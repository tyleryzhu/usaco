#include <iostream>
#include <algorithm> 

using namespace std; 

struct cows{
	long p, c; 
}; 

const int maxN = 100010; 
long N, B; 
cows price[maxN]; 

bool comp(cows a, cows b){
	return a.p < b.p; 
}

int main() {
	cin >> N >> B; 
	for (int i = 0; i< N; i++){
		cin >> price[i].p >> price[i].c; 
	}	
	sort(price, price+N, comp); 
	long ct = 0; 
	for (int i = 0; i< N; i++){
		long hi = B/price[i].p;  
		if (hi >= price[i].c){ //enough allowance to use everything
			ct += price[i].c; 
			B -= price[i].p * price[i].c; 
		}
		else {
			ct += hi; 
			B -= price[i].p * hi; 
		}
	}
	cout << ct << endl; 
}