#include <bits/stdc++.h>

using namespace std;

int main() {
    int n; cin >> n;

    vector<vector<int>> matrix (n, vector<int> (n, 0));

    int num = 1;
    int y = 0, x = 0;
    int yDirection = 1, xDirection = 1;
    bool isEnd = false;
    while (num <= n * n) {
        matrix.at(y).at(x) = num;
        num++;
        if (isEnd) {
            isEnd = false;
            y += yDirection;
            x += xDirection;
        }
        else if (x == n - 1) {
            y++;
            isEnd = true;
            yDirection = 1;
            xDirection = -1;
        }
        else if (y == n - 1) {
            x++;
            isEnd = true;
            yDirection = -1;
            xDirection = 1;
        }
        else if (y == 0) {
            x++;
            isEnd = true;
            yDirection = 1;
            xDirection = -1;
        }
        else if (x == 0) {
            y++; 
            isEnd = true;
            yDirection = -1;
            xDirection = 1; 
        }
        else {
            y += yDirection;
            x += xDirection; 
        }
    }

    for (int i = 0;i < n;i++) {
        for (int j = 0;j < n;j++) {
            cout << matrix.at(i).at(j) << " ";
        }
        cout << endl;
    }
}