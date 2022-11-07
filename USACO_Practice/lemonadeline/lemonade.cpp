// started : 02/20/22
// finished: 02/20/22
// problem : http://www.usaco.org/index.php?page=viewproblem2&cpid=835

#include <bits/stdc++.h>

#define ALL(arr) arr.begin(), arr.end()
#define ll long long
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define endl "\n"

using namespace std;

ifstream fin("lemonade.in");
ofstream fout("lemonade.out");

int main() {
    int n; fin >> n;

    vector<ll> cows(n);
    for (int i = 0;i < n;i++) {
        fin >> cows[i];
    }

    sort(ALL(cows), greater<ll>());

    for (int i = 0;i < n;i++) {
        if (cows[i] < i) {
            fout << i;
            return 0;
        }
    }

    fout << n;
}