// started : 01/11/22
// finished: 1/15/22

#include <bits/stdc++.h>

#define ll long long
#define pb push_back
#define mp make_pair
#define f first
#define s second

using namespace std;

int main() {
    int n, m; cin >> n >> m;

    vector<ll> boys(n);
    for (int i = 0;i < n;i++) {
        cin >> boys[i];
    }
    vector<ll> girls(m);
    for (int i = 0;i < m;i++) {
        cin >> girls[i];
    }

    sort(boys.begin(), boys.end());
    sort(girls.begin(), girls.end());

    if (boys[n - 1] > girls[0]) {
        cout << "-1";
        return 0;
    }

    ll answer = 0;
    for (int i = 0;i < n;i++) {
        answer += boys.at(i);
    }
    answer *= m;

    if (boys[n - 1] != girls[0]) {
        answer += girls[0] - boys[n - 2];
    }

    for (int i = 1;i < m;i++) {
        answer += girls[i] - boys[n - 1]; 
    }

    cout << answer;
}