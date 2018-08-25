/**
	ID: tylerzh1
	PROB: preface
	LANG: C++11
**/ 
#include <fstream>
#include <iostream>
#include <string> 
#include <cmath> 

using namespace std; 

ofstream fout("preface.out"); 
ifstream fin("preface.in"); 

int N; 
int vals[500] = {0}; 

int power(int n){
	int temp = 1; 
	while ( n > 0) {
		temp *= 10; 
		n--; 
	}
	return temp; 
}

void update(string trans){
	for (int i = 0; i<trans.size(); i++){
		vals[trans.at(i)]++; 
	}
}

string roman(int num){
	string temp = ""; 
	for (int i = 3; i>= 0; i--){ //iterate on the power of 10
		int place = (num % power(i+1)); //gets the 
		place /= power(i); 
		if (place == 0) continue;  //no digits in this place 
		if (place == 9) {
			//look at previous 
			if (i == 0){
				temp += "IX"; 
			}
			else if (i == 1){
				temp += "XC"; 
			}
			else if (i == 2){
				temp += "CM"; 
			}
			continue; 
		}
		if (place == 4) {
			if (i == 0)
				temp += "IV"; 
			else if (i == 1) 
				temp += "XL"; 
			else if (i == 2)
				temp += "CD"; 
			continue; 
		}
		if (place >= 5){
			if (i == 0) temp += "V"; 
			if (i == 1) temp += "L"; 
			if (i == 2) temp += "D"; 
			place -= 5; 
		}
		if (place < 5){ //place == 1,2,3 or 
			for (int j = 0; j<place; j++){
				if (i == 0) temp += "I"; 
				else if (i == 1) temp += "X"; 
				else if (i == 2) temp += "C"; 
				else if (i == 3) temp += "M"; 
			}
		}
	}
	return temp; 
}

int main() {
	fin >> N; 	
	for (int i = 1; i<= N; i++){
		string k = roman(i);
		cout << k << endl; 
		update(k); 	
	}
	int arrs[7] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'}; 
	for (int i = 0; i<7; i++){
		if (vals[arrs[i]] != 0) {
			fout << char(arrs[i]) << " " << vals[arrs[i]] << endl; 
		}
	}
}