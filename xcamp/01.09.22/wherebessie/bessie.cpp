// started : 01/09/22
// finished: ???

#include <bits/stdc++.h>

#define ll long long
#define pb push_back
#define mp make_pair
#define f first
#define s second

using namespace std;

bool isInBound(int y, int x, int yLower, int xLower, int yUpper, int xUpper) {
    bool output = (y >= yLower) && (y <= yUpper) && (x >= xLower) && (x <= xUpper);
    return output;
}

int main() {
    int n; cin >> n;

    vector<vector<char>> grid(n, vector<char>(n));
    for (int i = 0;i < n;i++) {
        for (int j = 0;j < n;j++) {
            cin >> grid[i][j];
        }
    }

    vector<pair<pair<int, int>, pair<int, int>>> PCLs; // (y1, x1), (y2, x2)

    for (int y1 = 0;y1 < n;y1++) {
        for (int x1 = 0; x1 < n;x1++) {
            for (int y2 = y1;y2 < n;y2++) {
                for (int x2 = x1;x2 < n;x2++) {
                    char color1 = '!', color2 = '!';
                    int color1Cnt = 0, color2Cnt = 0;
                    vector<vector<bool>> visited(n, vector<bool>(n, false));

                    bool shouldEnd = false;
                    for (int i = y1;i <= y2;i++) {
                        if (shouldEnd) {
                            break;
                        }
                        for (int j = x1;j <= x2;j++) {
                            if (visited[i][j]) {
                                continue; 
                            }

                            if (color1 == '!') {
                                color1 = grid[i][j];
                                color1Cnt++;
                            }
                            else if (grid[i][j] == color1) {
                                color1Cnt++;    
                            }
                            else if (color2 == '!') {
                                color2 = grid[i][j];
                                color2Cnt++;
                            }
                            else if (grid[i][j] == color2) {
                                color2Cnt++;
                            }
                            else {
                                // there are more than 3 colors in this subgrid
                                shouldEnd = true;
                                break;
                            }

                            stack<pair<int, int>> dfs;
                            dfs.push(mp(i, j));
                            while (!dfs.empty()) {
                                int y = dfs.top().f;
                                int x = dfs.top().s;
                                dfs.pop();
                                if (visited[y][x]) {
                                    continue;
                                }
                                visited[y][x] = true;

                                if (isInBound(y + 1, x, y1, x1, y2, x2) && !visited[y + 1][x] && grid[y + 1][x] == grid[y][x]) {
                                    dfs.push(mp(y + 1, x));
                                }
                                if (isInBound(y - 1, x, y1, x1, y2, x2) && !visited[y - 1][x] && grid[y - 1][x] == grid[y][x]) {
                                    dfs.push(mp(y - 1, x));
                                }
                                if (isInBound(y, x + 1, y1, x1, y2, x2) && !visited[y][x + 1] && grid[y][x + 1] == grid[y][x]) {
                                    dfs.push(mp(y, x + 1));
                                }
                                if (isInBound(y, x - 1, y1, x1, y2, x2) && !visited[y][x - 1] && grid[y][x - 1] == grid[y][x]) {
                                    dfs.push(mp(y, x - 1));
                                }
                            }
                        }
                    }

                    if (shouldEnd) { 
                        // there are more than 3 colors in the subgrid and therefore it is not a PCL
                        continue;
                    }

                    // check if the subgrid is a PCL
                    if ((color1Cnt == 1 && color2Cnt >= 2) || (color1Cnt >= 2 && color2Cnt == 1)) {
                        PCLs.pb(mp(mp(y1, x1), mp(y2, x2)));
                    }
                }
            }
        }
    }
    
    // check if any of the PCLs are inside another PCL
    ll answer = 0;
    for (int i = 0 ;i < PCLs.size();i++) {
        bool isPCL = true;
        for (int j = 0;j < PCLs.size();j++) {
            if (j == i) {
                continue;
            }
            if (PCLs[i].f.f >= PCLs[j].f.f && PCLs[i].f.s >= PCLs[j].f.s && 
                PCLs[i].s.f <= PCLs[j].s.f && PCLs[i].s.s <= PCLs[j].s.s) {
                isPCL = false;
            }
        }
        if (isPCL) {
            answer++;
        }
    } 

    cout << answer;
}