#include <bits/stdc++.h>

#define ll long long
#define ins insert
#define e erase
#define ub upper_bound

using namespace std;

int main() {
    int n; cin >> n;

    multiset<ll> towers; // holds the size of the cube on top of the tower
    for (int i = 0;i < n;i++) {
        ll cubeSize; cin >> cubeSize;
        if ((towers.size() > 0) && (*(--towers.end()) > cubeSize)) {
            auto it = towers.ub(cubeSize);
            towers.e(it);
        }
        towers.ins(cubeSize);
    }

    cout << towers.size();
}