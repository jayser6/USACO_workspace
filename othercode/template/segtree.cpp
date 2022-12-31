/*____________________________________________________________
// started :
// finished:
// problem :
____________________________________________________________*/

#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize ("Ofast")
#pragma GCC target ("avx2")

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
#define BIG (int)INT_MAX 
#define BIGGER (ll)LLONG_MAX
#define PRIME64 (ll)999998727899999 // this number has 15 digits
#define PRIME32 (int)(1e9 + 7) 
#define ASCII_PRIME (int)257
#define ALPHA_PRIME (int)29

// a lazy segtree that supports range sums
struct lz_segtree {
    // lz[i] { lz_add, lz_set }. If no lazy values, lz[i] = {0, -1} 
    vector<pair<ll, int>> lz;
    vector<ll> st;
    int depth, size;
    const int DONT_SET = -1; // TODO: change this if necessary

    lz_segtree(int n) {
        depth = ceil(log2(n));
        size = pow(2, depth + 1) - 1;

        st.resize(size);
        lz.resize(size);
        FOR(i, size) lz[i] = { 0, DONT_SET };
    }

    int mid(int a, int b) {
        return (a + b) / 2;
    }

    ll build(int val[], int st_i, int st_s, int st_e) {
        if (st_s == st_e) return st[st_i] = val[st_s];

        return st[st_i] = build(val, st_i * 2 + 1, st_s, mid(st_s, st_e)) +
            build(val, st_i * 2 + 2, mid(st_s, st_e) + 1, st_e);
    }

    void lz_add(int st_i, int st_s, int st_e, ll val) {
        int l = st_e - st_s + 1;
        lz[st_i].f += val;
        st[st_i] += l * val;
    }

    void lz_set(int st_i, int st_s, int st_e, int val) {
        if (val != DONT_SET) {
            int l = st_e - st_s + 1;
            lz[st_i].f = 0;
            lz[st_i].s = val;
            st[st_i] = (ll)l * val;
        }
    }

    void prop(int st_i, int st_s, int st_e) {
        lz_set(st_i * 2 + 1, st_s, mid(st_s, st_e), lz[st_i].s);
        lz_set(st_i * 2 + 2, mid(st_s, st_e) + 1, st_e, lz[st_i].s);

        lz_add(st_i * 2 + 1, st_s, mid(st_s, st_e), lz[st_i].f);
        lz_add(st_i * 2 + 2, mid(st_s, st_e) + 1, st_e, lz[st_i].f);

        lz[st_i] = { 0, DONT_SET };
    }

    ll get(int st_i, int st_s, int st_e, int q_s, int q_e) {
        if (q_s > st_e || q_e < st_s) {
            // not contained at all 
            return 0;
        }
        else if (q_s <= st_s && q_e >= st_e) {
            // fully contained
            return st[st_i];
        }
        else {
            // partially contained
            prop(st_i, st_s, st_e);
            return get(st_i * 2 + 1, st_s, mid(st_s, st_e), q_s, q_e) +
                get(st_i * 2 + 2, mid(st_s, st_e) + 1, st_e, q_s, q_e);
        }
    }

    ll update(int st_i, int st_s, int st_e, int q_s, int q_e, int add, int set) { // TODO: use whatever segtree function the problem requires - doesn't have to be add() or set()
        if (q_s > st_e || q_e < st_s) {
            // not contained at all 
            return st[st_i];
        }
        else if (q_s <= st_s && q_e >= st_e) {
            // fully contained
            lz_set(st_i, st_s, st_e, set);

            // if you want to add instead of set
            lz_add(st_i, st_s, st_e, add);
            return st[st_i];
        }
        else {
            // partially contained
            prop(st_i, st_s, st_e);
            return st[st_i] = update(st_i * 2 + 1, st_s, mid(st_s, st_e), q_s, q_e, add, set) +
                update(st_i * 2 + 2, mid(st_s, st_e) + 1, st_e, q_s, q_e, add, set);
        }
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, q; cin >> n >> q;
    int arr[n]; FOR(i, n) cin >> arr[i];

    lz_segtree st(n);
    st.build(arr, 0, 0, n - 1);

    FOR(i, q) {
        int t, a, b; cin >> t >> a >> b;
        a--; b--;

        if (t == 3) cout << st.get(0, 0, n - 1, a, b) << endl;
        else {
            int x; cin >> x;
            if (t == 1) st.update(0, 0, n - 1, a, b, x, st.DONT_SET);
            else if (t == 2) st.update(0, 0, n - 1, a, b, 0, x);
        }
    }

    return 0;
}
