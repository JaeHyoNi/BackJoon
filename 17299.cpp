#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
int dic[1000001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int num, i, j;
	stack<pair<int,int>> temp;
	map< int, int> dic;
	cin >> num;
	int* arr = new int[num];
	int* sol = new int[num];
	for (int i = 0; i < num; i++) {sol[i] = -1;}
	for (i = 0; i < num; i++) {
		cin >> arr[i];
		dic[arr[i]]++;
	}
	i = 0;
	while (i < num) {
		if (temp.empty()) { temp.push(make_pair(arr[i],i)); i++; }
		else if (dic[temp.top().first] > dic[arr[i]]) {
			temp.push(make_pair(arr[i],i));
			i++;
		}
		else {
			while (!temp.empty()&& dic[temp.top().first] < dic[arr[i]] ) {
				sol[temp.top().second] = arr[i];
				temp.pop();
			}
			temp.push(make_pair(arr[i],i));
			i++;
		}
	}
	for (int i = 0; i < num; i++) {
		cout << sol[i] << " ";
	}
}