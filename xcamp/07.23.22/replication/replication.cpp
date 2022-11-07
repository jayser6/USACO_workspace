/*____________________________________________________________
// started : 08/03/22
// finished:
// problem : http://www.usaco.org/index.php?page=viewproblem2&cpid=1065
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

bool in_bound(int n, int y, int x) {
    return (y >= 0) && (y < n) && (x >= 0) && (x < n);
}

int main() {
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);

    freopen("replication.in", "r", stdin);

    int n, d; cin >> n >> d;

    // vectors storing the information from the three BFS
    vector<vector<char>> grid(n, vector<char>(n));
    vector<vector<int>> d_to_wall(n, vector<int>(n, PRIME32));
    vector<vector<bool>> can_reach(n, vector<bool>(n, false));
    vector<vector<int>> sourceLen(n, vector<int>(n, -1));

    // utility vectors
    vector<pair<int, int>> dir = { { 0, 1 }, { 0, -1 }, { 1, 0 }, { -1, 0 } };

    // queues for the BFS
    queue<pair<pair<int, int>, int>> cells;
    queue<pair<pair<int, int>, int>> centers; // s.s stores radius 
    queue<pair<pair<int, int>, pair<int, int>>> all_reach; // source, curr

    // get input & give initial values to the vectors
    for (int i = 0;i < n;i++) {
        for (int j = 0;j < n;j++) {
            cin >> grid[i][j];
            if (grid[i][j] == '#') {
                cells.push({ { i, j }, 0 });
                d_to_wall[i][j] = 0;
            }
            else if (grid[i][j] == 'S') {
                can_reach[i][j] = true;
                centers.push({ { i, j }, 0 });
            }
        }
    }

    cout << "checkpoint 1" << endl;

    // find the distance from each cell to the closest wall
    while (!cells.empty()) {
        int y = cells.front().f.f;
        int x = cells.front().f.s;
        int dist = cells.front().s;
        cells.pop();
        if (dist > d_to_wall[y][x]) {
            continue;
        }

        FOR(4) {
            int newY = y + dir[i].f;
            int newX = x + dir[i].s;
            if (in_bound(n, newY, newX) && (dist + 1 < d_to_wall[newY][newX])) {
                cells.push({ { newY, newX }, dist + 1 });
                d_to_wall[newY][newX] = dist + 1;
            }
        }
    }

    cout << "checkpoint 2" << endl;

    // find all the squares that the original robot can get to
    // the last implementation sucked so ill do it again here pepeW
    while (!centers.empty()) {
        int y = centers.front().f.f;
        int x = centers.front().f.s;
        int len = centers.front().s;
        centers.pop();

        if (d * d_to_wall[y][x] <= len) {
            continue;
        }

        FOR(4) {
            int newY = y + dir[i].f;
            int newX = x + dir[i].s;

            if (!in_bound(n, newY, newX) || grid[newY][newX] == '#') {
                // don't go this way
                continue;
            }

            if (!can_reach[newY][newX] && (d * d_to_wall[newY][newX] > len)) {
                centers.push({ { newY, newX }, len + 1 });
                // sourceLen[newY][newX] = d_to_wall[newY][newX];
                can_reach[newY][newX] = true;
            }
        }
    }

    cout << "checkpoint 3" << endl;

    // finally, look for all the cells that may be covered. 
    for (int i = 0;i < n;i++) {
        for (int j = 0;j < n;j++) {
            if (can_reach[i][j]) {
                all_reach.push({ { i, j }, { i, j } });
            }
        }
    }

    // cout << endl;
    // for (int i = 0;i < n;i++) {
    //     for (int j = 0;j < n;j++) {
    //         cout << d_to_wall[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    // cout << endl;
    // for (int i = 0;i < n;i++) {
    //     for (int j = 0;j < n;j++) {
    //         cout << can_reach[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    int num = 0;
    int notUsed = 0;
    int used = 0;
    while (!all_reach.empty()) {
        num++;
        pair<int, int> source = all_reach.front().f;
        pair<int, int> curr = all_reach.front().s;
        all_reach.pop();
        if (sourceLen[curr.f][curr.s] > d_to_wall[source.f][source.s]) {
            notUsed++;
            continue;
        }
        used++;

        int dist = abs(source.f - curr.f) + abs(source.s - curr.s);
        FOR(4) {
            int newY = curr.f + dir[i].f;
            int newX = curr.s + dir[i].s;

            if (!in_bound(n, newY, newX) || (grid[newY][newX] == '#')) {
                continue;
            }

            if ((d_to_wall[source.f][source.s] - 1 > dist) && (d_to_wall[source.f][source.s] > sourceLen[newY][newX])) {
                all_reach.push({ source, { newY, newX } });
                can_reach[newY][newX] = true;
                sourceLen[newY][newX] = d_to_wall[source.f][source.s];
            }
        }
    }

    cout << num << " " << notUsed << endl;

    int ans = 0;
    for (int i = 0;i < n;i++) {
        for (int j = 0;j < n;j++) {
            if (can_reach[i][j]) ans++;
        }
    }

    cout << ans;

    return 0;
}
