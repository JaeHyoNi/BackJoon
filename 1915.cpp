#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int arr[1001][1001];
int main() {

	int row, col;
	cin >> row >> col;
	string temp;
	cin >> temp;
	int i = 0, j = 0, k = 0;
	int MAX = 0;
	for (char x : temp) { arr[0][i++] = (int)(x - 48) ; }
	if (arr[0][0] == 1) MAX = 1;
	for (i = 1; i < row; i++) {
		cin >> temp;
		for (char x : temp) {
			arr[i][j] = (int)(x - 48);
			if (j != 0) {
				if (arr[i - 1][j - 1] != 0 && arr[i - 1][j] != 0 && arr[i][j - 1] != 0 && arr[i][j] != 0) {
					arr[i][j] = min(arr[i - 1][j - 1], min(arr[i - 1][j], arr[i][j - 1])) + 1;
					if (arr[i][j] > MAX) {
						MAX = arr[i][j];
					}
				}
			}
			j++;
		}
		j = 0;
	}
	cout << MAX*MAX;
}

