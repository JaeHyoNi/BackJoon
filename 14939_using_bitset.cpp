#include<bits/stdc++.h>
using namespace std;
// 꺼짐,켜짐 상태를 바꿔준다.
inline void change(char &c){
	if(c=='#') c='O';
	else c='#';
}
// x행 y열과 이에 인접한 전구를 바꿔준다.
// 인덱스를 벗어나지 않게 주의한다.
inline void push(int x, int y, auto &V){
	change(V[x][y]);
	if(x) change(V[x-1][y]);
	if(y) change(V[x][y-1]);
	if(x!=9) change(V[x+1][y]);
	if(y!=9) change(V[x][y+1]);
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	vector<string> orig;
	orig.resize(10);
	for(int i=0; i<10; ++i)
		cin >> orig[i];
	int ans = 101;
	//cand의 i번째 비트가 켜져있으면, [0][i]의 스위치를 누른다.
	for(int cand = (1<<10)-1; cand>=0; cand--){
		int ret = 0;
		vector<string> bulb = orig;
		for(int i=0; i<10; ++i)
			if(cand & (1<<i)){
				push(0,i,bulb);
				++ret;
			}
		//1행부터는 [i-1][j]가 켜져있으면 [i][j]의 스위치는 반드시 눌러야 한다.
		for(int i=1; i<10; ++i)
			for(int j=0; j<10; ++j){
				if(bulb[i-1][j] == '#') continue;
				push(i,j,bulb);
				++ret;
			}
		//10행의 전구가 전부 꺼져있으면 모든 전구가 꺼진 상태다.
		bool flag = true;
		for(int j=0; j<10; ++j)
			if(bulb[9][j] == 'O'){
				flag = false;
				break;
			}
		if(flag) ans = min(ans, ret);
	}
	//모든 조합을 시도 했지만 전구를 끌 수 없는 경우.
	cout << (ans == 101 ? -1 : ans);
}