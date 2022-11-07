// started : 04/22/22
// finished: 04/22/22
// problem : https://cses.fi/problemset/task/1672

#include <bits/stdc++.h>

#define ALL(arr) arr.begin(), arr.end()
#define ll long long
#define hashmap unordered_map
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define endl "\n"
#define BIG_NUMBER (ll)pow(10, 18)

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, q; cin >> n >> m >> q;

    vector<vector<ll>> dist(n, vector<ll>(n, BIG_NUMBER));
    for (int i = 0;i < n;i++) {
        dist[i][i] = 0;
    }

    for (int i = 0;i < m;i++) {
        int a, b; ll c; cin >> a >> b >> c;
        a--; b--;

        dist[a][b] = min(c, dist[a][b]);
        dist[b][a] = min(c, dist[b][a]);
    }

    for (int k = 0;k < n;k++) {
        for (int i = 0;i < n;i++) {
            for (int j = 0;j < n;j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    for (int i = 0;i < q;i++) {
        int a, b; cin >> a >> b;
        a--; b--;

        if (dist[a][b] == BIG_NUMBER) {
            cout << "-1" << endl;
            continue;
        }
        cout << dist[a][b] << endl;
    }

}