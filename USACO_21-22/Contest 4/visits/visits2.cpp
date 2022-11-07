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

ll ans = 0;

vector<pair<int, ll>> cows;
vector<bool> visited;

void DFS(int curr, int dest, ll minVol) {
    visited[curr] = true;
    if (curr == dest) {
        ans -= minVol;
        return;
    }

    DFS(cows[curr].f, dest, min(minVol, cows[curr].s));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;

    vector<int> numTo = vector<int>(n, 0);
    cows = vector<pair<int, ll>>(n);
    visited = vector<bool>(n, false);
    for (int i = 0;i < n;i++) {
        cin >> cows[i].f >> cows[i].s;

        cows[i].f--;
        ans += cows[i].s;
        numTo[cows[i].f]++;
    }

    queue<int> notCycle;
    for (int i = 0;i < n;i++) {
        if (numTo[i] == 0) {
            notCycle.push(i);
        }
    }

    while (!notCycle.empty()) {
        int node = notCycle.front();
        notCycle.pop();

        visited[node] = true;
        numTo[cows[node].f]--;
        if (numTo[cows[node].f] == 0) {
            notCycle.push(cows[node].f);
        }
    }

    for (int i = 0;i < n;i++) {
        if (!visited[i]) {
            DFS(cows[i].f, i, cows[i].s);
        }
    }

    cout << ans;
}