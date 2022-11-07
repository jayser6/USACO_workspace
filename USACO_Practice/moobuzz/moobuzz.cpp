// started : 12/16/21
// finished: 12/16/21

#include <bits/stdc++.h>

#define ll long long
#define pb push_back
#define mp make_pair
#define f first
#define s second

using namespace std;

ifstream fin ("moobuzz.in");
ofstream fout ("moobuzz.out");

int main() {
    ll n; fin >> n;

    int a[8] = { 1, 2, 4, 7, 8, 11, 13, 14 };

    int index = n % 8 - 1;
    if (index < 0) {
        fout << ((n / 8) - 1) * 15 + a[7];
        return 0;
    }


    ll output = ((n / 8) * 15) + a[index];

    fout << output;
}