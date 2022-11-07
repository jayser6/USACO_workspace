// start : 12/6/21
// finish: 12/7/21

#include <bits/stdc++.h>

#define ARR_SIZE 3000 
#define ARR_BEGIN 1000 // corresponding index for cow position 0

using namespace std;

// index 1000 is equal to position 0 from the input
int adjCount[ARR_SIZE][ARR_SIZE];
int yChange[4] = {1, -1, 0, 0};
int xChange[4] = {0, 0, 1, -1}; 
int cowsNeeded = 0;
bool placed[ARR_SIZE][ARR_SIZE];

void putMoreCows(int, int);
void placeCow(int, int);

bool shouldPlaceMore(int y, int x) {
    if (adjCount[y][x] == 3 && placed[y][x]) {
        return true;
    }
    return false;
}

void putMoreCows(int y, int x) {
    if (!shouldPlaceMore(y, x)) {
        return;
    }
    for (int i = 0;i < 4;i++) {
        placeCow(y + yChange[i], x + xChange[i]);
    }
}

void placeCow(int y, int x) {
    if (placed[y][x]) {
        return;
    }
    placed[y][x] = true;
    cowsNeeded++;
    putMoreCows(y, x);
    for (int i = 0; i < 4;i++) {
        adjCount[y + yChange[i]][x + xChange[i]]++;
        putMoreCows(y + yChange[i], x + xChange[i]);
    }
}

void solve() {
    int inX, inY; cin >> inX >> inY;
    inX += ARR_BEGIN;
    inY += ARR_BEGIN;

    cowsNeeded--;
    placeCow(inY, inX);

    cout << cowsNeeded << endl;
}

int main() {
    int n; cin >> n; 

    for(int i = 0;i < ARR_SIZE;i++) {
        for (int j = 0; j < ARR_SIZE;j++) {
            adjCount[i][j] = 0;
            placed[i][j] = false;
        }
    }

    for (int i = 0;i < n;i++) {
        solve();
    }
}