/*____________________________________________________________
// started : 12/27/22
// finished: 12/27/22
// problem : https://codeforces.com/group/eZhSssSlea/contest/418818/problem/C
____________________________________________________________*/

#include <bits/stdc++.h>

#define FOR(curr, n) for (int curr = 0;curr < n;curr++)
#define FORO(curr, n) for (int curr = 1;curr < n;curr++)
#define ROF(curr, n) for (int curr = n - 1;curr >= 0;curr--)
#define ROFO(curr, n) for (int curr = n - 1;curr >= 1;curr--)
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
#define BIG_INT64 (ll)1e18
#define PRIME64 (ll)999998727899999 // this number has 15 digits
#define PRIME32 (int)(1e9 + 7) 
#define ASCII_PRIME (int)257
#define ALPHA_PRIME (int)29

using namespace std;

// also check the negative of these vectors 
const pair<int, int> dir[] = { { 0, 1 }, { 1, 0 }, { 1, -1 } };

struct comp {
    int parent;
    int size;
    int fences;
    comp() {}
    comp(int parent, int size, int fences) {
        this->parent = parent;
        this->size = size;
        this->fences = fences;
    }
};

struct operation {
    int type;
    int x;
    int y;
    operation() {}
    operation(int type, int x, int y) {
        this->type = type;
        this->x = x;
        this->y = y;
    }
};

int find_head(vector<comp>& dsu, int node) {
    if (dsu[node].parent == node) {
        return node;
    }
    return dsu[node].parent = find_head(dsu, dsu[node].parent);
}

void merge(vector<comp>& dsu, int a, int b) {
    int a_head = find_head(dsu, a);
    int b_head = find_head(dsu, b);

    if (a_head == b_head) {
        return;
    }

    int big, small;
    if (dsu[a_head].size > dsu[b_head].size) {
        big = a_head;
        small = b_head;
    }
    else {
        big = b_head;
        small = a_head;
    }

    dsu[big].size += dsu[small].size;
    dsu[small].parent = big;
    dsu[big].fences += dsu[small].fences - 2;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;

    int num_nodes;
    vector<comp> dsu;
    map<pair<int, int>, int> coord_to_id; // coord to node index

    FOR(i, n) {
        int type, x, y; cin >> type >> x >> y;

        if (type == 1) {
            coord_to_id[{x, y}] = num_nodes;
            dsu.pb(comp(num_nodes, 1, 6));

            // check all directions, find the number of shared edges(sides), use
            // DSU if necessary
            for (int i = 0;i < 2;i++) {
                int a = (i == 0) ? 1 : -1;

                for (auto curr : dir) {
                    int x2 = x + a * curr.f;
                    int y2 = y + a * curr.s;
                    auto it = coord_to_id.find({ x2, y2 });

                    // this check is unnecessary because the merge function
                    // already takes care of the case where a_head = b_head
                    if (it != coord_to_id.end()) {
                        int a_head = find_head(dsu, it->s);
                        int b_head = find_head(dsu, num_nodes);

                        if (a_head != b_head) {
                            merge(dsu, a_head, b_head);
                        }
                        else {
                            dsu[a_head].fences -= 2;
                        }
                    }
                }
            }

            num_nodes++;
        }
        else {
            int head = find_head(dsu, coord_to_id[{ x, y }]);
            cout << dsu[head].fences << endl;
        }
    }

    return 0;
}
