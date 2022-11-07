// THIS VERSION DOESN"T WORK AND IM TOO LAZY TO FIX IT

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

ifstream fin("visits.in");

ll volumeSubtract = 0;
vector<vector<pair<int, ll>>> edges;
vector<bool> visited;
vector<bool> cycleVisited;

void findCycle(int index, int parent, int target, ll minV) {
    cycleVisited[index] = true;
    if (index == target) {
        volumeSubtract += minV;
        return;
    }

    for (pair<int, ll> dest : edges[index]) {
        if (dest.f != parent && !cycleVisited[dest.f]) {
            findCycle(dest.f, index, target, min(minV, dest.s));
        }
    }
}

void findTree(int index, int parent) {
    visited[index] = true;

    for (pair<int, ll> dest : edges[index]) {
        if (dest.f != parent && !visited[dest.f]) {
            findTree(dest.f, index);
        }
        else if (dest.f != parent) {
            findCycle(dest.f, index, index, dest.s);
        }
    }
}

int main() {
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);

    int n; fin >> n;

    ll output = 0;
    edges = vector<vector<pair<int, ll>>>(n);
    visited = vector<bool>(n, false);
    cycleVisited = vector<bool>(n, false);
    for (int i = 0;i < n;i++) {
        int dest; ll v; fin >> dest >> v;
        dest--;
        output += v;
        edges[i].pb(mp(dest, v));
        edges[dest].pb(mp(i, v));
    }

    for (int i = 0;i < n;i++) {
        if (!visited[i]) {
            findTree(i, -1);
        }
    }

    cout << output - volumeSubtract;
}
