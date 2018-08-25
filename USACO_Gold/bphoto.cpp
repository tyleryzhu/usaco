#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std; 

ofstream fout("bphoto.out"); 
ifstream fin("bphoto.in"); 

#define REP(i,a,b) \
	for (int i = int(a); i < int(b); i++) // a to b, i is local as usual 

struct BIT{
	int* tree; 	//initializes array tree 
	int maxT; 

	BIT(int n){ //constructor
		tree = new int[n+5]; 
		maxT = n+1; 
		for (int i = 0; i<=maxT; i++){
			tree[i] = 0; 
		}
	}

	~BIT(){ //destructor
		delete[] tree; 
	}

	void update(int ind, int val){ //update value at index ind with val
		ind++; 
		while (ind < maxT){
			tree[ind] += val; 
			ind += (ind & -ind); 
		}
	}

	int query(int ind){ //query the sum [1...a]; 
		ind++; 
		int sum = 0; 
		while (ind > 0){
			sum += tree[ind]; 
			ind -= (ind & -ind); 
		}
		return sum; 
	}

	int query(int a, int b){ //query the sum [a...b];  (overloaded)
		return query(b)-query(a-1); 
	}

	void printarr(){
		for (int i = 0; i<maxT; i++){
			cout << tree[i] << " "; 
		}
		cout << endl; 
	}
}; 

struct photo{
	int h; //height
	int pos; //index
};

bool comp(photo a, photo b){
	return (a.h > b.h); 
}

const int maxN = 100010; 
int N; 
photo arrs[maxN]; 

int main() {
	fin >> N; 
	BIT bit(N); 
	REP(i, 0, N){
		int temp; 
		fin >> temp; 
		photo temper = {temp, i}; 
		arrs[i] = temper; 
	}
	sort(arrs, arrs+N, comp); 
	int ct = 0; 
	for (int i = 0; i<N; i++){ //go through left and right
		int left = 0; 
		int right = 0; 
		/** Determine left **/ 
		left = bit.query(arrs[i].pos); //how many are greater
		right = i-left; 
		bit.update(arrs[i].pos, 1); 
		if (max(left,right) > 2 * min(left, right)) ct++; 
	}
	fout << ct << endl; 
}
