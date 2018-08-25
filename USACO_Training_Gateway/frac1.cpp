/**
	ID: tylerzh1
	PROB: frac1
	LANG: C++11
**/ 	
#include <fstream>
#include <iostream>
#include <algorithm> 

using namespace std; 

ofstream fout("frac1.out"); 
ifstream fin("frac1.in"); 

int numPrime; 
int primes[50]; 

bool coprime(int a, int b){
	for (int i = 0; i<numPrime; i++){
		if ((a%primes[i] == 0) && (b%primes[i] == 0)) return false; 
	}
	return true; 
}

struct Fraction{
	int num, den; 
}; 

bool comp(Fraction a, Fraction b){
	return a.num*b.den < b.num* a.den; 
}

int N; 
Fraction arrs[160*160]; 

int main() {
	fin >> N; 
	//fill out primes
	numPrime = 2; 
	primes[0] = 2; 
	primes[1] = 3; 
	for (int i = 5; i< N; i++){
		for (int j = 0; j<numPrime; j++){
			if (i % primes[j] == 0) break; 
			else if (j == numPrime-1) {
				primes[numPrime] = i; 
				numPrime++; 
			}
		}
	}
	int ct = 0; 
	for (int bot = 1; bot<=N; bot++){
		for (int top = 1; top < bot; top++){
			if (coprime(top, bot)){
				arrs[ct].num = top; 
				arrs[ct].den = bot; 
				ct++; 
			}
		}
	}
	sort(arrs, arrs+ct, comp); 
	fout << "0/1" << endl; 
	for (int i = 0; i<ct; i++){
		int a = arrs[i].num;
		int b = arrs[i].den; 
		fout << a << "/" << b << endl; 
	}
	fout << "1/1" << endl;
}