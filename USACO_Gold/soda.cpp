#include <iostream> 
#include <queue> 

using namespace std; 

typedef pair<int, int> ii; 
typedef vector<ii> vii; 
const int maxN = 50010; 
int N; 

class prioritize{public: bool operator ()(pair<int, int>&p1 ,pair<int, int>&p2){
	return (p1.first == p2.first) ? p1.second < p2.second : p1.first > p2.first;  //want least priority 
	}
}; //p1.first is time,  p1.second = 1 if start, -1 if end

int main() {
	cin >> N; 
	priority_queue<ii, vii, prioritize> pq; 
	for (int i = 0; i<N; i++){
		int start, e; 
		cin >> start >> e; 
		pq.push(make_pair(start, 1)); 
		pq.push(make_pair(e, -1)); 
	}	
	int best = 0;  //keep best value 
	int curr = 0; 
	while (!pq.empty()){
		ii temp = pq.top(); pq.pop(); //get front element
		curr += temp.second;  //automatically updates 
		best = max(best, curr);  //update best
	}
	cout << best << endl; 
}