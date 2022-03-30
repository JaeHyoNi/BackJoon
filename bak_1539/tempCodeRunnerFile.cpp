
#include <bits/stdc++.h>
using namespace std;

#define FOR(i, n) for(int i=0; i<(n); ++i)

typedef long long lld;

map<int, int> h1, h2;

int main() {
    int n;
    scanf("%d", &n);

    lld ans = 0;
    FOR(t, n) {
        int x;
        scanf("%d", &x);
        auto l = h1.lower_bound(x);
        auto r = h2.lower_bound(-x);
        int m = 0;
        if (l != h1.end()) m = max(m, l->second);
        if (r != h2.end()) m = max(m, r->second);
        h1[x] = h2[-x] = 1 + m;
        ans += 1LL + m;
    }
    printf("%lld\n", ans);

    return 0;
}