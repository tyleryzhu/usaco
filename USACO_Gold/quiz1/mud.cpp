//problem 1 
#include <iostream> 
#include <queue>

using namespace std; 

int grid[1001][1001]; 
int dy[4] = {0,0,1,-1}; 
int dx[4] = {1,-1,0,0}; 

int X, Y, N; //X,Y are bessie's location. N is the # of mud puddles
int Xmin, Xmax, Ymin, Ymax; // keep track of xmin x max etc to reduce bfs and actually be able to solve for stuff
queue<int> qx;
queue<int> qy;  

bool valid(int x, int y){
	if ( x < Xmin || x > Xmax || y < Ymin || y > Ymax){ // out of bounds
		return false; 
	}
	else if (grid[x][y] != 0){ // mud or traveled to
		return false; 
	}
	return true; 
}

void bfs(){
	qx.push(500); 
	qy.push(500); 
	while (!qx.empty()){
		int xFront = qx.front(); qx.pop(); 
		int yFront = qy.front(); qy.pop(); 

		int dist = grid[xFront][yFront]; 

		if (xFront == (X+500) && yFront == (Y+500)){
			cout << dist << endl; 
			return; 
		}

		for (int i = 0; i<4; i++){
			int newX = xFront + dx[i];  //  up down left or right
			int newY = yFront + dy[i]; 
			if (valid(newX, newY)){  // if not out of bounds + not mud + not already travelled to
				qx.push(newX);    // recurse 
				qy.push(newY); 
				grid[newX][newY] = dist+1; 
			}
		}

	}
}

int main() {
	cin >> X >> Y >> N; 
	Xmin = 500; Xmax = 500; Ymin = 500; Ymax = 500; // initialize these at center where FJ is 

	for (int i = 0; i<N; i++){
		int x, y; //temp 
		cin >> x >> y; 
		x += 500; y += 500; // shift by 500 to store neg values 
		grid[x][y] = -1;  // mud piles be -1 
		if (x < Xmin) Xmin = x; 		// figure out minimums
		else if (x > Xmax) Xmax = x;    // figure out maximums

		if (y < Ymin) Ymin = y; 
		else if (y > Ymax) Ymax = y; 
	}
	if (Xmin != 0) Xmin--; 
	if (Xmax != 1000) Xmax++;  				// setting boundaries
	if (Ymin != 0) Ymin--; 
	if (Ymax != 1000) Ymax++; 

	// be wishful and hope that no values randomly = -1 

	for (int i = Xmin; i<Xmax+1; i++){
		for (int j = Ymin; j<Ymax+1; j++){
			if (grid[i][j] != -1) grid[i][j] = 0;  // everything else is 0; 
		}
	}

	// done initializing 
	bfs(); 
}