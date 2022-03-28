#include <bits/stdc++.h>
using namespace std;
bool arr[2510][2510];
int siz;
string str;

int main() {
	cin >> str;
	siz = str.size();
	for (int B = 0; B < siz; B++) {
		arr[B][B] = 1;
		for (int A = 0; A < B; A++) {
            if(B-A ==1){if(str[A] == str[B]) arr[A][B] = 1;}
			else if (str[A] == str[B]) {if (arr[A + 1][B - 1]) {arr[A][B] = 1;}else arr[A][B] = 0;}
			else arr[A][B] = 0;
		}
	}

    vector<int> DP(siz+1,999999);
    DP[0] = 0;
    for(int end = 1; end<=siz+1; end++){
        for(int start = 1;start <= end; start++){
            if(arr[start-1][end-1] == 1){
                DP[end] = min(DP[end],DP[start-1]+1);
            }
        }
    }
    cout<<DP[siz];
}