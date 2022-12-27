/*____________________________________________________________
// started : 12/26/22
// finished: 12/26/22
// problem : https://cses.fi/problemset/task/1666/
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

int find_head(vector<pair<int, int>>& comp, int curr) {
    if (curr == comp[curr].f) {
        return curr;
    }

    comp[curr].f = find_head(comp, comp[curr].f);
    return comp[curr].f;
}

void merge(vector<pair<int, int>>& comp, int a, int b) {
    int a_head = find_head(comp, a);
    int b_head = find_head(comp, b);

    if (a_head == b_head) {
        return;
    }

    if (comp[a_head].s > comp[b_head].s) {
        comp[b_head].f = a_head;
        comp[a_head].s += comp[b_head].s;
    }
    else {
        comp[a_head].f = b_head;
        comp[b_head].s += comp[a_head].s;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m; cin >> n >> m;
    vector<pair<int, int>> comp(n); // parent, size of component

    FOR(i, n) {
        comp[i] = { i, 1 };
    }

    FOR(i, m) {
        int a, b; cin >> a >> b; a--; b--;

        int a_head = find_head(comp, a);
        int b_head = find_head(comp, b);

        if (a_head != b_head) {
            merge(comp, a, b);
        }
    }

    set<int> heads;
    FOR(i, n) {
        heads.insert(find_head(comp, i));
    }

    cout << heads.size() - 1 << endl;
    int to = -1;
    int from = -1;
    for (auto it = heads.begin();it != heads.end();it++) {
        from = to;
        to = *it;

        if (from != -1) {
            cout << from + 1 << " " << to + 1 << endl;
        }
    }


    return 0;
}
