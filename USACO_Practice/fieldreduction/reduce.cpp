// started : 02/22/22
// finished: 02/23/22
// problem : http://www.usaco.org/index.php?page=viewproblem2&cpid=642

#include <bits/stdc++.h>

#define ALL(arr) arr.begin(), arr.end()
#define ll long long
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define endl "\n"

using namespace std;

ifstream fin("reduce.in");
ofstream fout("reduce.out");

int main() {
    int n; fin >> n;

    vector<pair<int, int>> cows(n);
    vector<int> cowsY(n);
    vector<int> cowsX(n);
    for (int i = 0;i < n;i++) {
        fin >> cows[i].f >> cows[i].s;

        cowsY[i] = cows[i].f;
        cowsX[i] = cows[i].s;
    }

    sort(ALL(cowsX));
    sort(ALL(cowsY));

    ll ans = -1;

    for (int i = 0;i < 4;i++) { // minumum y
        for (int j = 0;j < 4;j++) { // maximum y
            for (int k = 0;k < 4;k++) { // minimum x
                for (int l = 0;l < 4;l++) { // maximum x
                    int minY = cowsY[i];
                    int maxY = cowsY[n - 1 - j];
                    int minX = cowsX[k];
                    int maxX = cowsX[n - 1 - l];

                    // check if there are less than 3 cows outside the rectangle
                    int removeCnt = 0;
                    for (pair<int, int> cow : cows) {
                        if (cow.f < minY || cow.f > maxY || cow.s < minX || cow.s > maxX) {
                            removeCnt++;
                        }
                    }

                    if ((removeCnt <= 3) && (ans == -1 || abs((maxY - minY) * (maxX - minX)) < ans)) {
                        ans = abs((maxY - minY) * (maxX - minX));
                    }
                }
            }
        }
    }

    fout << ans;
}
