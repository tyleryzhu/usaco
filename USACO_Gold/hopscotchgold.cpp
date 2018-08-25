#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

const int maxR = 750, maxC = 750, maxK = maxR*maxC;
const int MOD = 1e9+7;
int arrs[maxR+1][maxC+1];
vector<int> columns[maxK+1];
vector<int> vals[maxK+1];
int R, C, K;

ofstream fout("hopscotch.out");
ifstream fin("hopscotch.in");


int main() {
  fin >> R >> C >> K;
  for (int i = 1; i <= R; i++) {
    for (int j = 1; j <= C; j++) {
      fin >> arrs[i][j];
    }
  }

  // Step 1: Figure out where the colors are
  for (int j = 1; j <= C; j++) {
    for (int i = 1; i <= R; i++) {
        int color = arrs[i][j];
        int len = columns[color].size();
        // checking len == 0 so we dont get array o.u.b. with len-1
        if (len == 0 || columns[color][len-1] != j) { // check if j is already in
            columns[color].push_back(j);
        }
    }
  }

  int total[maxC+1] = {0};
}
