/** 
	ID: tylerzh1
	PROB: crypt1
	LANG: C++11
**/
#include <iostream>
#include <fstream>

using namespace std; 

ofstream fout("crypt1.out"); 
ifstream fin("crypt1.in"); 

int N; 
int num[10]; 

bool check(int prod){
	while (prod > 0){
		bool found = false; 
		for (int i = 0; i<N; i++){
			if (prod%10 == num[i]){ //digit is found
				found = true; 
				break; 
			}
		}
		if (!found){
			return false; 
		}
		prod /= 10; 
	}
	return true; 
}

int main() {
	fin >> N; 
	for (int i = 0; i<N; i++){
		fin >> num[i]; 
	}
	int sol = 0; 
	for (int i = 100; i<1000; i++){
		if (check(i)){
			for (int j = 0; j<N; j++){ //ones digit	
				if ((i*num[j] <1000) && (check(i*num[j]))){
					for (int k = 0; k<N; k++){ //tens digit
						if ((i*num[k]<1000) && (check(i*num[k]))){
							if ((i*(10*num[k]+num[j])<10000) && (check(i*(10*num[k]+num[j])))){
//								cout << i << " " << 10*num[k]+num[j] << endl; 
								sol++; 
							}
						}
					}
				}
			}
		}
	}
	fout << sol << endl; 
}