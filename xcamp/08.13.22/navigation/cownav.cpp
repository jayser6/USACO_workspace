/*____________________________________________________________
// started : 01/01/23
// finished: 01/01/23
// problem : http://www.usaco.org/index.php?page=viewproblem2&cpid=695
____________________________________________________________*/

#include <bits/stdc++.h>
using namespace std;

#define debug(x) #x << ": " << x << ", "
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
#define BIG INT_MAX 
#define BIGGER (ll)LLONG_MAX
#define PRIME64 (ll)999998727899999 // this number has 15 digits
#define PRIME32 (int)(1e9 + 7) 
#define ASCII_PRIME (int)257
#define ALPHA_PRIME (int)29

const int MAX_N = 20;
char grid[MAX_N][MAX_N];
int dist[4][MAX_N][MAX_N][4][MAX_N][MAX_N];
pair<int, int> dir[] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };

bool in_bound(int n, int y, int x) {
    return 0 <= y && y < n && 0 <= x && x < n;
}

bool can_move(int n, int y, int x) {
    return in_bound(n, y, x) && grid[y][x] == 'E';
}

struct state {
    int d1, y1, x1, d2, y2, x2;
    state(int d1, int y1, int x1, int d2, int y2, int x2): d1(d1), y1(y1), x1(x1), d2(d2), y2(y2), x2(x2) {}
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("cownav.in", "r", stdin);
    freopen("cownav.out", "w", stdout);

    int n; cin >> n;
    FOR(i, n) FOR(j, n) cin >> grid[i][j];

    for (auto& a : dist) for (auto& b : a) for (auto& c : b) for (auto& d : c) for (auto& e : d) for (auto& f : e) f = BIG;

    const int sx = 0, sy = n - 1, ex = n - 1, ey = 0;
    queue<tuple<int, int, int, int, int, int>> bfs;
    bfs.push({ 0, sy, sx, 1, sy, sx });
    dist[0][sy][sx][1][sy][sx] = 0;

    while (!bfs.empty()) {
        auto [d1, y1, x1, d2, y2, x2] = bfs.front(); bfs.pop(); // d for direction

        if (y1 == ey && x1 == ex && y2 == ey && x2 == ex) {
            cout << dist[d1][y1][x1][d2][y2][x2] << endl;
            return 0;
        }

        int next_dist = dist[d1][y1][x1][d2][y2][x2] + 1;
        // try moving forward
        int n_y1 = y1 + dir[d1].f, n_x1 = x1 + dir[d1].s;
        if (y1 == ey && x1 == ex || !can_move(n, n_y1, n_x1)) n_y1 = y1, n_x1 = x1;

        int n_y2 = y2 + dir[d2].f, n_x2 = x2 + dir[d2].s;
        if (y2 == ey && x2 == ex || !can_move(n, n_y2, n_x2)) n_y2 = y2, n_x2 = x2;

        if (next_dist < dist[d1][n_y1][n_x1][d2][n_y2][n_x2]) {
            dist[d1][n_y1][n_x1][d2][n_y2][n_x2] = next_dist;
            bfs.push({ d1, n_y1, n_x1, d2, n_y2, n_x2 });
        }

        // try turning left
        int n_d1 = (d1 + 3) % 4, n_d2 = (d2 + 3) % 4;
        if (next_dist < dist[n_d1][y1][x1][n_d2][y2][x2]) {
            dist[n_d1][y1][x1][n_d2][y2][x2] = next_dist;
            bfs.push({ n_d1, y1, x1, n_d2, y2, x2 });
        }

        // try turning right
        n_d1 = (d1 + 1) % 4, n_d2 = (d2 + 1) % 4;
        if (next_dist < dist[n_d1][y1][x1][n_d2][y2][x2]) {
            dist[n_d1][y1][x1][n_d2][y2][x2] = next_dist;
            bfs.push({ n_d1, y1, x1, n_d2, y2, x2 });
        }
    }

    return 0;
}
