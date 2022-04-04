#include <bits/stdc++.h>
using namespace std;
typedef struct {int s;int e;int val;}contest;
int main(){
    int N,temp,iter=0,MAX = 0;
    scanf("%d",&N);
    vector<contest> con(N);
    for(int i=0;i<N;i++){scanf("%d %d %d",&con[i].s,&con[i].e,&con[i].val);}
    sort(con.begin(),con.end(),[](const contest &a,const contest &b){return a.s ^ b.s ? a.s < b.s : a.e < b.e;});
    vector<int> Dyn(N,0);
    Dyn[N-1] = con[N-1].val;
    for(int i=N-2;i>=0;i--){
        Dyn[i] = max(con[i].val , Dyn[i+1]);
        auto iter = upper_bound(con.begin(),con.end(),contest{con[i].e,-1,-1},[](const contest &a,const contest &b){return a.s<b.s;});
        if(iter != con.end()){
            Dyn[i] = max( Dyn[i] , Dyn[iter-con.begin()] + con[i].val);
        }
    }
    cout<<Dyn[0];
}

// #include <bits/stdc++.h>
// #define fastio cin.tie(0)->sync_with_stdio(0)
// using namespace std;

// struct Info { int s, e, val; };

// int main() {
// 	fastio;
// 	int n; cin >> n;
// 	vector<Info> I(n);
// 	for (auto& [s, e, val] : I) cin >> s >> e >> val;
// 	sort(I.begin(), I.end(), [](const Info& a, const Info& b) { return a.s ^ b.s ? a.s < b.s : a.e < b.e; });

// 	vector<int> DP(n);
// 	for (int i = n - 1; i >= 0; i--) {
// 		DP[i] = I[i].val;
// 		if (i != n - 1) DP[i] = max(DP[i], DP[i + 1]);
// 		auto it = upper_bound(I.begin(), I.end(), Info{ I[i].e, -1, -1 }, [](const Info& a, const Info& b) { return a.s < b.s; });
// 		if (it != I.end()) DP[i] = max(DP[i], I[i].val + DP[it - I.begin()]);
//         for(auto K:DP){
//             cout.width(2);
//             cout<<K;
//         }cout<<endl;
//         cout<<endl;
// 	}
// 	cout << DP[0] << '\n';
// }