// started : 4/15/22 
// finished: 4/15/22
// problem : https://cses.fi/problemset/task/1667

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

    int n, m; cin >> n >> m;

    vector<vector<int>> edges(n);
    for (int i = 0;i < m;i++) {
        int a, b; cin >> a >> b;
        a--; b--;

        edges[a].pb(b);
        edges[b].pb(a);
    }

    vector<int> whereFrom(n, -1);
    queue<int> bfs;
    bfs.push(0);

    while (!bfs.empty()) {
        int curr = bfs.front();
        bfs.pop();

        if (curr == n - 1) {
            break;
        }

        for (int dest : edges[curr]) {
            if (whereFrom[dest] == -1) {
                whereFrom[dest] = curr;
                bfs.push(dest);
            }
        }
    }

    if (whereFrom[n - 1] == -1) {
        cout << "IMPOSSIBLE";
        return 0;
    }

    stack<int> order;
    int curr = n - 1;
    while (true) {
        order.push(curr);
        if (curr == 0) {
            break;
        }

        curr = whereFrom[curr];
    }

    cout << order.size() << endl;
    while (!order.empty()) {
        cout << (order.top() + 1) << " ";
        order.pop();
    }
}
