#include <bits/stdc++.h>

#define ALL(arr) arr.begin(), arr.end()
#define ll long long
#define hashmap unordered_map
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define endl "\n"

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;

    vector<int> hills(n);
    for (int i = 0;i < n;i++) {
        cin >> hills[i];
    }

    sort(ALL(hills));

    vector<bool> uniques(1000005, false);

    int ans = 0;
    for (int i = 0;i < n;i++) {
        if (!uniques[hills[i] - 1]) {
            ans++;
            uniques[hills[i] - 1] = true;
            continue;
        }

        if (!uniques[hills[i]]) {
            ans++;
            uniques[hills[i]] = true;
            continue;
        }

        if (!uniques[hills[i] + 1]) {
            ans++;
            uniques[hills[i] + 1] = true;
        }
    }

    cout << ans;

    // set<int> uniques;
    // for (int i = 0;i < n;i++) {
    //     int sizeBefore = uniques.size();

    //     uniques.insert(hills[i] - 1);
    //     if (uniques.size() > sizeBefore) {
    //         continue;
    //     }

    //     uniques.insert(hills[i]);
    //     if (uniques.size() > sizeBefore) {
    //         continue;
    //     }

    //     uniques.insert(hills[i] + 1);
    // }

    // cout << uniques.size();
}
