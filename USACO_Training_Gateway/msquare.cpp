/**
	ID: tylerzh1
	PROB: msquare
	LANG: C++14
**/

#include <iostream>
#include <queue> 
#include <fstream>
#include <string> 

using namespace std;

ofstream fout("msquare.out"); 
ifstream fin("msquare.in"); 

bool visit[1000100] = {false};  
int p = 10e6+3; 

struct sq {
   string s; //current board 
   string moves=""; 
   int id; 
}; 

void printString(string s) {
    for (int i = 0; i < 4; i++){
        cout << s[i] << " "; 
    }
    cout << endl; 
    for (int i = 7; i > 3; i--){
        cout << s[i] << " "; 
    }
    cout << endl; 
}

string move(string s, char n) { //N is move number
    string t = ""; 
    if (n == 'A') { //exchange top and bottom
        for (int i = 7; i >= 0; i--) {
            t += s[i]; 
        }
    }
    else if (n == 'B') {
        t = t+s[3]+s[0]+s[1]+s[2]+s[5]+s[6]+s[7]+s[4]; 
    }
    else {
        t = t+s[0]+s[6]+s[1]+s[3]+s[4]+s[2]+s[5]+s[7]; 
    }
    return t; 
}

string bfs(string target, sq cur) {
    queue<sq> q; 
    q.push(cur); 
    string m = "ABC";
    while (!q.empty()) {
        cur = q.front(); q.pop(); 
        if (0 == target.compare(cur.s)) {
            return cur.moves;  
        }
        for (int i =0; i < 3; i++){
            int len = cur.moves.length();
            // if last one was A, no point in doing A again
            if (i == 0 && len > 0 && 
                    cur.moves[len -1] == 'A') continue; 
            // if last 3 were B, no point in doing B again 
            if (i == 1 && len > 2 &&  
                    !cur.moves.substr(len-3, 3).compare("BBB")) continue; 
            // if last 3 were C, no point in doing C again
            if (i == 2 && len > 2 && 
                    !cur.moves.substr(len-3, 3).compare("CCC")) continue; 
            sq temp; 
            temp.id = (cur.id*4+i+1)%p; //use a hash to check for duplicates
            if (visit[temp.id]) continue; 
            temp.s = move(cur.s,m[i]); 
            temp.moves = cur.moves+m[i]; 
            q.push(temp); 
            visit[temp.id] = true; 
        }
    }
}

int main() {
    string t = "", temp; 
    for (int i = 0; i < 8; i++){
        cin >> temp; 
        t += temp; 
    }
    sq start; 
    start.s = "12345678"; 
    start.moves = ""; 
    start.id = 0; 
    visit[0] = true; 
    string end = bfs(t,start); 
    cout << end.size() << endl << end << endl; 
}
