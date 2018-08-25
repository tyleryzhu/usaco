#include <iostream>
#include <cmath>

using namespace std;

int main() {
    double cur, N; 
    cin >> N;
    double totP, totL = 0; 
    for (int i = 0; i <6; i++){
        cin >> cur; 
        double p = cur/N; 
        cout << p << " " << log(p) << " " << p*log(p) << endl; 
        totP += log(p); 
        totL += p*log(p); 
    }
    cout << totP << " " << totL << endl; 
}
