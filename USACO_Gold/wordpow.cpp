#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string cows[1010]; 
int qual[1010]; 
string good[110]; 

int main() {
    int N, M; 
    cin >> N >> M; 
    for (int i = 0; i < N; i++){
        cin >> cows[i]; 
        transform(cows[i].begin(), cows[i].end(), cows[i].begin(), ::tolower); //convert to lowercase 
    }
    for (int i = 0; i < M; i++){
        cin >> good[i]; 
        transform(good[i].begin(), good[i].end(), good[i].begin(), ::tolower); //convert to lowercase 
    }
    /** Iterate through good strings, and then through cows **/ 
    for (int g = 0; g < M; g++){
        for (int c = 0; c < N; c++){ //keep one pointer for the good stirng 
            int pos = 0; 
            for (int i = 0; i < cows[c].size(); i++){
                if (pos == good[g].size()) break; 
                if (cows[c].at(i) == good[g].at(pos)){ //places match 
                    pos++;  
                }
            } 
            if (pos == good[g].size()) qual[c]++; //increment cow qual
        }
    } 
    for (int i = 0; i < N; i++){
        cout << qual[i] << endl; 
    }
}


