// started : 04/30/22
// finished: 04/30/22
// problem : https://cses.fi/problemset/task/1676

#include <bits/stdc++.h>

#define ALL(arr) arr.begin(), arr.end()
#define ll long long
#define hashmap unordered_map
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define endl "\n"
#define BIG_NUMBER (ll)pow(10, 18)

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m; cin >> n >> m;

    vector<vector<int>> components(n);
    vector<int> whichComp(n);
    for (int i = 0;i < n;i++) {
        components[i].pb(i);
        whichComp[i] = i;
    }

    int numComp = n;
    int biggestComp = 0;
    for (int i = 0;i < m;i++) {
        int a, b; cin >> a >> b;
        a--; b--;

        if (whichComp[a] != whichComp[b]) {
            numComp--;

            // these two are the indices of the components
            int smaller = (components[whichComp[a]].size() > components[whichComp[b]].size())
                ? whichComp[b] : whichComp[a];
            int bigger = (components[whichComp[a]].size() > components[whichComp[b]].size())
                ? whichComp[a] : whichComp[b];

            for (int i = 0;i < components[smaller].size();i++) {
                components[bigger].pb(components[smaller][i]);
                whichComp[components[smaller][i]] = bigger;
            }
        }

        biggestComp = max(biggestComp, (int)max(components[whichComp[a]].size(),
            components[whichComp[b]].size()));

        cout << numComp << " " << biggestComp << endl;
    }
}