#include <iostream>

using namespace std; 

int main() {
	cout << "1 || 2 gives " << 1||2 ; 
	cout << endl; 
	cout << "2 || 1 gives " << 2||1 ; 
	cout << endl; 
	cout << "(1%7 == (1||2)) gives " << (1%7 == (1||2)) << endl; 

	cout << " (1 == 1) gives " << (1 == 1) << endl; 
	
	cout << "(bool) 1 || bool(2) gives" << bool(1) || bool(2); 
	cout << endl; 	

	cout << "0 || 1 gives " << 0 || 1; 
	cout << endl; 
	cout << "bool(0)||bool(1) gives " << bool(0) || bool(1); 
	cout << endl; 
}