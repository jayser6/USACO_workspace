#include <iostream>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <string>
#include <cmath>
#include <vector>
#include <set>
#include <stack>
#include <deque>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <bitset>
#include <map>
#include <chrono>
#include <cstring>
#include <deque>
#include <numeric>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

/*
* Idea: this is just mex right
*/
const ll MOD = 1000000007;
const int maxN = 3e5 + 5;
const ll INF = 1e18;

int N, M;
int a[maxN];
int st[maxN * 4];
bool lz[maxN * 4];
set<int> trust[maxN];

void prop(int v)
{
    if (lz[v])
    {
        st[v * 2] = st[v * 2 + 1] = st[v];
        lz[v * 2] = lz[v * 2 + 1] = lz[v];
        lz[v] = 0;
    }
}

void build(int v, int tl, int tr)
{
    if (tl == tr) st[v] = a[tl];
    else
    {
        int tm = (tl + tr) / 2;
        build(v * 2, tl, tm);
        build(v * 2 + 1, tm + 1, tr);
    }
}

void upd(int v, int tl, int tr, int l, int r, int x)
{
    if (l > r) return;
    if (l == tl && tr == r)
    {
        st[v] = x;
        lz[v] = 1;
        return;
    }

    prop(v);
    int tm = (tl + tr) / 2;
    upd(v * 2, tl, tm, l, min(tm, r), x);
    upd(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, x);
}

int get(int v, int tl, int tr, int pos)
{
    if (tl == tr) return st[v];

    prop(v);
    int tm = (tl + tr) / 2;
    if (pos <= tm) return get(v * 2, tl, tm, pos);
    else return get(v * 2 + 1, tm + 1, tr, pos);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> a[i], trust[a[i]].insert(i);

    build(1, 1, N);

    cin >> M;

    int c;
    for (int i = 0; i < M; i++)
    {
        cin >> c;

        if (trust[c].size() <= 1) continue;

        auto it = trust[c].begin();
        while (!trust[c].empty() && get(1, 1, N, *it) != c)
        {
            trust[c].erase(trust[c].begin());
            if (!trust[c].empty())
                it = trust[c].begin();
        }

        if (trust[c].size() <= 1) continue;

        int l = *it;
        auto en = trust[c].rbegin();
        while (!trust[c].empty() && get(1, 1, N, *en) != c)
        {
            trust[c].erase(prev(trust[c].end()));
            if (!trust[c].empty())
                en = trust[c].rbegin();
        }

        if (trust[c].size() <= 1) continue;

        int r = *en;
        upd(1, 1, N, l, r, c);
    }

    for (int i = 1; i <= N; i++)
        cout << get(1, 1, N, i) << " ";
    cout << "\n";

    return 0;
}