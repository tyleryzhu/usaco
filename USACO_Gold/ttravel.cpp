#include <iostream>
#include <stack> 

using namespace std; 

#define REP(i, a,b) \
	for( int i = int(a); i < int(b); i++)

int N; 
stack<int> id; 
stack<int> q; 

int main() {
	cin >> N; 
	char temp; 
	int num; 
	id.push(-1); 
	q.push(0); 
	REP(i, 1, N+1){
		cin >> temp; 
		if (temp == 'a'){  // if adding a number 
			cout << "a" << endl; 
			cin >> num; 
			id.push(num); 
			q.push(i); 
		}
		else if (temp == 's' ){
			cout << "s" << endl; 
			id.pop(); 
			q.pop(); 
		}
		else { // q traveling
			cout << temp << endl; 
			cin >> num; 
			while (q.top() >= num){
				cout << " loop " << " " << q.top() << " " << num << endl; 
				id.pop(); 
				q.pop(); 
			}
		}
		cout << id.top() << endl; 
	}
}