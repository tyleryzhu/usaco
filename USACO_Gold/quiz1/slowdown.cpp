//problem 2 slowdown
#include <iostream> 
#include <algorithm>

using namespace std; 

int N; 
int t,d; // # of t events , # of d events
double dist; //current distance 
double Time;  // current Time 
double down; // # of times bessies slows down
int T[10000]; 
int D[10000]; 

double time_travel(int ind){// index of Time ; returns the distance traveled in that Time period 
	return ((T[ind]-Time)/down); 
}

double dist_travel(int ind){// index of distance; returns the Time traveled in that distance period
	return ((D[ind]-dist)*down); 
} 

int main() {
	cin >> N; 
	t = 0; 
	d = 0; 
	dist = 0; 
	Time = 0; 
	down = 1; // 1/down is bessie's velocity
	for (int i = 0; i<N; i++){
		char temp; 
		cin >> temp; 
		if (temp == 'T'){
			cin >> T[t]; 
			t++; 
		}
		else{   // double check that this actually works and gives D
			cin >> D[d]; 
			d++; 
		}
	}

	sort(T, T+t);  // sort them in increasing order
	sort(D, D+d); 

	int tCount= 0; 
	int dCount = 0; // keeps track of which index we are on

	for (int i = 0; i<N; i++){ // loop through all total N possibilities
		if ( (time_travel(tCount) + dist < D[dCount] && tCount <t) || dCount  >= d){ // if bessie would slowdown first based on T than on D
			//cout << "1Dist: " << dist << " Time: " << Time << endl; 
			dist +=  time_travel(tCount);  // update dist
			Time = T[tCount];  // update time
			tCount++; 
			down++; 
		}
		else { //distance is either equal to or greater than time_travel
			//cout << "2Dist: " << dist << " Time: " << Time << endl; 
			Time +=  dist_travel(dCount); 
			dist = D[dCount]; 
			dCount++;
			down++; 
		}
	}

	if (dist < 1000){
		Time += (down * (1000-dist)); 
	}

	
	cout << (int) Time << endl; 

}