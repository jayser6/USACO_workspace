// started : 05/06/22
// finished: 05/06/22
// problem : http://www.usaco.org/index.php?page=viewproblem2&cpid=644

// main idea: go backwards(i.e. everything is closed at first)

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

ifstream fin("closing.in");
ofstream fout("closing.out");

int findHead(int curr, vector<pair<int, int>>& comp) {
    if (curr == comp[curr].f) {
        return curr;
    }

    comp[curr].f = findHead(comp[curr].f, comp);
    return comp[curr].f;
}

void merge(int a, int b, vector<pair<int, int>>& comp) {
    if (comp[a].s > comp[b].s) {
        comp[b].f = a;
        comp[a].s += comp[b].s;
    }
    else {
        comp[a].f = b;
        comp[b].s += comp[a].s;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m; fin >> n >> m;

    vector<vector<int>> edges(n); // false -> edge is not active
    for (int i = 0;i < m;i++) {
        int a, b; fin >> a >> b;
        a--; b--;

        edges[a].pb(b);
        edges[b].pb(a);
    }

    vector<int> input(n);
    for (int& curr : input) {
        fin >> curr;
        curr--;
    }

    vector<bool> isActive(n, false);
    vector<pair<int, int>> comp(n); // parent, component size
    for (int i = 0;i < n;i++) {
        comp[i] = mp(i, 1);
    }
    isActive[input[n - 1]] = true;

    vector<string> output(n);
    output[n - 1] = "YES";
    for (int i = n - 2;i >= 0;i--) {
        int currNode = input[i];
        isActive[currNode] = true;

        for (int dest : edges[currNode]) {
            int aHead = findHead(currNode, comp);
            int bHead = findHead(dest, comp);

            if (isActive[dest] && aHead != bHead) {
                merge(aHead, bHead, comp);
            }
        }

        output[i] = (comp[findHead(currNode, comp)].s == n - i) ? "YES" : "NO";
    }

    for (string curr : output) {
        fout << curr << endl;
    }
}