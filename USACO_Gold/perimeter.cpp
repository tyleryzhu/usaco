#include <iostream>
#include <queue>
#include <map> 

using namespace std;

int dr[4] = {0, 0, 1, -1}; 
int dc[4] = {1, -1, 0, 0};  //for moving in floodfill
int cr[8] = {0, 1, 1, 1, 0, -1, -1, -1};  //for checking if neighbor is box
int cc[8] = {1, 1, 0, -1, -1, -1, 0, 1}; 
map<pair<int, int>, int> box, m; // box[1][2] = 0 means box, m[1][2] = 0 means floodfilled 
int tot; 

void bfs(int start, int end){
    queue<pair<int, int> > q; 
    q.push(make_pair(start, end)); 
    
    while(!q.empty()){ 
        int x = q.front().first; 
        int y = q.front().second; 
        q.pop(); 
        for (int i = 0; i<4; i++){
            int nx = x+dr[i]; 
            int ny = y+dc[i]; 
            if (box.count(make_pair(nx,ny)) == 1){
                tot++; 
            }
        }
        //Floodfill
        for (int i = 0; i < 4; i++){
        int nx = x+dr[i]; 
        int ny = y+dc[i]; 
        if (box.count(make_pair(nx, ny)) == 1 ||  //is box
            m.count(make_pair(nx, ny)) == 1) continue; //or already flooded to 
        // Remains to check that there is a box within 8 squares 
        for (int j = 0; j < 8; j++){
            int bx = nx + cr[j]; 
            int by = ny + cc[j]; 
            if (m.count(make_pair(nx, ny)) == 0 && box.count(make_pair(bx, by)) == 1){ //if there is a box neighboring
                m[make_pair(nx, ny)] = 0;  //floodfill
                q.push(make_pair(nx, ny));
                break; 
            }
        }
        }
    }
}

int main() {
    int N; //keep track of coordinates of leftmost (first) and bottommost (2nd) box
    pair<int, int> smol = make_pair(1000001,1000001); 
    cin >> N; 
    for (int i = 0; i<N; i++){
        int x, y;
        cin >> x >> y; 
        box[make_pair(x,y)] = 1;  //create box 
        smol = min(smol, make_pair(x, y)); 
    }
    smol.first--; 
    m[smol] = 0;  //mark for floodfill
    bfs(smol.first, smol.second); 
    cout << tot << endl; 
}
