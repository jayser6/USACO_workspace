// started : 01/20/22
// finished: 01/21/22
// Problem : Why Did the Cow Cross the Road? (USACO Silver) http://www.usaco.org/index.php?page=viewproblem2&cpid=716

#include <bits/stdc++.h>

#define ll long long
#define pb push_back
#define mp make_pair
#define f first
#define s second

using namespace std;

// ifstream fin("countcross.in");
// ofstream fout("countcross.out");

int n, k, r;
vector<vector<int>> farm; // 0 -> empty, 1 -> cow, 2 -> road

void DFS(int y, int x, int floodNumber, vector<vector<int>>& visited, vector<int>& cowCnt) {
    visited[y][x] = floodNumber;
    if (farm[y][x] == 1) {
        cowCnt[floodNumber]++;
    }

    for (int i = -1;i <= 1;i++) {
        for (int j = -1;j <= 1;j++) {
            if ((i == 0 && j == 0) || (i != 0 && j != 0)) {
                continue;
            }

            if (visited[y + i][x + j] == -1 && farm[y + i][x + j] != 2) {
                DFS(y + i, x + j, floodNumber, visited, cowCnt);
            }
        }
    }
 }

int main() {
    cin >> n >> k >> r;

    farm = vector<vector<int>>((n * 2) + 2, vector<int>((n * 2) + 2, 2)); // 1-index the grid
    for (int i = 1;i <= n * 2;i++) {
        for (int j = 1;j <= n * 2;j++)  {
            if (i % 2 == 1 && j % 2 == 1) {
                continue;
            }
            farm[i][j] = 0; // keep only the boundary as unaccessible(for now)
        }
    }

    for (int i = 0;i < r;i++) {
        int y1, x1, y2, x2; cin >> y1 >> x1 >> y2 >> x2;

        int y = (y1 * 2) + (y2 - y1);
        int x = (x1 * 2) + (x2 - x1);
        farm[y][x] = 2;
    }

    for (int i = 0;i < k;i++) {
        int y, x; cin >> y >> x;

        farm[y * 2][x * 2] = 1;
    }

    vector<vector<int>> visited((n * 2) + 2, vector<int>((n * 2) + 2, -1));
    vector<int> cowCnt; // count of the cows in the contiguous sub grid
    int floodNumber = 0;
    for (int i = 1;i <= n * 2;i++) {
        for (int j = 1;j <= n * 2;j++) {
            if (visited[i][j] == -1 && i % 2 == 0 && j % 2 == 0) {
                cowCnt.pb(0);
                DFS(i, j, floodNumber, visited, cowCnt);
                floodNumber++;
            }
        }
    }

    ll output = 0;
    for (int i = 0;i < floodNumber;i++) {
        for (int j = i + 1;j < floodNumber;j++) {
            output += cowCnt[i] * cowCnt[j];
        }
    }

    cout << output;
}
