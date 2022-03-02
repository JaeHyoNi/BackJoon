#include <iostream>
#include <queue>

using namespace std;
int arr[100][100], N, M, ans;
queue<pair<int, int>> point;
int x[4] = { 1,0,-1,0 }, y[4] = { 0,1,0,-1 };

void check(int dep) {
    int a, b, now_x, now_y;
    int siz = point.size();
    for (int j = 0; j < siz; j++) {
        now_x = point.front().first;
        now_y = point.front().second;
        for (int i = 0; i < 4; i++) {
            a = now_x + x[i];
            b = now_y + y[i];
            if (a < 0 || b < 0 || a >= N || b >= M) continue;
            if (arr[a][b] == 1) {
                if (a == N - 1 && b == M - 1) {
                    ans = dep;
                    return;
                }
                arr[a][b] = dep;
                point.push({ a,b });
            }
        }
        point.pop();
    }
    check(dep + 1);
}

void solution() {
    point.push({ 0,0 });
    check(2);
    cout << ans << endl;
}

int main() {
    string temp;
    int k = 0;
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> temp;
        k = 0;
        for (auto K : temp) {
            arr[i][k] = K - '0';
            k++;
        }
    }
    solution();
    return 0;
}
