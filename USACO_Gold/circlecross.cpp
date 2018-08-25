#include <iostream>
#include <fstream> 
#include <cstring> 

using namespace std; 

ofstream fout("circlecross.out"); 
ifstream fin("circlecross.in"); 

struct BIT{
	int* tree; 	//initializes array tree 
	int maxT; 

	BIT() {}; 	

	BIT(int n){ //constructor
		tree = new int[n+5]; 
		maxT = n+5; 
		memset(tree, 0, sizeof(int)*maxT); 
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

const int maxN = 50010; 
int arrs[maxN*2]; 
int ind[maxN]; 

int main() {
	int N; 
	fin >> N; 
	for (int i = 1; i<= 2*N; i++){
		fin >> arrs[i]; 
	}	
	long tot = 0; 
	BIT bit(2*maxN); 
	for (int i = 1; i <= 2*N; i++){
		if (ind[arrs[i]] == 0){ //has not been visited
			bit.update(i, 1); 
			ind[arrs[i]] = i; 
		}
		else { //has been visited
			bit.update(i, 1); 
			bit.update(ind[arrs[i]], -2); 
			tot += bit.query(ind[arrs[i]], i); 
		}
//		cout << "tot: " << tot << endl; 
	}
	fout << tot/2 << endl; 
}