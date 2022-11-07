// started : 02/21/22
// finished: 02/22/22
// problem : https://codeforces.com/problemset/problem/1203/E

#include <bits/stdc++.h>

#define ALL(arr) arr.begin(), arr.end()
#define ll long long
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define endl "\n"

using namespace std;

int main() {
    ios::sync_with_stdio(NULL);
    cin.tie(NULL);

    int n; cin >> n;

    vector<int> boxers(n);
    for (int i = 0;i < n;i++) {
        cin >> boxers[i];
    }

    sort(ALL(boxers));

    unordered_set<int> team;
    for (int i = 0;i < n;i++) {
        int num = boxers[i];
        int currTeamSize = team.size();

        if (num > 1) {
            // try reducing the weight by 1
            team.insert(num - 1);
            if (team.size() > currTeamSize) {
                // this boxer can reduce his weight by 1
                continue;
            }
        }

        // try keeping the same weight
        team.insert(num);
        if (team.size() > currTeamSize) {
            // this boxer can keep his weight
            continue;
        }

        team.insert(num + 1);
    }

    cout << team.size();
}