/*____________________________________________________________
// started : 12/18/22
// finished:
// problem :
____________________________________________________________*/

#include <bits/stdc++.h>

#define FOR(i, n) for (int i = 0;i < n;i++)
#define FORO(i, n) for (int i = 1;i < n;i++)
#define ROF(i, n) for (int i = n - 1;i >= 0;i--)
#define ROFO(i, n) for (int i = n - 1;i >= 1;i--)
#define ALL(arr) arr.begin(), arr.end()
#define lower lower_bound 
#define upper upper_bound
#define ll long long
#define hashmap unordered_map
#define hashset unordered_set
#define p_queue priority_queue
#define pb push_back
#define f first
#define s second
#define endl "\n"
#define BIG_NUMBER 1e18LL
#define BIG_PRIME 999998727899999LL
#define PRIME32 (int)(1e9 + 7) 

using namespace std;

void print_output(vector<vector<pair<int, ll>>>& edges, vector<int>& new_indeg) {
    queue<int> leaves;

    FOR(i, new_indeg.size()) {
        if (new_indeg[i] == 0) {
            leaves.push(i);
        }
    }

    while (!leaves.empty()) {
        int curr = leaves.front(); leaves.pop();

        for (auto& edge : edges[curr]) {
            cout << curr + 1 << " " << edge.f + 1 << " " << edge.s << endl;
            new_indeg[edge.f]--;
            if (new_indeg[edge.f] == 0) {
                leaves.push(edge.f);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;

    int sum = 0;
    vector<ll> barns(n);
    FOR(i, n) {
        cin >> barns[i];
        sum += barns[i];
    }

    int avg = sum / n;

    vector<vector<int>> edges(n, vector<int>());
    vector<int> indeg(n, 0);
    FOR(i, n - 1) {
        int a, b; cin >> a >> b; a--; b--;

        edges[a].pb(b);
        edges[b].pb(a);
        indeg[a]++;
        indeg[b]++;
    }

    queue<int> leaves;
    FOR(i, n) {
        if (indeg[i] == 1) {
            leaves.push(i);
        }
    }

    vector<vector<pair<int, ll>>> output(n, vector<pair<int, ll>>());
    vector<bool> visited(n, false);
    vector<int> new_indeg(n, 0);
    int orders = 0;

    while (!leaves.empty()) {
        int curr = leaves.front(); leaves.pop();
        visited[curr] = true;

        bool can_start;
        if (barns[curr] > avg)
            can_start = true;
        else
            can_start = false;


        for (int next : edges[curr]) {
            if (visited[next])
                continue;

            indeg[next]--;
            if (indeg[next] == 1) {
                leaves.push(next);
            }

            if (barns[curr] < avg) {
                output[next].pb({ curr, avg - barns[curr] });
                orders++;
                new_indeg[curr]++;
            }
            else if (barns[curr] > avg) {
                output[curr].pb({ next, barns[curr] - avg });
                orders++;
                new_indeg[next]++;
            }
            barns[next] += barns[curr] - avg;
            barns[curr] = avg;
        }
    }

    cout << orders << endl;
    print_output(output, new_indeg);

    return 0;
}
