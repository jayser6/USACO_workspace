/*____________________________________________________________
// started : 07/01/22
// finished:
// problem : https://codeforces.com/contest/1627/problem/E
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
#define BIG_NUMBER (ll)1e18
#define MOD (int)1e9 + 7 

using namespace std;

struct Node {
    int index;
    vector<pair<int, ll>> edges; // f -> index of the other node, s -> weight
    Node() {}
    Node(int index) {
        this->index = index;
    }
};

struct cmp {
    bool operator()(const pair<ll, int>& a, const pair<ll, int>& b) const {
        return b.f < a.f;
    }
};

void solve() {
    int n, m, k; cin >> n >> m >> k;

    vector<int> fire(n);
    FOR(n) {
        cin >> fire[i];
    }

    vector<Node> nodes = { Node(0), Node(1) };
    {
        // vector<set<pair<int, int>>> building(n); // set f -> x value of node, s -> node index
        vector<vector<pair<int, int>>> building(n);

        building[0].pb({ 0, 0 });
        building[n - 1].pb({ m - 1, 1 });

        // build all the ladders
        int nodeCnt = 2;
        FOR(k) {
            int a, b, c, d, h; cin >> a >> b >> c >> d >> h;
            a--; b--; c--; d--;

            int node1 = nodeCnt;
            nodes.pb(Node(nodeCnt));
            building[a].pb({ b, nodeCnt });
            nodeCnt++;

            int node2 = nodeCnt;
            nodes.pb(Node(nodeCnt));
            building[c].pb({ d, nodeCnt });
            nodeCnt++;
            nodes[node1].edges.pb({ node2, -h });
        }

        // build edges between horizontally adjacent rooms
        for (int i = 0;i < n;i++) {
            if (building[i].size() <= 1) continue;

            sort(ALL(building[i]));
            pair<int, int> prevNode;
            for (int j = 0;j < building[i].size();j++) {
                pair<int, int> currNode = building[i][j];
                if (j > 0) {
                    ll dmg = abs(currNode.f - prevNode.f) * (ll)fire[i];
                    nodes[prevNode.s].edges.pb({ currNode.s, dmg });
                    nodes[currNode.s].edges.pb({ prevNode.s, dmg });
                }
                prevNode = currNode;
            }
        }
    }

    // run dijkstra and find answer
    vector<ll> dmgTo(nodes.size(), BIG_NUMBER);
    p_queue<pair<ll, int>, vector<pair<ll, int>>, cmp> dijkstra;
    dijkstra.push({ 0, 0 });
    while (!dijkstra.empty()) {
        pair<ll, int> curr = dijkstra.top();
        dijkstra.pop();

        if (curr.f > dmgTo[curr.s] || curr.s == 1) {
            continue;
        }

        for (pair<int, ll> dest : nodes[curr.s].edges) {
            ll next = curr.f + dest.s;
            if (next < dmgTo[dest.f]) {
                dmgTo[dest.f] = next;
                dijkstra.push({ next, dest.f });
            }
        }
    }

    if (dmgTo[1] == BIG_NUMBER) {
        cout << "NO ESCAPE" << endl;
    }
    else {
        cout << dmgTo[1] << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    FOR(t) {
        solve();
    }

    return 0;
}
