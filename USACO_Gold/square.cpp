#include <iostream>
#include <fstream>

using namespace std; 

int main() {
	ofstream fout("square.out"); 
	ifstream fin("square.in"); 

	int x1, x2, y1, y2; 
	int a1, a2, b1, b2; 
	fin >> x1 >> y1 >> x2 >> y2; 
	fin >> a1 >> b1 >> a2 >> b2; 

	int xmin = min(x1, a1); 
	int ymin = min(y1, b1); 

	int xmax = max(x2, a2); 
	int ymax = max(y2, b2); 

	int xdiff = xmax - xmin; 
	int ydiff = ymax-ymin; 
	int diff = max(xdiff, ydiff); 
	fout << diff*diff << endl; 
}