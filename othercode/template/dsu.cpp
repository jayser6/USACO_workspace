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

struct dsu {
    vector<pair<int, int>> comp; // dsu[i] = {parent, size}
    int num_comps;

    dsu(int n) {
        num_comps = n;
        comp.resize(n);
        FOR(i, n) comp[i] = { i, 1 };
    }

    int find_head(int a) {
        if (comp[a].f == a) return a;
        return comp[a].f = find_head(comp[a].f);
    }

    void merge(int a, int b) {
        int a_head = find_head(a);
        int b_head = find_head(b);

        if (a_head == b_head) {
            return;
        }

        int gr, sm;
        if (comp[a_head].s > comp[b_head].s) {
            gr = a_head;
            sm = b_head;
        }
        else {
            gr = b_head;
            sm = a_head;
        }

        num_comps--;
        comp[gr].f = sm;
        comp[sm].s += comp[gr].s;
    }
};