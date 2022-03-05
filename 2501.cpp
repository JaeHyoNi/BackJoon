#include <iostream>
using namespace std;

int main(void) {
    int N, num,now=0;
    bool flag = false;
    cin >> N >> num;
    for (int i = 1; i <= N; i++) {
        if (N % i == 0) now++;
        if (now == num) {
            cout << i;
            flag = true;
            break;
        }
    }
    if (!flag) cout << "0";
    return 0;
}
