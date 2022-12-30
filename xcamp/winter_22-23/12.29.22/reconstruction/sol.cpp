// 

#include <bits/stdc++.h>
#pragma GCC optimize ("Ofast")
#pragma GCC target ("avx2")
using namespace std;

#define MOD 1000000007
#define MAXN 500000
#define INF 2e9
#define ll int64_t
#define nl '\n'
#define pb push_back
#define fi first
#define se second

typedef pair<ll, ll> pii;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;cin >> n;
    int u, v;
    map<int, int> m;
    set<int> unused;
    for (int i = 1;i < n;i++) {
        unused.insert(i);
    }
    while (cin >> u >> v) {
        if (v != n) {
            cout << "NO";
            return 0;
        }
        m[u]++;
        unused.erase(u);
    }
    for (auto x : m) {
        if (x.se > x.fi) {
            cout << "NO";
            return 0;
        }
    }
    vector<pii> ans;
    for (auto x : m) {
        int pre = x.fi;
        for (int i = 1;i < x.se;i++) {
            int y = *unused.begin();
            if (y > x.fi) {
                cout << "NO";
                return 0;
            }
            ans.pb({ pre,y });
            unused.erase(y);
            pre = y;
        }
        ans.pb({ pre,x.fi + 1 });
    }
    cout << "YES\n";
    for (auto x : ans) {
        cout << x.fi << " " << x.se << nl;
    }
}