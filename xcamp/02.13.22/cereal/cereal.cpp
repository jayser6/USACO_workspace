/*____________________________________________________________
// started : 06/24/22
// finished: 06/24/22
// problem : http://www.usaco.org/index.php?page=viewproblem2&cpid=1039
____________________________________________________________*/

#include <bits/stdc++.h>

#define FOR(n) for (int i = 0;i < n;i++)
#define FORO(n) for (int i = 1;i < n;i++)
#define ROF(n) for (int i = n - 1;i >= 0;i--)
#define ROFO(n) for (int i = n - 1;i >= 1;i--)
#define loop while (true)
#define ALL(arr) arr.begin(), arr.end()
#define lower lower_bound // rust woooo
#define upper upper_bound
#define ll long long
#define uint unsigned int
#define hashmap unordered_map
#define hashset unordered_set
#define p_queue priority_queue
#define pb push_back
#define pf push_front
#define mp make_pair
#define f first
#define s second
#define endl "\n"
#define BIG_NUMBER (ll)1e18

using namespace std;

ifstream fin("cereal.in");
ofstream fout("cereal.out");

bool update(vector<pair<int, int>>& cows, vector<int>& cereals, int currCereal, int currCow) {
    if (cereals[currCereal] == -1) {
        cereals[currCereal] = currCow;
        return true;
    }
    else if (cereals[currCereal] < currCow) {
        return false;
    }

    int nextCow = cereals[currCereal];
    cereals[currCereal] = currCow;

    if (currCereal == cows[nextCow].s) {
        return false;
    }
    return update(cows, cereals, cows[nextCow].s, nextCow);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m; fin >> n >> m;
    vector<pair<int, int>> cows(n);
    for (pair<int, int>& curr : cows) {
        fin >> curr.f >> curr.s;
        curr.f--;
        curr.s--;
    }

    vector<int> cereals(m, -1);
    vector<int> output(n);
    int lastAns = 0;
    ROF(n) {
        lastAns += update(cows, cereals, cows[i].f, i);

        output[i] = lastAns;
    }

    for (int curr : output) {
        fout << curr << endl;
    }

    return 0;
}
