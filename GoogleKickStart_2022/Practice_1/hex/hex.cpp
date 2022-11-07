// started : 02/16/22
// finished: 02/16/22

#include <bits/stdc++.h>

#define ALL(arr) arr.begin(), arr.end()
#define ll long long
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define endl "\n"

using namespace std;

int n;

int blueCnt = 0, redCnt = 0;
int blueWinCnt = 0, redWinCnt = 0;

vector<vector<char>> board;
vector<vector<bool>> visited;

const vector<pair<int, int>> NEIGHBOR_COORDS = {mp(0, 1), mp(0, -1), mp(-1, 0), mp(-1, 1), mp(1, 0), mp(1, -1)};
const int NEIGHBOR_CNT = 6;

bool isInBnd (int y, int x) {
    if (y >= 0 && y < n && x >= 0 && x < n) {
        return true;
    }
    return false;
}

void DFS(int y, int x, char color) {
    visited[y][x] = true;

    // check for wins
    if (color == 'R' && y == n - 1) {
        // red wins
        redWinCnt++;
        return;
    }
    else if (color == 'B' && x == n - 1) {
        // blue wins
        blueWinCnt++;
        return;
    }

    // move to neighbor cells if possible
    for (int i = 0;i < NEIGHBOR_CNT;i++) {
        int y2 = y + NEIGHBOR_COORDS[i].f;
        int x2 = x + NEIGHBOR_COORDS[i].s;

        if (!isInBnd(y2, x2)) {
            continue;
        }

        if (!visited[y2][x2] && board[y2][x2] == color) {
            DFS(y2, x2, color);
        }
    }
}

void solve(int caseNum) {
    // get input and initialize variables
    cin >> n;

    blueCnt = 0;
    redCnt = 0;
    blueWinCnt = 0;
    redWinCnt = 0;

    board = vector<vector<char>>(n, vector<char>(n));
    visited = vector<vector<bool>>(n, vector<bool>(n, false));
    for (int i = 0;i < n;i++) {
        for (int j = 0;j < n;j++) {
            cin >> board[i][j];

            if (board[i][j] == 'R') {
                redCnt++;
            }
            else if (board[i][j] == 'B') {
                blueCnt++;
            }
        }
    }

    cout << "Case #" << caseNum << ": ";

    // check the number of red and blue pieces
    if (abs(redCnt - blueCnt) > 1) {
        cout << "Impossible" << endl;
        return;
    }

    // DFS to check if someone won
    for (int i = 0;i < n;i++) {
        // this is for red
        if (!visited[0][i] && board[0][i] == 'R') {
            DFS(0, i, 'R');
        }

        // this is for blue
        if (!visited[i][0] && board[i][0] == 'B') {
            DFS(i, 0, 'B');
        }
    }

    if (blueWinCnt > 1 || redWinCnt > 1) {
        cout << "Impossible" << endl;
    }
    else if (blueWinCnt >= 1 && redWinCnt >= 1) {
        cout << "Impossible" << endl;
    }
    else if (blueWinCnt >= 1) {
        cout << "Blue wins" << endl;
    }
    else if (redWinCnt >= 1) {
        cout << "Red wins" << endl;
    }
    else {
        cout << "Nobody wins" << endl;
    }
}

int main() {
    int t; cin >> t;

    for (int i = 0;i < t;i++) {
        solve(i + 1);
    }
}
