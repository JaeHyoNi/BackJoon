#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int arr[1005];
int main() {
	int n, k,num=0;
	cin >> n >> k;
	int  temp=2,fir=2;
	while (num != k) {
		temp = fir;
		while (fir < n +1) {
			if (arr[fir] == 0) {
				arr[fir] = 1;
				num++;

				if (num == k) {
					cout << fir;
					exit(0);
				}
			}
			fir = fir + temp;
		}

		while (temp < n + 1) {
			if (arr[temp] != 1) {
				fir = temp;
				break;
			}
			temp++;
		}
	}
}