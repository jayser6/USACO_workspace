/*____________________________________________________________
// started : 10/08/22
// finished:
// problem : http://www.usaco.org/index.php?page=viewproblem2&cpid=971
____________________________________________________________*/

#include <bits/stdc++.h>

#define FOR(n) for (int i = 0;i < n;i++)
#define FORO(n) for (int i = 1;i < n;i++)
#define ROF(n) for (int i = n - 1;i >= 0;i--)
#define ROFO(n) for (int i = n - 1;i >= 1;i--)
#define loop while (true) // rust woooo
#define ALL(arr) arr.begin(), arr.end()
#define lower lower_bound 
#define upper upper_bound
#define ll long long
#define uint unsigned int
#define hashmap unordered_map
#define hashset unordered_set
#define p_queue priority_queue
#define pb push_back
#define pf push_front
#define popb pop_back
#define popf pop_front
#define mp make_pair    
#define f first
#define s second
#define endl "\n"
#define BIG_NUMBER (ll)1e18
#define BIG_PRIME (ll)999998727899999 // this number has 15 digits
#define PRIME32 (int)(1e9 + 7) 
#define ASCII_PRIME (int)257
#define ALPHA_PRIME (int)29

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("cowmbat.in", "r", stdin);
    freopen("cowmbat.out", "w", stdout);

    int n, m, k; cin >> n >> m >> k;
    string combo; cin >> combo;

    vector<vector<int>> dist(m, vector<int>(m));
    for (int i = 0;i < m;i++) {
        for (int j = 0;j < m;j++) {
            cin >> dist[i][j];
        }
    }

    // Floyd-Warshall to calculate the shortest path from each letter to every
    // other letter
    for (int k = 0;k < m;k++)
        for (int i = 0;i < m;i++)
            for (int j = 0;j < m;j++)
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);



    return 0;
}
