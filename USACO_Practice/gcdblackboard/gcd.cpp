// started : 01/10/22
// finished: 01/10/22

#include <bits/stdc++.h>

#define ll long long
#define gcd __gcd
#define pb push_back
#define mp make_pair
#define f first
#define s second

using namespace std;

int main() {
    int n; cin >> n;

    vector<ll> num(n + 1);
    for (int i = 1;i <= n;i++) {
        cin >> num.at(i);
    }

    vector<ll> gcdL(n + 2);
    vector<ll> gcdR(n + 2);
    gcdL.at(0) = 0;
    gcdR.at(n + 1) = 0;

    for (int i = 1;i <= n;i++) {
        gcdL.at(i) = gcd(num.at(i), gcdL.at(i - 1));
    }

    for (int i = n;i >= 1;i--) {
        gcdR.at(i) = gcd(num.at(i), gcdR.at(i + 1));
    }

    ll answer = 0;
    for (int i = 1;i <= n;i++) {
        answer = max(answer, gcd(gcdR.at(i + 1), gcdL.at(i - 1)));        
    }

    cout << answer;
}