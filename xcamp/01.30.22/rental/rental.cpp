// started : 02/04/22
// finished: 02/04/22
// problem : http://www.usaco.org/index.php?page=viewproblem2&cpid=787

#include <bits/stdc++.h>

#define ALL(arr) arr.begin(), arr.end()
#define ll long long
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define endl "\n"

using namespace std;

bool sortShops(pair<int, int> a, pair<int, int> b) {
    return a.s > b.s;
}

int main() {
    ifstream fin("rental.in");
    ofstream fout("rental.out");

    int n, m, r; fin >> n >> m >> r;

    // get input for cows
    vector<int> cows(n);
    for (int i = 0;i < n;i++) {
        fin >> cows[i];
    }


    // get input for shops
    vector<pair<int, int>> shops(m);
    for (int i = 0; i < m;i++) {
        fin >> shops[i].f >> shops[i].s;
    }

    // get input for rentals
    vector<int> rentals(r);
    for (int i = 0;i < r;i++) {
        fin >> rentals[i];
    }

    // sort the vectors
    sort(ALL(cows));
    sort(ALL(shops), sortShops);
    sort(ALL(rentals), greater<int>());

    // first, assume that all the cows are rented out
    ll output = 0;
    ll currentProfit = 0;
    for (int i = 0;i < n && i < r;i++) {
        currentProfit += rentals[i];
    }

    // now iterate through each cow and sell their milk instead of renting them out
    int shopNumber = 0;
    for (int i = n - 1;i >= 0;i--) {
        if (i < r) {
            currentProfit -= rentals[i];
        }

        while (shopNumber < m && cows[i] > 0) {
            if (shops[shopNumber].f < cows[i]) {
                currentProfit += shops[shopNumber].s * shops[shopNumber].f;
                cows[i] -= shops[shopNumber].f;
                shopNumber++;
            }
            else {
                currentProfit += shops[shopNumber].s * cows[i];
                shops[shopNumber].f -= cows[i];
                cows[i] = 0;
            }
        }
        output = max(output, currentProfit);
    }

    fout << output;

}
