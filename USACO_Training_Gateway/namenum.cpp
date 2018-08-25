/*
ID: tylerzh1 
LANG: C++11 
TASK: namenum 
*/
#include <fstream>
#include <algorithm>
#include <cmath>
#include <string>
#include <map> 

using namespace std; 

ofstream fout("namenum.out"); 
ifstream fin("namenum.in"); 
ifstream dict("dict.txt"); 

map<char, char> conv;  //convert from letters to "numbers"

int main() {
	string N; 
	fin >> N; 
	conv['A'] = '2'; conv['B'] = '2'; conv['C'] = '2'; 
	conv['D'] = '3'; conv['E'] = '3'; conv['F'] = '3'; 
	conv['G'] = '4'; conv['H'] = '4'; conv['I'] = '4'; 
	conv['J'] = '5'; conv['K'] = '5'; conv['L'] = '5'; 
	conv['M'] = '6'; conv['N'] = '6'; conv['O'] = '6'; 
	conv['P'] = '7'; conv['R'] = '7'; conv['S'] = '7';
	conv['T'] = '8'; conv['U'] = '8'; conv['V'] = '8'; 
	conv['W'] = '9'; conv['X'] = '9'; conv['Y'] = '9'; 
	string temp = "";
	bool found = false; 
	while (dict >> temp){
		string name = ""; //conversion of name to a number
		for (int i = 0; i<temp.length(); i++){
			name += conv[temp.at(i)]; 
		}
		if (name == N){
			found = true; 
			fout << temp << endl; 
		}
	}	
	if (!found) fout << "NONE\n"; 
}