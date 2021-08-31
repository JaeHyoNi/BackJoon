#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

vector <string> mytoken = { "push", "pop", "size", "empty","front","back" };

int get_type(string w) {
	for (int i = 0; i < 6; i++) {
		if (w == mytoken[i]) return(i);
	}
	return(-1);
}

int main() {
	queue<int> que;
	int num, i, temp;
	scanf("%d", &num);
	
	int what;
	string wh;
	for (i = 0; i < num; i++) {
		cin >> wh;
		what = get_type(wh);
		switch (what) {
		case 0:
			scanf(" %d", &temp);
			que.push(temp);
			break;
		case 1:
			if (!que.empty()) {
				printf("%d\n", que.front());
				que.pop();
			}
			else
			{
				printf("-1\n");
			}
			break;
		case 2:
			printf("%d\n", que.size());
			break;
		case 3:
			printf("%d\n", que.empty());
			break;
		case 4:
			if (que.empty())
				printf("-1\n");
			else printf("%d\n", que.front());
			break;
		case 5:
			if (que.empty())
				printf("-1\n");
			else printf("%d\n", que.back());
			break;
		}
	}
	return 0;
}