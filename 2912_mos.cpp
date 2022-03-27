#include <bits/stdc++.h>
using namespace std;

int n, q;
int arr[303030];
vector<int> v[10101];
int main(){
	mt19937 rd = mt19937((unsigned)chrono::steady_clock::now().time_since_epoch().count());
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> q;
	uniform_int_distribution<int> ran(0, 2147483647);
	for(int i=1; i<=n; i++){
		cin >> arr[i];
		if(v[arr[i]].empty()) v[arr[i]].push_back(-1);
		v[arr[i]].push_back(i);
	}
	cin >> q;
	while(q--){
		int s, e, ans = -1;
		cin >> s >> e;
		for(int i=1; i<=50; i++){
			int j = ran(rd) % (e-s+1) + s;
			int k = arr[j];
			int cnt = upper_bound(v[k].begin(), v[k].end(), e) - lower_bound(v[k].begin(), v[k].end(), s);
            if(cnt > (e-s+1)/2){
				ans = k; break;
			}
		}
		if(ans < 0) cout << "no\n";
		else cout << "yes " << ans << "\n";
	}
}