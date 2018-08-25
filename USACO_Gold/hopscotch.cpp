#include <iostream>
#include <fstream>

using namespace std;

const int maxR = 750, maxC = 750;
const int MOD = 1e9+7;
int arrs[maxR+5][maxC+5];
int dp[maxR+5][maxC+5];
int R, C, K;

ofstream fout("hopscotch.out");
ifstream fin("hopscotch.in");


int main() {
  fin >> R >> C >> K;
  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C; j++) {
      fin >> arrs[i][j];
    }
  }

  dp[0][0] = 1;
  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C; j++) {
      for (int m = 0; m < i; m++) {
        for (int n = 0; n < j; n++) {
          if (arrs[m][n] != arrs[i][j]) {
            dp[i][j] += dp[m][n];
            dp[i][j] %= MOD;
          }
        }
      }
    }
  }
  // for (int i = 0; i < R; i++) {
  //   for (int j = 0; j < C; j++){
  //     cout << dp[i][j] << " ";
  //   }
  //   cout << endl;
  // }
  fout << dp[R-1][C-1] << endl;
}
