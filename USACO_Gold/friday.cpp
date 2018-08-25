/*
ID: tylerzh1
PROG: friday 
LANG: C++11
*/

#include <fstream>
#include <string>
#include <iostream>

using namespace std; 

int month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; // dates of the months
int fri[7] = {0}; //store fridays


// 0 - 6 will be the days of the week 
int main() {
	int N; 
	ofstream fout("friday.out"); 
	ifstream fin("friday.in"); 
	fin >> N; 
	int day = 1; // intialize day of the month
	int week = 0;  // day of the week
	int year = 1900; // year 1900 
	int mon = 0; // month counter
	while (year < N+1900){
		if (day == 13) fri[week]++; //increase 1 for the day of the week that 13 lands on
		if (((year %4 == 0) && (year % 100 != 0)) || (year == 2000)){ // if leap year (mult of 4 but not 100) or (2000)
			month[1] = 29; //update feb to have 29 days
		}
		else {//non leap year
			month[1] = 28; // unleap the year
		}

		day++; 
		week++; 
		week %= 7; 

		if (day > month[mon]){ // if more days in a month than supposed to 
			day = 1; 
			mon++; 

		}
		if (mon > 11){// reached the end of the year
			year++; 
			day = 1; 
			mon = 0; // reset 
		}	
	}

	for (int i = 5; i<12; i++){
		fout << fri[i%7]; 
		if (i != 11) fout << " "; 
	}
	fout << endl; 
	return 0; 
}

/*
#include <fstream>
#include <string>
#include <iostream>

using namespace std; 

int month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; // dates of the months
int fri[7] = {0}; //store fridays


// 0 - 6 will be the days of the week 
int main() {
	int N; 
	cin >> N; 
	int day = 1; // intialize day of the month
	int week = 0;  // day of the week
	int year = 1900; // year 1900 
	int mon = 0; // month counter
	while (year <1900+ N){
		if (day == 13) fri[week]++; //increase 1 for the day of the week that 13 lands on
		if (((year %4 == 0) && (year % 100 != 0)) || (year == 2000)){ // if leap year (mult of 4 but not 100) or (2000)
			month[1] = 29; //update feb to have 29 days
		}
		else {//non leap year
			month[1] = 28; // unleap the year
		}

		day++; 
		week++; 
		week %= 7; 

		if (day > month[mon]){ // if more days in a month than supposed to 
			day -= month[mon]; 
			mon++; 

		}
		if (mon > 11){// reached the end of the year
			year++; 
			day %= 31; 
			mon = 0; // reset 
		}	
	}

	for (int i = 5; i<12; i++){
		cout << fri[i%7]; 
		if (i != 11) cout << " "; 
	}
	cout << endl; 
	return 0; 
}
*/