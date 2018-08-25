/**
	ID: tylerzh1
	PROB: fact4  
	LANG: C++14
**/

#include <iostream>
#include <fstream>

using namespace std;

ofstream fout("fact4.out"); 
ifstream fin("fact4.in"); 

int main() {
    int N, tot = 1; 
    fin >> N; 
    
    int n2 = 0, n5 = 0; 
    for (int i = 2; i <= N; i*=2){
        n2 += N/i; 
    }
    for (int i = 5; i <= N; i*=5) {
        n5 += N/i; 
    }
    
    for (int i = 3; i <= N; i++){
        int x = i; 
        while (x > 1 && (x%2 == 0)) {
            x /= 2; 
        }
        while (x > 2 && (x % 5 == 0)) {
            x /= 5; 
        }
        tot = (tot * x) % 10; 
    }
    
    if (n2 > n5) {
        int x = (n2 - n5) % 4; 
        if (x == 0) x += 4; 
        for (int i = 0; i < x; i++){
            tot = (tot*2) % 10; 
        }
    }
    else if (n5 > n2) {
        tot = (tot * 5) % 10; 
    }

    fout << tot << endl; 
}
