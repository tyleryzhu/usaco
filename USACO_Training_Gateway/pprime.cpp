/**
	ID: tylerzh1
	PROB: pprime
	LANG: C++11 
**/ 
#include <iostream>
#include <fstream>
#include <string> 
#include <cmath> 

using namespace std; 

ofstream fout("pprime.out"); 
ifstream fin("pprime.in"); 

const int maxP = 600000; 
int A, B; 
int numP; 
int num[15]; 
int primes[maxP]; //list of primes

bool prime(int n){
	for (int i = 2; i*i <=n; i++){
		if (n%i == 0) return false; 
	}
	return true; 
}

bool is_prime(int n){
	for (int i = 0; i<numP; i++){
		if (n%primes[i] == 0) return false; 
	}
	return true; 
}

void palind(int dig, int depth){ //generates palindromes of length dig
	if (dig == 1){
		if ( A <= 5 && 5 <= B) fout << 5 << endl; 
		if ( A <= 7 && 7 <= B) fout << 7 << endl; 
		return; 
	}
	if (depth == dig){
		int temp = 0; 
		for (int i = 0; i<dig; i++){
			temp += pow(10,i)*num[i]; 
		}
		if (temp >= A && temp <= B && prime(temp)) fout << temp << endl; 
		return; 
	}

	if (depth == 0){
		for (int i = 1; i<10; i++){
			num[0] = i; 
			num[dig-1] = i; 
			palind(dig, 2); 
		}
	}
	else {
		if (depth == dig-1){ //middle digit
			for (int i = 0; i<10; i++){
				num[dig/2] = i; 
				palind(dig, depth+1); 
			}
		}
		else {
			for (int i = 0; i<10; i++){
				num[depth/2] = i; 
				num[dig - (depth/2) - 1] = i; 
				palind(dig, depth+2); 
			}
		}
	}
}

int main() {
	numP = 0; 
	fin >> A >> B; 
	cerr << "Test Program " << endl; 
	for (int i = 2; i*i <= B; i++){ //generate primes up to sqrt(B);  
		if (prime(i)){
			primes[numP] = i; 
			numP++; 
		}	
	}
	int digA = 0; 
	int digB = 0; 
	int temp = A; 
	while (temp > 0){
		temp /= 10; 
		digA++; 
	}
	temp = B; 
	while (temp > 0){
		temp /= 10; 
		digB ++; 
	}
	cerr << "Input okay" << endl; 
	for (int i = digA; i<= digB; i++){
		palind(i,0); 
	}
}