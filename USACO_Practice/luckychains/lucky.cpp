/*____________________________________________________________
// started : 01/06/23
// finished:
// problem : https://codeforces.com/problemset/problem/1766/D
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

const int MAX_X = 1e7, P_MAX = 1e4;
vector<int> primes;
bool sieve[P_MAX];

void find_primes() {
    for (int i = 2; i < P_MAX;i++) {
        if (!sieve[i]) {
            primes.pb(i);
            for (int j = 2 * i;j < P_MAX;j += i) sieve[j] = true;
        }
    }
}

vector<int> get_primes(int n) {
    vector<int> prime_factors;
    for (int p : primes) {
        if (p * p > n) break;
        if (n % p == 0) prime_factors.pb(p);
        while (n % p == 0) n /= p;
    }
    if (n != 1) prime_factors.pb(n);
    return prime_factors;
}

int per_prime(int n, int a) {
    int ans = n - a % n;
    for (int p : get_primes(n)) if (n % p == 0) ans = min(ans, p - a % p);

    return ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    find_primes();

    int n; cin >> n;
    FOR(i, n) {
        int a, b; cin >> a >> b;
        int dif = abs(a - b);

        if (dif == 1) cout << -1 << endl;
        else if (min(a, b) != 1 && gcd(a, b) != 1) cout << 0 << endl;
        else cout << per_prime(dif, a) << endl;
    }

    return 0;
}
