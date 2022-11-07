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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int r, c, n, m; cin >> r >> c >> n >> m;

    vector<vector<int>> map(r + 2, vector<int>(c + 2, -1)); // -1 -> wall,  0 -> empty, 1 -> /, 2 -> \, 3 -> start, 4 -> end
    map[1][0] = 3;
    map[r][c + 1] = 4;
    for (int i = 1;i <= r;i++) {
        for (int j = 1;j <= c;j++) {
            map[i][j] = 0;
        }
    }

    for (int i = 0;i < n;i++) {
        int y, x; cin >> y >> x;
        map[y][x] = 1;
    }
    for (int i = 0;i < m;i++) {
        int y, x; cin >> y >> x;
        map[y][x] = 2;
    }

    vector<vector<pair<bool, int>>> firstPath(r + 2, vector<pair<bool, int>>(c + 2, mp(false, -1)));
    int y = 1, x = 0;
    int dir = 3;
    vector<pair<int, int>> move = { mp(-1, 0), mp(1, 0), mp(0, -1), mp(0, 1) };
    while (map[y][x] != -1) {
        firstPath[y][x].f = true;
        firstPath[y][x].s = dir;

        if (map[y][x] == 4) {
            cout << "Moo";
            return 0;
        }
        else if (map[y][x] == 1) {
            if (dir == 0) {
                dir = 3;
            }
            else if (dir == 1) {
                dir = 2;
            }
            else if (dir == 2) {
                dir = 1;
            }
            else {
                dir = 0;
            }
        }
        else if (map[y][x] == 2) {
            if (dir == 0) {
                dir = 2;
            }
            else if (dir == 1) {
                dir = 3;
            }
            else if (dir == 2) {
                dir = 0;
            }
            else {
                dir = 1;
            }
        }

        y += move[dir].f;
        x += move[dir].s;
    }

    // for (int i = 0; i < r + 2;i++) {
    //     for (int j = 0;j < c + 2;j++) {
    //         cout << firstPath[i][j].s << " ";
    //     }
    //     cout << endl;
    // }

    set <pair<pair<int, int>, string>> output;
    y = r; x = c + 1;
    dir = 2;
    while (map[y][x] != -1) {
        if (firstPath[y][x].f && map[y][x] == 0) {
            vector<int> sigDir(4, 0);
            sigDir[dir]++;
            sigDir[firstPath[y][x].s]++;

            // cout << y << " " << x << " ";
            if ((sigDir[0] == 1 && sigDir[3] == 1) || (sigDir[2] == 1 && sigDir[1] == 1)) {
                // cout << "\\" << endl;
                output.insert(mp(mp(y, x), "\\"));
            }
            else {
                // cout << "/" << endl;
                output.insert(mp(mp(y, x), "/"));
            }
        }

        if (map[y][x] == 1) {
            if (dir == 0) {
                dir = 3;
            }
            else if (dir == 1) {
                dir = 2;
            }
            else if (dir == 2) {
                dir = 1;
            }
            else {
                dir = 0;
            }
        }
        else if (map[y][x] == 2) {
            if (dir == 0) {
                dir = 2;
            }
            else if (dir == 1) {
                dir = 3;
            }
            else if (dir == 2) {
                dir = 0;
            }
            else {
                dir = 1;
            }
        }

        y += move[dir].f;
        x += move[dir].s;
    }

    for (auto it = output.begin();it != output.end();it++) {
        cout << it->f.f << " " << it->f.s << " " << it->s << endl;
    }

    if (output.empty()) {
        cout << "Moo Moo";
    }
}