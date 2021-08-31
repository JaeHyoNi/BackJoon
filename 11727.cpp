#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int arr[1050];

int fibo(int n) {
	if (arr[n] != 0) {return arr[n];}
	else
	{
		if (arr[n - 1] == 0) { arr[n - 1] = fibo(n - 1)%10007; }
		if (arr[n - 2] == 0) { arr[n - 2] = fibo(n - 2)%10007; }
		return ((arr[n - 1] + arr[n - 2] * 2 ) % 10007);
	}

}
int main() {
	arr[1] = 1; arr[2] = 3; arr[3] = 5;
	int num;
	cin >> num;
	int ans = fibo(num);
	cout << ans;
}