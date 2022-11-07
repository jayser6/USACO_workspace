// started : 01/25/22
// finished: 01/25/22
// problem : Solve the Maze (CF) - https://codeforces.com/contest/1365/problem/D

#include <bits/stdc++.h>

#define ALL(arr) arr.begin(), arr.end()
#define ll long long
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define endl "\n"

using namespace std;

void DFS(int y, int x, int n, int m, int& goodGuysCnt, vector<vector<char>>& grid) {
    if (grid[y][x] == 'G') {
        goodGuysCnt++;
    }
    else if (grid[y][x] == 'B') {
        goodGuysCnt--; // if the bad guy can somehow cross, just mess up goodguysCnt
    }

    grid[y][x] = '#';

    // dfs to other places
    for (int j = -1;j <= 1;j++) {
        for (int k = -1;k <= 1;k++) {
            // make sure j and k only check the four directions around y and x
            if ((y + j < 0) || (y + j >= n) || (x + k < 0) || (x + k >= m) || (j != 0 && k != 0) || (j == 0 && k == 0)) {
                continue;
            }

            // check if grid[y + j][x + k] is a wall
            if (grid[y + j][x + k] != '#') {
                DFS(y + j, x + k, n, m, goodGuysCnt, grid);
            }
        }
    }
}

void solve(int caseNum) {
    int n, m; cin >> n >> m;

    vector<vector<char>> grid(n, vector<char>(m));
    int numGoodGuys = 0;
    // vector<pair<int, int>> goodGuys;
    vector<pair<int, int>> badGuys;
    for (int i = 0;i < n;i++) {
        for (int j = 0;j < m;j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 'B') {
                badGuys.pb(mp(i, j));
            }
            else if (grid[i][j] == 'G') {
                numGoodGuys++;
                //goodGuys.pb(mp(i, j));
            }
        }
    }

    // replace all the walls
    for (int i = 0;i < badGuys.size();i++) {
        int y = badGuys[i].f, x = badGuys[i].s;
        for (int j = -1;j <= 1;j++) {
            for (int k = -1;k <= 1;k++) {
                // make sure j and k only check the four directions around y and x
                if ((y + j < 0) || (y + j >= n) || (x + k < 0) || (x + k >= m) || (j != 0 && k != 0) || (j == 0 && k == 0)) {
                    continue;
                }

                // make sure grid[y + j][x + k] doesn't contain a bad guy or a good guy
                if ((grid[y + j][x + k] == 'G') || (grid[y + j][x + k] == 'B')) {
                    continue;
                }
                grid[y + j][x + k] = '#';
            }
        }
    }

    if (numGoodGuys > 0 && grid[n - 1][m - 1] == '#') {
        cout << "NO" << endl;
        return;
    }
    else if (numGoodGuys == 0) {
        cout << "YES" << endl;
        return;
    }

    // floodfill starting n - 1, m - 1 and see if all the good guys are in one fill
    int goodGuysCnt = 0;
    DFS(n - 1, m - 1, n, m, goodGuysCnt, grid);

    if (goodGuysCnt != numGoodGuys) {
        cout << "NO" << endl;
    }
    else {
        cout << "YES" << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    for (int i = 0;i < t;i++) {
        solve(i);
    }
}
