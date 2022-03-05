#include <iostream>
using namespace std;

void bin(int num) {
    int i = 0;
    while (num != 1) {
        if (num % 2 == 1) cout << i<<" ";
        num /= 2;
        i++;
    }
    cout << i<<endl;
}

int main(void) {
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        int K;
        cin >> K;
        bin(K);
    }
}
