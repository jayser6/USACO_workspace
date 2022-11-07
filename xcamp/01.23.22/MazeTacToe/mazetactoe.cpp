// started : 01/26/22
// finished: 01/28/22
// problem : Maze Tac Toe (USACO Silver) http://www.usaco.org/index.php?page=viewproblem2&cpid=1134

#include <bits/stdc++.h>

#define ALL(arr) arr.begin(), arr.end()
#define ll long long
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define endl "\n"

using namespace std;

const int M_CONST = 2;
const int O_CONST = 1;
const int pow39 = 19683;

int run = 0;

string grid[25][25];
bool visit[25][25][pow39]; // pow(3, 9) since the board can have up to 3 ^ 9 tic tac toe board states
unordered_set<int> answer; // keeps track of all the boardstates that Bessie can win with
int bsPower[3][3] = { {0, 1, 2},
                      {3, 4, 5},
                      {6, 7, 8} };

bool isMoo(string str) {
    if (str == "MOO" || str == "OOM") {
        return  true;
    }
    return false;
}

bool didWin(int boardState) {
    // translate the compressed boardState into an actual board
    string ttcBoard[3][3];
    for (int i = 0;i < 3;i++) {
        for (int j = 0;j < 3;j++) {
            int num = boardState % 3;
            string c;
            if (num == 2) {
                c = "M";
            }
            else if (num == 1) {
                c = "O";
            }
            else {
                c = ".";
            }

            ttcBoard[i][j] = c;
            boardState /= 3;
        }
    }

    // check for horizotal and vertical "MOO"s
    for (int i = 0;i < 3;i++) {
        string horizontal = ttcBoard[0][i] + ttcBoard[1][i] + ttcBoard[2][i];
        string vertical = ttcBoard[i][0] + ttcBoard[i][1] + ttcBoard[i][2];

        if (isMoo(horizontal)) {
            return true;
        }
        if (isMoo(vertical)) {
            return true;
        }
    }

    // check for diagonal "MOO"s
    string diag1 = ttcBoard[0][0] + ttcBoard[1][1] + ttcBoard[2][2];
    string diag2 = ttcBoard[0][2] + ttcBoard[1][1] + ttcBoard[2][0];
    if (isMoo(diag1)) {
        return true;
    }
    if (isMoo(diag2)) {
        return true;
    }

    return false;
}

void DFS(int y, int x, int boardState) {
    visit[y][x][boardState] = true;

    if (grid[y][x].at(0) != '.') {
        int boardY = grid[y][x].at(1) - 49;
        int boardX = grid[y][x].at(2) - 49;
        if ((int)(boardState / pow(3, bsPower[boardY][boardX])) % 3 == 0) {
            if (grid[y][x].at(0) == 'M') {
                boardState += pow(3, bsPower[boardY][boardX]) * M_CONST;
            }
            else if (grid[y][x].at(0) == 'O') {
                boardState += pow(3, bsPower[boardY][boardX]) * O_CONST;
            }
        }
    }

    if (didWin(boardState)) {
        answer.insert(boardState);
        return;
    }

    if ((grid[y + 1][x].at(0) != '#') && (!visit[y + 1][x][boardState])) {
        DFS(y + 1, x, boardState);
    }
    if ((grid[y - 1][x].at(0) != '#') && (!visit[y - 1][x][boardState])) {
        DFS(y - 1, x, boardState);
    }
    if ((grid[y][x + 1].at(0) != '#') && (!visit[y][x + 1][boardState])) {
        DFS(y, x + 1, boardState);
    }
    if ((grid[y][x - 1].at(0) != '#') && (!visit[y][x - 1][boardState])) {
        DFS(y, x - 1, boardState);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // start of coded
    int n; cin >> n;

    int bessieY, bessieX;
    for (int i = 0;i < n;i++) {
        string input; cin >> input;
        for (int j = 0;j < 3 * n;j++) {
            grid[i][j / 3] += input[j];
            if (input.at(j) == 'B') {
                bessieY = i;
                bessieX = j / 3;
            }
        }
    }

    // important note for boardState: grid[y][x] = 0 -> val = 0, = 'O' -> val = 1, = 'M' -> val = 2
    DFS(bessieY, bessieX, 0);

    cout << answer.size();
}
