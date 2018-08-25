/**
	ID: tylerzh1
	PROB: sort3
	LANG: C++11
**/ 
#include <fstream>
#include <iostream>

using namespace std; 

ofstream fout("sort3.out"); 
ifstream fin("sort3.in"); 

int arrs[1000]; 

int main() {
	int N; 
	fin >> N; 
	int one = 0; 
	int two = 0; 
	int three = 0; //coutners for # of each number
	int swap = 0; //# of swaps
	for (int i = 0; i<N; i++){
		fin >> arrs[i]; 
		if (arrs[i] == 1) one++; 
		else if (arrs[i] == 2) two++; 
		else three++; 
	} 
//	cout << one << " " << two << " " << three << endl; 
	int ct = 0; 
	//swap 1's into place while looking for 2's
	for (int i = one; i<N; i++){
		if (arrs[i] == 1){
			bool swapped  = false;
			/** First look for a 2 to swap with the 1 **/ 
			for (int j = 0; j<one; j++){
				if (arrs[j] == 2 && !swapped){
//					cout << "1 : " << i << " " << j << endl; 
					swapped = true; 
					arrs[i] = 2; 
					arrs[j] = 1; 
					swap++; 
				}
			}
			if (!swapped){ //if we didnt find a 2 to swap with the 1
				for (int j = 0; j<one; j++){
					if (arrs[j] == 3){
//						cout << "1 : " << i << " " << j << endl; 
						swapped = true; 
						arrs[i] = 3; 
						arrs[j] = 1; 
						swap++; 
					}
				}
			}
		}
	}
	//swap 2's into place 
	ct = one; 
	for (int i = one+two; i<N; i++){
		if (arrs[i] == 2){
			while (arrs[ct] == 2){
				ct++; 
			}
			arrs[i] = arrs[ct]; 
			arrs[ct] = 2; 
			swap++; 
		}
	}
	fout << swap << endl; 
}