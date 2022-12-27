/*____________________________________________________________
// started : 12/26/22
// finished: 12/26/22
// problem : https://cses.fi/problemset/task/2166
____________________________________________________________*/

#include <bits/stdc++.h>

#define FOR(i, n) for (int i = 0;i < n;i++)
#define FORO(i, n) for (int i = 1;i < n;i++)
#define ROF(i, n) for (int i = n - 1;i >= 0;i--)
#define ROFO(i, n) for (int i = n - 1;i >= 1;i--)
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
#define BIG_INT64 (ll)1e18
#define PRIME64 (ll)999998727899999 // this number has 15 digits
#define PRIME32 (int)(1e9 + 7) 
#define ASCII_PRIME (int)257
#define ALPHA_PRIME (int)29

using namespace std;

int mid(int a, int b) {
    return (a + b) / 2;
}

void st_make(vector<pair<ll, ll>>& st, vector<int>& arr, int st_i, int st_s, int st_e) {
    if (st_s == st_e) {
        st[st_i] = { arr[st_s], max(0, arr[st_s]) };
        return;
    }

    int child1 = st_i * 2 + 1, child2 = st_i * 2 + 2;

    st_make(st, arr, child1, st_s, mid(st_s, st_e));
    st_make(st, arr, child2, mid(st_s, st_e) + 1, st_e);

    st[st_i].f = (ll)st[child1].f + st[child2].f;
    st[st_i].s = max((ll)st[child1].f + st[child2].s, st[child1].s);
}

// returns sum, max prefix of the segment
pair<ll, ll> st_query(vector<pair<ll, ll>>& st, int st_i, int st_s, int st_e, int q_s, int q_e) {
    if (st_e < q_s || st_s > q_e) {
        return { 0, 0 };
    }
    else if (st_s >= q_s && st_e <= q_e) {
        return { st[st_i].f, st[st_i].s };
    }
    else {
        int child1 = st_i * 2 + 1, child2 = st_i * 2 + 2;

        pair<ll, ll> left = st_query(st, child1, st_s, mid(st_s, st_e), q_s, q_e);
        pair<ll, ll> right = st_query(st, child2, mid(st_s, st_e) + 1, st_e, q_s, q_e);

        return { left.f + right.f, max(left.f + right.s, left.s) };
    }
}

void st_update(vector<pair<ll, ll>>& st, int st_i, int st_s, int st_e, int update_at, int update_to) {
    if (st_s == st_e && st_s == update_at) {
        st[st_i] = { update_to, max(0, update_to) };
    }
    else if (st_s <= update_at && st_e >= update_at) {
        int child1 = st_i * 2 + 1, child2 = st_i * 2 + 2;

        st_update(st, child1, st_s, mid(st_s, st_e), update_at, update_to);
        st_update(st, child2, mid(st_s, st_e) + 1, st_e, update_at, update_to);

        st[st_i].f = st[child1].f + st[child2].f;
        st[st_i].s = max(st[child1].f + st[child2].s, st[child1].s);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, q; cin >> n >> q;

    vector<int> arr(n);
    FOR(i, n)
        cin >> arr[i];

    int st_depth = ceil(log2(n)), st_size = pow(2, st_depth + 1) - 1;
    vector<pair<ll, ll>> st(st_size, { BIG_INT64, BIG_INT64 }); // sum, prefix
    st_make(st, arr, 0, 0, n - 1);

    FOR(i, q) {
        int type, in1, in2; cin >> type >> in1 >> in2;

        if (type == 1) {
            st_update(st, 0, 0, n - 1, in1 - 1, in2);
        }
        else {
            cout << st_query(st, 0, 0, n - 1, in1 - 1, in2 - 1).s << endl;
        }
    }

    return 0;
}
