/*____________________________________________________________
// started : 09/09/22
// finished: 09/09/22
// problem : http://www.usaco.org/index.php?page=viewproblem2&cpid=575
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

struct state {
    int y, x, dist, dir;
    bool smell;

    state(int y, int x, int dist, int dir, bool smell) {
        this->y = y;
        this->x = x;
        this->dist = dist;
        this->dir = dir;
        this->smell = smell;
    }
};

bool in_bound(pair<int, int> bound, pair<int, int> coord) {
    return (coord.f >= 0) && (coord.f < bound.f) && (coord.s >= 0) && (coord.s < bound.s);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("dream.in", "r", stdin);
    freopen("dream.out", "w", stdout);

    /* input */

    int n, m; cin >> n >> m;

    // vector<vector<int>> grid(n, vector<int>(m));
    int grid[1002][1002];
    FOR(1002) {
        for (int j = 0;j < 1002;j++) {
            grid[i][j] = 0;
        }
    }
    FOR(n) {
        for (int j = 0;j < m;j++) {
            cin >> grid[i][j];
        }
    }

    /* dijkstra */

    // n, m, dir, smell
    // vector<vector<vector<vector<int>>>> dist_to(n, vector<vector<vector<int>>>(m, vector<vector<int>>(4, vector<int>(2, PRIME32))));
    int dist_to[1002][1002][4][2];
    FOR(1002) {
        for (int j = 0;j < 1002;j++) {
            for (int k = 0;k < 4;k++) {
                for (int l = 0;l < 2;l++) {
                    dist_to[i][j][k][l] = PRIME32;
                }
            }
        }
    }
    queue<state> bfs;
    pair<int, int> dir[4] = { { 0,  1 }, { 0, -1 }, { 1, 0 }, { -1, 0 } };

    // prepping to start dijkstra
    FOR(4) {
        dist_to[0][0][i][0] = 0;
    }
    bfs.push(state(0, 0, 0, 0, 0));

    ll processes = 0;

    // run dijkstra
    while (!bfs.empty()) {
        state curr = bfs.front();

        bfs.pop();
        // cout << ++processes << endl;

        bool can_move = false;
        FOR(4) {
            int new_y = curr.y, new_x = curr.x;
            int new_dir = i;

            // special case: the current tile is purple
            if (grid[curr.y][curr.x] == 4) {
                new_y += dir[curr.dir].f;
                new_x += dir[curr.dir].s;
                new_dir = curr.dir;
            }
            else {
                new_y += dir[i].f;
                new_x += dir[i].s;
            }

            if (in_bound({ n, m }, { new_y, new_x })) {
                // check for different colors
                if (grid[new_y][new_x] == 1) {
                    can_move = true;
                    if (dist_to[new_y][new_x][new_dir][curr.smell] == PRIME32) {
                        dist_to[new_y][new_x][new_dir][curr.smell] = curr.dist + 1;
                        bfs.push(state(new_y, new_x, curr.dist + 1, new_dir, curr.smell));
                    }
                }
                else if (grid[new_y][new_x] == 2) {
                    can_move = true;
                    if (dist_to[new_y][new_x][new_dir][true] == PRIME32) {
                        dist_to[new_y][new_x][new_dir][1] = curr.dist + 1;
                        bfs.push(state(new_y, new_x, curr.dist + 1, new_dir, 1));
                    }
                }
                else if ((grid[new_y][new_x] == 3) && curr.smell) {
                    can_move = true;
                    if (dist_to[new_y][new_x][new_dir][curr.smell] == PRIME32) {
                        dist_to[new_y][new_x][new_dir][curr.smell] = curr.dist + 1;
                        bfs.push(state(new_y, new_x, curr.dist + 1, new_dir, curr.smell));
                    }
                }
                else if (grid[new_y][new_x] == 4) {
                    can_move = true;
                    if (dist_to[new_y][new_x][new_dir][0] == PRIME32) {
                        dist_to[new_y][new_x][new_dir][0] = curr.dist + 1;
                        bfs.push(state(new_y, new_x, curr.dist + 1, new_dir, 0));
                    }
                }
            }
        }

        if (!can_move && grid[curr.y][curr.x] == 4) {
            FOR(4) {
                if (curr.dist < dist_to[curr.y][curr.x][i][curr.smell]) {
                    dist_to[curr.y][curr.x][i][curr.smell] = curr.dist;
                    bfs.push(state(curr.y, curr.x, curr.dist, i, curr.smell));
                }
            }
        }
    }

    int ans = PRIME32;
    FOR(4) {
        ans = min(dist_to[n - 1][m - 1][i][0], ans);
        ans = min(dist_to[n - 1][m - 1][i][1], ans);
    }

    if (ans == PRIME32)
        cout << "-1";
    else
        cout << ans;

    return 0;
}
