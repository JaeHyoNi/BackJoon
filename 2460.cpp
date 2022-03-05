#include <iostream>
using namespace std;


int main() {
    int max = 0, sum=0, rin, rout;
    for (int i = 0; i < 10; i++) {
        cin >> rout >> rin;
        sum -= rout;
        sum += rin;
        if (sum > max) max = sum;
    }
    cout << max;
    return 0;
}
