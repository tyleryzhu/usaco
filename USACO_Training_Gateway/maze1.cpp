/**
	ID: tylerzh1
	PROB: maze1 
	LANG: C++11
**/
#include <iostream>
#include <fstream>
#include <cstring> 
#include <queue>

using namespace std; 

ofstream fout("maze1.out"); 
ifstream fin("maze1.in"); 

struct Point {
    int h, w;
};

int W, H;
int arrs[210][80]; // H by W
queue<Point> q1, q2;
int dh[4] = {0,0,-1,1};
int dw[4] = {-1,1,0,0};
int maxDis = 0;

void print_arr() {
    for (int i = 0; i<2*H+1; i++){
        for (int j = 0; j< 2*W+1; j++){
            if (arrs[i][j] == -1) fout << "+"; 
            else if (arrs[i][j] == 0) fout << " ";
            else fout << arrs[i][j]; 
        }
        fout << endl;
    }
    fout << endl;
}

bool legal(Point p) {
    if (p.w < 0 || p.w > 2*W || p.h > 2*H || p.h < 0) return false;  // out of bounds
    if (arrs[p.h][p.w] == -1) return false; // if fence
    return true;
}

void bfs() {
    while (!q1.empty() || !q2.empty()){
        if (!q2.empty()){
            Point pt2 = q2.front();
            q2.pop();
            
            for (int i = 0; i<4; i++){
                Point psh = pt2;
                psh.h += dh[i]; psh.w += dw[i];
                if (legal(psh)) {
                    psh.h += dh[i]; psh.w += dw[i];
                    if (arrs[psh.h][psh.w] == 0 || arrs[psh.h][psh.w] > arrs[pt2.h][pt2.w]+1) {
                        q2.push(psh);
                        arrs[psh.h][psh.w] = arrs[pt2.h][pt2.w]+1;
                    }
                }
            }
        }
        
        if (!q1.empty()){
            Point pt1 = q1.front();
            q1.pop();
            
            for (int i = 0; i<4; i++){
                Point psh = pt1;
                psh.h += dh[i]; psh.w += dw[i];
                if (legal(psh)) {
                    psh.h += dh[i]; psh.w += dw[i];
                    if (arrs[psh.h][psh.w] == 0 || arrs[psh.h][psh.w] > arrs[pt1.h][pt1.w]+1) {
                        q1.push(psh);
                        arrs[psh.h][psh.w] = arrs[pt1.h][pt1.w]+1;
                    }
                }
            }
//            print_arr(); 
        }
        
        //print_arr();
    }
}

int main() {
    fin >> W >> H;
    Point ex1, ex2;
    bool write = false; // if x1 and y1 have been written to yet
    fin.ignore();
    for (int i = 0; i < 2*H+1; i++){
        string temp;
        getline (fin, temp);
        for (int j = 0; j<2*W+1; j++){
            if (temp.at(j) == '+' || temp.at(j) == '-' || temp.at(j) == '|') arrs[i][j] = -1;
            else {
                if (i == 0 || i == 2*H || j == 0 || j == 2*W){ // if exit
                    arrs[i][j] = -1;
                    int h, w;
                    if (i == 0) {
                        h = 1;
                        w = j;
                    }
                    else if (i == 2*H){
                        h = 2*H-1;
                        w = j;
                    }
                    else if (j == 0) {
                        h = i;
                        w = 1;
                    }
                    else {
                        h = i;
                        w = 2*W-1;
                    }
                    if (!write){
                        ex1.h = h; ex1.w = w;
                        write = true;
                    }
                    else{
                        ex2.h = h; ex2.w = w;
                    }
                }
            }
        }
    }
    arrs[ex1.h][ex1.w] = 1;
    arrs[ex2.h][ex2.w] = 1;
    q1.push(ex1);
    q2.push(ex2);
    bfs();

    for (int i = 0; i < 2*H+1; i++){
        for (int j = 0; j < 2*W+1; j++){
            maxDis = max(maxDis, arrs[i][j]); 
        }
    }
    fout << maxDis << endl; 
    
    return 0;
}
/**
struct Point {
    int h, w;
    Point () {}; 
    Point (int h, int w) : h(h), w(w) {}
};

const int maxW = 100; 
const int maxH = 210; 
int W, H;
Point ex1, ex2; 
int arrs[maxH][maxW]; // H by W
int maze[maxH][maxW]; 
int dh[4] = {0,0,-1,1};
int dw[4] = {-1,1,0,0};

bool legal(Point p, int dir) {
    if (p.w+2*dw[dir] < 0 || p.w+2*dw[dir] > 2*W || p.h+2*dh[dir] > 2*H || p.h+2*dh[dir] < 0) return false;  // out of bounds
    if (arrs[p.h+dh[dir]][p.w+dw[dir]] == -1) return false; // if fence
    return true;
}

int bfs(Point start) {
    int dist = 0; 
    queue<Point> q; 
    int mark[maxH][maxW]; 
    memset(mark, 0, sizeof(mark)); 
    q.push(start); 
    mark[start.h][start.w] = 1; 
    while (!q.empty()){
        Point temp = q.front(); 
        q.pop(); 
        cout << temp.h << " " << temp.w << " " << mark[temp.h][temp.w] << endl; 
        maze[temp.h][temp.w] = min(maze[temp.h][temp.w], mark[temp.h][temp.w]); 
        dist = max(dist, maze[temp.h][temp.w]); 
        for (int k = 0; k<4; k++){
            Point next = Point(temp.h + 2*dh[k], temp.w + 2*dw[k]); 
            if (legal(temp, k) && !mark[next.h][next.w]){
                mark[next.h][next.w] = mark[temp.h][temp.w]+1; 
                q.push(next); 
            }
        }
    }
    return dist; 
}

int main() {
    memset(maze, 63, sizeof(maze)); 
    fin >> W >> H;
    fin.ignore();
    for (int i = 0; i < 2*H+1; i++){
        string temp;
        getline (fin, temp);
        for (int j = 0; j<2*W+1; j++){
            if (temp.at(j) == '+' || temp.at(j) == '-' || temp.at(j) == '|') arrs[i][j] = -1;
            else if (i == 0 ){
                if (!ex1.h && !ex1.w) ex1 = Point(1,j);  
                else ex2 = Point(1, j); 
            }
            else if (i == 2*H){
                if (!ex1.h && !ex1.w) ex1 = Point(2*H-1, j);
                else ex2 = Point(2*H-1, j); 
            }
            else if (j == 0){
                if (!ex1.h && !ex1.w) ex1 = Point(i, 1);  
                else ex2 = Point(i, 1); 
            }
            else if (j == 2*W){
                if (!ex1.h && !ex1.w) ex1 =  Point(i, 2*W-1); 
                else ex2 = Point(i, 2*W-1); 
            }
        }
    }
    fout << max(bfs(ex1), bfs(ex2)) << endl; 
}
**/
