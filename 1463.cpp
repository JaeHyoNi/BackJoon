#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
int v[1000005] = { 0, };
int main() {
	int X,  tn,time,t1,t2,t3;
	cin >> X;
    if (X == 1) { cout << 0; exit(0); }
	queue<pair<int, int>> arr;
	arr.push(make_pair(X, 0));
	pair<int, int> temp;
	while (1) {
		temp = arr.front();
		arr.pop();
		tn = temp.first; time = temp.second;
		t1 = tn / 3; t2 = tn / 2; t3 = tn - 1;
		if (tn == 3 || tn == 2) { cout << time + 1; exit(0); }
		if (tn % 3 == 0) { if (v[t1] == 0) { arr.push(make_pair(t1, time + 1)); v[t1] = 1; } }
		if (tn % 2 == 0) { if (v[t2] == 0) { arr.push(make_pair(t2, time + 1)); v[t2] = 1; } }
		if (v[t3] == 0) { v[t3] = 1; arr.push(make_pair(t3, time + 1)); }
	}
}
