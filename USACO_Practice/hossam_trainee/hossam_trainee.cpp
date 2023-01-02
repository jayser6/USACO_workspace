/*____________________________________________________________
// started : 01/01/23
// finished: 01/01/23
// problem : https://codeforces.com/problemset/problem/1771/C
____________________________________________________________*/

#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize ("Ofast")
#pragma GCC target ("avx2")

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

const int A = 4 * 1e4; // A ~ sqrt(10^9)
bool sieve[A];
vector<int> primes;
set<int> primes_used;
bool ans_found;

void find_primes() {
    for (int i = 2;i < A;i++) {
        if (!sieve[i]) {
            primes.pb(i);
            for (int j = 2 * i;j < A;j += i) sieve[j] = true;
        }
    }
}

// prime factorization. returns the factor that remains after n is diviced by all the elements in "primes"
int fact(int n) {
    for (int i = 0;i < primes.size() && primes[i] * primes[i] <= n;i++) {
        if (n % primes[i] == 0) {
            bool ins = false;
            while (n % primes[i] == 0) {
                n /= primes[i];
                if (primes_used.find(primes[i]) != primes_used.end() && !ins) ans_found = true;
                else {
                    primes_used.insert(primes[i]);
                    ins = true;
                }
            }
        }
    }

    return n;
}

void solve() {
    int n; cin >> n;

    ans_found = false;
    primes_used.clear();

    FOR(i, n) {
        int num; cin >> num;
        int f = fact(num);

        if (primes_used.find(f) != primes_used.end())
            ans_found = true;
        else if (f != 1) primes_used.insert(f);
    }

    cout << (ans_found ? "YES" : "NO") << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    find_primes();

    int t; cin >> t;
    while (t--) solve();

    return 0;
}
