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
    vector<int> indegree(n, 0);
    for (int i = 0;i < m;i++) {
        int a, b; cin >> a >> b;
        a--; b--;

        edges[a].pb(b);
        edges[b].pb(a);
        indegree[a]++;
        indegree[b]++;
    }

    queue<int> notCycle;
    for (int i = 0;i < n;i++) {
        if (indegree[i] == 1) {
            notCycle.push(i);
        }
    }

    set<pair<int, int>> ans;
    while (!notCycle.empty()) {
        int node = notCycle.front();
        notCycle.pop();

        for (int dest : edges[node]) {
            int a = min(node, dest);
            int b = max(node, dest);
            ans.insert(mp(a, b));
            indegree[dest]--;
            if (indegree[dest] == 1) {
                notCycle.push(dest);
            }
        }
    }

    cout << ans.size() << endl;
    for (pair<int, int> output : ans) {
        cout << (output.f + 1) << " " << (output.s + 1) << endl;
    }
}