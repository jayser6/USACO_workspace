/*____________________________________________________________
// started : 01/08/23
// finished: 01/08/23
// problem : http://www.usaco.org/index.php?page=viewproblem2&cpid=1255
____________________________________________________________*/

#include <bits/stdc++.h>
using namespace std;

// #pragma GCC optimize ("Ofast")
// #pragma GCC target ("avx2")

#define debug(x) #x << ": " << x << " "
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
#define tup tuple
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
#define SMALL (int)INT_MIN
#define SMALLER (ll)LLONG_MIN
#define PRIME64 (ll)999998727899999 // this number has 15 digits
#define PRIME32 (int)(1e9 + 7) 
#define ASCII_PRIME (int)257
#define ALPHA_PRIME (int)29

const int MAX_A = 5e6;
int dur[MAX_A + 1];

bool sieve[MAX_A + 1];
set<int> primes;

void solve() {
    int n; cin >> n;

    int ans = -1;
    FOR(i, n) {
        int a; cin >> a;
        if (ans == -1 || dur[a] < dur[ans]) ans = a;
    }

    cout << ((ans % 4 == 0) ? "Farmer Nhoj" : "Farmer John") << endl;
}

void find_primes() {
    for (int i = 2;i <= MAX_A + 1;i++) {
        if (!sieve[i]) {
            primes.insert(i);
            for (int j = i * 2;j <= MAX_A + 1;j += i) sieve[j] = true;
        }
    }
}

void compute_duration() {
    int last_prime[4] = { 0, 1, 2, 3 };
    for (int i = 4;i < MAX_A + 1;i++) {
        if (i % 4 == 0) dur[i] = i / 4;
        else {
            if (primes.find(i) != primes.end()) {
                last_prime[i % 4] = i;
                dur[i] = 0;
            }
            else dur[i] = dur[i - last_prime[i % 4]];
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    find_primes();
    compute_duration();

    int t; cin >> t;
    while (t--) solve();

    return 0;
}
