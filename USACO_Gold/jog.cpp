#include <iostream>

using namespace std;
typedef long long ll; 

struct cow{
    ll p, s; 
};

const int maxN = 100010; 
cow arrs[maxN]; 
ll pos[maxN]; 
int N, T; 

int main() {
   cin >> N >> T;
   for (int i = N-1; i >= 0; i--){ //decreasing 
       cin >> arrs[i].p >> arrs[i].s; 
   }
   for (int i = 0; i < N; i++){ //future position
       pos[i] = arrs[i].p + arrs[i].s*T; 
   }
   int tot = 1; 
   ll f = pos[0]; 
   for (int i = 0; i < N; i++){
       if (pos[i] < f){ //new group
           tot++; 
           f = pos[i]; 
       }
   }
   cout << tot << endl; 
}
