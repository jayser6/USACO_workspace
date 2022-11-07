// started : 02/13/22
// finished: 02/24/22
// problem : http://www.usaco.org/index.php?page=viewproblem2&cpid=571

#include <bits/stdc++.h>

#define ALL(arr) arr.begin(), arr.end()
#define ll long long
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define endl "\n"

using namespace std;

ifstream fin("highcard.in");
ofstream fout("highcard.out");

int main() { 
    int n; fin >> n;

    vector<bool> cards(2 * n + 1, false); // false -> bessie, true -> elsie
    for (int i = 0;i < n;i++) {
        int card; fin >> card; 
        cards[card] = true;
    }

    vector<int> elsie;
    vector<int> bessie;
    for (int i = 1;i < 2 * n + 1;i++) {
        if (cards[i]) {
            elsie.pb(i);       
        }
        else {
            bessie.pb(i);
        }
    }

    int output = 0;
    int bessieIndex = 0;
    for (int i = 0;i < n;i++) {
        while (bessie[bessieIndex] < elsie[i] && bessieIndex + 1 < n) {
            bessieIndex++;
        }

        if (bessieIndex < n) {
            output++;
            bessieIndex++;
        }
    }

    fout << output;
}
 