/**
	ID: tylerzh1
	PROB: sprime
	LANG: C++11
**/
#include <iostream>
#include <fstream>

using namespace std;

//ofstream fout("sprime.out");
//ifstream fin("sprime.in");

int N;

bool is_prime(int n){
	for (int i = 2; i*i<=n; i++){
		if (n%i == 0) return false;
	}
	return true;
}

void dfs(int depth, int num){
	if (depth == N){
		cout << num << endl;
		return;
	}
	num*= 10;
	for (int i = 0; i< 10; i++){
		if (is_prime(num+i)) dfs(depth+1,num+i); 
	}
}

int main() {
	cin >> N;
	dfs(1, 2);
	dfs(1, 3);
	dfs(1, 5);
	dfs(1, 7);
}
