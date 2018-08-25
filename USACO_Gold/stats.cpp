#include <iostream>
#include <string> 
#include <cmath>

using namespace std; 

int main() {
	string temp; 
	cout << "Would you like to calculate a One Proportion Z-Interval? " << endl; 
	cin >> temp; 
	if (temp.compare("NO") == 0){
		cout << "The program shall end " << endl; 
		return 0; 
	}
	while (temp.compare("NO") != 0){
		cout << "Input p-hat, followed by the z-score and then followed by n" << endl; 
		double phat, z, n; 
		cin >> phat >> z >> n; 
		double moe = sqrt(phat * (1-phat) / n)*z; 
		cout << "( " << phat-moe << ", " << phat+moe << " )" << endl; 
		cout << "Would you like to do this again?" << endl; 
		cin >> temp; 
	}
	return 0; 
}