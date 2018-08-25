/**
	ID: tylerzh1
	PROB: fracdec
	LANG: C++11
**/
#include <iostream>
#include <fstream>
#include <cstring>
#include <algorithm>

using namespace std; 

ofstream fout("fracdec.out"); 
ifstream fin("fracdec.in"); 

int main() 
{
    int N, D; 
    fin >> N >> D; 
    string num = ""; 
    num = num + to_string(N/D) + ".";  //make N/D < 1
    N %= D; 
    
    if (N == 0)  //special case
    {
        num += "0"; 
        fout << num << endl; 
        return 0; 
    }

    // now divide and check remainders
    bool rem[D]; //if remainder calculated, mark true 
    memset(rem, 0, sizeof(rem)); 
    int pos[D]; // tracks which position remainder D is at  
    int ct = 0; 
    string q = ""; 
    
    while ( (N != 0) && (!rem[N] || ct == 0))  //while remainder has not been calculated
    {
        rem[N] = true; 
        pos[N] = ct; 
        ct++; 
        q += to_string(N*10/D); 
        N = N*10 % D; 
    }
    
    // either N is 0 now, so it terminates 
    if (N == 0) num += q; 
    else {  // or N is a repeat 
        num = num + q.substr(0, pos[N]) + "(" + q.substr(pos[N], q.length()-pos[N]) + ")"; 
    }

    int mult = num.length() / 76; 
    for (int i = 0; i <= mult; i++) 
    {
        fout << num.substr(i*76,76) << endl; 
    }
}
