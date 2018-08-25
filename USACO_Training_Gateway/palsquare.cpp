/**
	ID: tylerzh1
	PROB: palsquare
	LANG: C++11 
**/
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm> 

using namespace std; 

ofstream fout("palsquare.out");
ifstream fin("palsquare.in"); 
int B; 

string palind(int n){
	int temp = n*n; 
	string conv = ""; 
	while (temp > 0){
		char last; 
		if ((temp%B) > 9) {
			last = (temp%B)-10 + 'A'; 
		}
		else {
			last = (temp%B) + '0'; 
		}
		conv += last; 
		temp/= B; 
	}
	int len = conv.length()-1; 
	for (int i = 0; i<len; i++){
		if (conv.at(i) != conv.at(len)) return ""; 
		len--; 
	}
	string pal = ""; 
	while ( n > 0){
		char last; 
		if ((n%B) > 9) {
			last = (n%B)-10 + 'A'; 
		}
		else {
			last = (n%B) + '0'; 
		}
		pal += last; 
		n /= B; 
	}
	reverse(pal.begin(), pal.end()); 
	fout << pal << " " << conv << endl; 
	return conv; 
}

int main() {
	fin >> B; 
	for (int i = 1; i<301; i++){
		palind(i); 
	}	
	return 0; 
}
