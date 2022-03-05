#include <iostream>
using namespace std;


int main() {
    int max = -1000001, min = 1000001;
    int N,temp;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> temp;
        if (max < temp) max = temp;
        if (min > temp) min = temp;
    }
    cout << min << " " << max;
}
