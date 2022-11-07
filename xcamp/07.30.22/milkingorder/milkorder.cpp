/*____________________________________________________________
// started : 08/15/22
// finished: 08/15/22
// problem : http://www.usaco.org/index.php?page=viewproblem2&cpid=838
____________________________________________________________*/

#include <bits/stdc++.h>

#define FOR(n) for (int i = 0;i < n;i++)
#define FORO(n) for (int i = 1;i < n;i++)
#define ROF(n) for (int i = n - 1;i >= 0;i--)
#define ROFO(n) for (int i = n - 1;i >= 1;i--)
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
#define mp make_pair    
#define f first
#define s second
#define endl "\n"
#define BIG_NUMBER 1e18
#define BIG_PRIME 999998727899999 // this number has 15 digits
#define PRIME32 1e9 + 7 
#define ASCII_PRIME 257
#define ALPHA_PRIME 29

using namespace std;

string check(vector<vector<int>>& conditions, const int n, int x) {
    // build a graph according to first m conditions
    vector<vector<int>> edges(n);
    vector<int> indeg(n, 0);

    FOR(min(x, (int)conditions.size())) {
        for (int j = 0;j < conditions[i].size() - 1;j++) {
            int a = conditions[i][j], b = conditions[i][j + 1];

            edges[a].pb(b);
            indeg[b]++;
        }
    }

    // run topsort
    string order = "";
    int processed = 0;
    p_queue<int, vector<int>, greater<int>> topsort;

    FOR(n) {
        if (indeg[i] == 0)
            topsort.push(i);
    }

    while (!topsort.empty()) {
        int curr_node = topsort.top();

        order += to_string(curr_node + 1) + " ";
        processed++;
        topsort.pop();

        for (int dest : edges[curr_node]) {
            indeg[dest]--;
            if (indeg[dest] == 0) {
                topsort.push(dest);
            }
        }

    }

    if (processed == n) {
        return order;
    }
    else {
        return "-1";
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("milkorder.in", "r", stdin);
    freopen("milkorder.out", "w", stdout);

    int n, m; cin >> n >> m;

    vector<vector<int>> conditions(m);
    FOR(m) {
        int size; cin >> size;
        conditions[i] = vector<int>(size);
        for (int j = 0;j < size;j++) {
            cin >> conditions[i][j];
            conditions[i][j]--;
        }
    }

    int low = 0, high = m + 5;
    string ans = "0";

    while (low <= high) {
        int mid = (low + high) / 2;
        string res = check(conditions, n, mid);

        if (res == "-1") {
            high = mid - 1;
        }
        else {
            low = mid + 1;
            ans = res;
        }
    }

    cout << ans.substr(0, ans.length() - 1);

    return 0;
}
