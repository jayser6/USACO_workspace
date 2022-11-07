#include <bits/stdc++.h>

#define ALL(arr) arr.begin(), arr.end()
#define u_set unordered_set
#define ll long long
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define endl "\n"

using namespace std;

bool canFile(int start, int k, int folder) {
    return (folder >= start) && (folder < start + k);
}

int scrollFolder(vector<int>& emailsLeft, int index, int currFolder, int m) {
    while ((currFolder <= m) && (emailsLeft[currFolder] == 0)) {
        currFolder++;
    }

    return currFolder;
}

void solve() {
    int m, n, k; cin >> k >> n >> k;

    vector<int> emails(n);
    vector<int> emailsLeft(m + 1, 0); // the furthest index of the email that needs to be filed to file[i]
    for (int i = 0;i < n;i++) {
        cin >> emails[i];
        emailsLeft[emails[i]]++;
    }

    // start scrolling down and filing emails
    vector<pair<int, int>> skipped;
    set<pair<int, int>> window1; // index, email
    set<pair<int, int>> window2; // email, index
    int currFolder = 1;

    for (int i = 0;i < n;i++) {
        // simulate scrolling down
        if (window1.size() == k) {
            pair<int, int> _erase = *(window1.begin());
            window1.erase(_erase);
            window2.erase(mp(_erase.s, _erase.f));

            skipped.pb(_erase);
        }

        window1.insert(mp(i, emails[i]));
        window2.insert(mp(emails[i], i));
        auto emailToRemove = lower_bound(ALL(window2), mp(currFolder, -1));
        while (emailToRemove != window2.end() && canFile(currFolder, k, emailToRemove->f)) {
            pair<int, int> _erase = *emailToRemove;
            window1.erase(mp(_erase.s, _erase.f));
            window2.erase(_erase);
            emailsLeft[_erase.f]--;
            currFolder = scrollFolder(emailsLeft, _erase.s, currFolder, m);
            emailToRemove = lower_bound(ALL(window2), mp(currFolder, -1));
        }
    }

    // now try to "scroll" back up
    for (int i = skipped.size() - 1;i >= 0;i--) {
        window1.insert(skipped[i]);
        window2.insert(mp(skipped[i].s, skipped[i].f));

        if (window1.size() > k) {
            cout << "NO" << endl;
            return;
        }
        auto emailToRemove = lower_bound(ALL(window2), mp(currFolder, -1));
        while (emailToRemove != window2.end() && canFile(currFolder, k, emailToRemove->f)) {
            pair<int, int> _erase = *emailToRemove;
            window1.erase(mp(_erase.s, _erase.f));
            window2.erase(_erase);
            emailsLeft[_erase.f]--;
            currFolder = scrollFolder(emailsLeft, _erase.s, currFolder, m);
            emailToRemove = lower_bound(ALL(window2), mp(currFolder, -1));
        }
    }

    if (window1.empty()) {
        cout << "YES" << endl;
    }
    else {
        cout << "NO" << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    for (int i = 0;i < t;i++) {
        solve();
    }
}
