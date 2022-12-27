/*____________________________________________________________
// started : 12/26/22
// finished: 12/26/22
// problem : https://cses.fi/problemset/task/1679
____________________________________________________________*/

#include <bits/stdc++.h>

#define FOR(i, n) for (int i = 0;i < n;i++)
#define FORO(i, n) for (int i = 1;i < n;i++)
#define ROF(i, n) for (int i = n - 1;i >= 0;i--)
#define ROFO(i, n) for (int i = n - 1;i >= 1;i--)
#define loop while (true) // rust woooo
#define ALL(arr) arr.begin(), arr.end()
#define lower lower_bound 
#define upper upper_bound
#define ll long long
#define uint unsigned int
#define hashmap unordered_map
#define hashset unordered_set
#define p_queue priority_queue
#define pb push_back
#define pf push_front
#define popb pop_back
#define popf pop_front
#define mp make_pair    
#define f first
#define s second
#define endl "\n"
#define BIG_NUMBER 1e18LL
#define BIG_PRIME 999998727899999LL // this number has 15 digits
#define PRIME32 (int)(1e9 + 7) 
#define ASCII_PRIME (int)257
#define ALPHA_PRIME (int)29

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m; cin >> n >> m;
    vector<vector<int>> edges(n, vector<int>());
    vector<int> indeg(n, 0);

    FOR(i, m) {
        int a, b; cin >> a >> b;
        a--; b--;
        edges[a].pb(b);
        indeg[b]++;
    }

    queue<int> leaves;
    FOR(i, n) {
        if (indeg[i] == 0) {
            leaves.push(i);
        }
    }

    vector<int> output;
    while (!leaves.empty()) {
        auto curr = leaves.front(); leaves.pop();
        output.pb(curr + 1);

        for (auto edge : edges[curr]) {
            indeg[edge]--;
            if (indeg[edge] == 0) {
                leaves.push(edge);
            }
        }
    }

    if (output.size() < n) {
        cout << "IMPOSSIBLE" << endl;
    }
    else {
        for (auto i : output) {
            cout << i << " ";
        }
        cout << endl;
    }

    return 0;
}
