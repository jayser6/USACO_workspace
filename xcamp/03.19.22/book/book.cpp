// started : 04/06/22
// finished: 04/08/22
// problem : https://codeforces.com/problemset/problem/1572/A

#include <bits/stdc++.h>

#define ALL(arr) arr.begin(), arr.end()
#define ll long long
#define ld long double
#define hashmap unordered_map
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define endl "\n"
#define BIG_NUMBER (ll)pow(10, 18)

using namespace std;

void solve() {
    int n; cin >> n;

    vector<vector<int>> prereq = vector<vector<int>>(n);
    vector<int> reqrem = vector<int>(n);

    for (int i = 0;i < n;i++) {
        cin >> reqrem[i];

        for (int j = 0;j < reqrem[i];j++) {
            int req; cin >> req;
            req--;
            prereq[req].pb(i);
        }
    }

    set<int> booksToRead;
    for (int i = 0;i < n;i++) {
        if (reqrem[i] == 0) {
            booksToRead.insert(i);
        }
    }

    int output = 1;
    int bookRem = n;
    int lastBook = -1;
    while (!booksToRead.empty()) {
        auto bookIt = booksToRead.lower_bound(lastBook);
        if (bookIt == booksToRead.end()) {
            output++;
            bookIt = booksToRead.begin();
        }

        for (int nextBook : prereq[*bookIt]) {
            reqrem[nextBook]--;
            if (reqrem[nextBook] == 0) {
                booksToRead.insert(nextBook);
            }
        }

        bookRem--;
        lastBook = *bookIt;
        booksToRead.erase(bookIt);
    }

    if (bookRem == 0) {
        cout << output << endl;
    }
    else {
        cout << "-1" << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    for (int i = 0;i < t;i++) {
        solve();
    }
}