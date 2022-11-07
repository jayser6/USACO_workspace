// started : 03/14/22
// finished: 03/14/22
// probelm : https://codeforces.com/contest/1650/problem/C

#include <bits/stdc++.h>

#define ALL(arr) arr.begin(), arr.end()
#define ll long long
#define hashmap unordered_map
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define endl "\n"

using namespace std;

struct P {
    int index;
    ll pos, weight;
};

bool sortPos(P a, P b) {
    return a.pos < b.pos;
}

bool sortWeight(P a, P b) {
    return a.weight < b.weight;
}

void solve() {
    int n, m; cin >> n >> m;

    vector<P> points(m);
    for (int i = 0; i < m;i++) {
        cin >> points[i].pos >> points[i].weight;
        points[i].index = i + 1;
    }

    sort(ALL(points), sortWeight);
    
    ll totalWeight = 0;
    for (int i = 0;i < 2 * n;i++) {
        totalWeight += points[i].weight;
    }
    
    cout << totalWeight << endl;

    sort(points.begin(), points.begin() + 2 * n, sortPos);

    for (int i = 0;i < n;i++) {
        cout << points[i].index << " " << points[2 * n - 1 - i].index << endl;        
    }

    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;

    for (int i = 0;i < t;i++) {
        solve();
    }
}