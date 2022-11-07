// started : 12/15/21
// finished: 12/15/21

#include <bits/stdc++.h>

#define ll long long
#define pb push_back
#define mp make_pair
#define f first
#define s second

using namespace std;

int blankArea = 0;
int n, m;
char paper[100][100];

void floodFill(int y, int x) {
    if (y < 0 || y >= n || x < 0 || x >= m || paper[y][x] == '*') {
        return;
    }

    paper[y][x] = '*';

    floodFill(y + 1, x);
    floodFill(y - 1, x);
    floodFill(y, x + 1);
    floodFill(y, x - 1);
}

int main() {
    cin >> n >> m;

    for (int i = 0;i < n;i++) {
        for (int j = 0;j < m;j++) {
            cin >> paper[i][j];
        }
    }

    // for (int i = 0;i < n;i++) {
    //     for (int j = 0;j < m;j++) {
    //         cout << paper[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    for (int i = 0;i < n;i++) {
        for (int j = 0;j < m;j++) {
            if (paper[i][j] == '.') {
                blankArea++;
                floodFill(i, j);
            }
        }
    }

    if (blankArea == 1) {
        cout << "E";
    }
    else if (blankArea == 2) {
        cout << "D";
    }
    else {
        cout << "B";
    }
}