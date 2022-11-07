/*____________________________________________________________
// started : 08/23/22
// finished: 08/23/22
// problem : http://www.usaco.org/index.php?page=viewproblem2&cpid=282
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
#define popb pop_back
#define popf pop_front
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

struct state {
    int y, x;
    int dir, val; // -1 or 1

    state() {}
    state(int y, int x, int dir, int val) {
        this->y = y;
        this->x = x;
        this->dir = dir;
        this->val = val;
    }
};

bool inbound(const int max, int val) {
    return (val >= 0) && (val < max);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("gravity.in", "r", stdin);
    freopen("gravity.out", "w", stdout);

    /* input */
    int n, m; cin >> n >> m;

    vector<vector<char>> grid(n, vector<char>(m));
    deque<state> dijkstra;
    vector<vector<vector<int>>> min_to(n, vector<vector<int>>(m, vector<int>(2, PRIME32))); // 0 -> dir = -1, 1 -> dir = 1

    for (int i = 0;i < n;i++) {
        for (int j = 0;j < m;j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 'C') {
                dijkstra.pb(state(i, j, 1, 0));
                min_to[i][j][1] = 0;
            }
        }
    }

    /* 0-1 dijkstra */


    int dir_x[] = { -1, 1 };

    while (!dijkstra.empty()) {
        state curr = dijkstra.front();
        int dir_i = (curr.dir == -1) ? 0 : 1;

        dijkstra.popf();
        if (curr.val > min_to[curr.y][curr.x][dir_i]) {
            continue;
        }

        // print answer if the dijkstra reaches 'D'
        if (grid[curr.y][curr.x] == 'D') {
            cout << curr.val;
            return 0;
        }

        // check for what is below
        int below = curr.y + curr.dir;

        // case 1: there is no "below", meaning we fall off the map
        if (!inbound(n, below)) {
            continue;
        }
        // case 2: the cell below is empty, so fall
        else if (grid[below][curr.x] != '#') {
            if (min_to[below][curr.x][dir_i] > curr.val) {
                min_to[below][curr.x][dir_i] = curr.val;
                dijkstra.pf(state(below, curr.x, curr.dir, curr.val));
            }
        }
        // case 3: the cell below is a ground
        else {
            // try moving left and right
            FOR(2) {
                int new_x = curr.x + dir_x[i];

                if (inbound(m, new_x) && (grid[curr.y][new_x] != '#') && (min_to[curr.y][new_x][dir_i] > curr.val)) {
                    min_to[curr.y][new_x][dir_i] = curr.val;
                    dijkstra.pf(state(curr.y, new_x, curr.dir, curr.val));
                }
            }

            // try flipping the gravity
            int new_dir = -1 * curr.dir;
            int new_val = curr.val + 1;

            dir_i = !dir_i;

            if (min_to[curr.y][curr.x][dir_i] > new_val) {
                min_to[curr.y][curr.x][dir_i] = new_val;
                dijkstra.pb(state(curr.y, curr.x, new_dir, new_val));
            }
        }
    }

    // couldn't reach 'D'
    cout << -1;

    return 0;
}
