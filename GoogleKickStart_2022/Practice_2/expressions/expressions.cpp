/*____________________________________________________________
// started : 06/29/22
// finished: 06/29/22
// problem : https://codingcompetitions.withgoogle.com/kickstart/round/00000000008f4a94/0000000000b55464
____________________________________________________________*/

#include <bits/stdc++.h>
#include <string.h>

#define FOR(n) for (int i = 0;i < n;i++)
#define FORO(n) for (int i = 1;i < n;i++)
#define ROF(n) for (int i = n - 1;i >= 0;i--)
#define ROFO(n) for (int i = n - 1;i >= 1;i--)
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
#define mp make_pair
#define f first
#define s second
#define endl "\n"
#define BIG_NUMBER (ll)1e18
#define MOD (int)1e9 + 7 

using namespace std;

bool isVowel(char in) {
    const char vowels[] = { 'a', 'e', 'i', 'o', 'u' };

    for (char curr : vowels) {
        if (in == curr) {
            return true;
        }
    }
    return false;
}

bool isSpell(string str, int vowelCnt) {
    string start = "", end = "";
    int m = str.size();
    int startVowel = 0;

    FOR(str.length() / 2) {
        start += str.at(i);
        end = str.at(m - 1 - i) + end;

        if (isVowel(str.at(m - 1 - i))) {
            vowelCnt--;
        }

        if (isVowel(str.at(i))) {
            startVowel++;
            vowelCnt--;
        }

        if (vowelCnt > 0 && startVowel >= 2 && start == end) {
            return true;
        }
    }

    return false;
}

void solve(int test) {
    string input; cin >> input;
    int n = input.length();

    int numVowels = 0;
    FOR(n) {
        if (isVowel(input[i])) {
            numVowels++;
        }
    }

    int l = 0, r = n - 1; // both inclusive
    int vowelsLeft = 0;
    for (;l < r;l++) {
        vowelsLeft = numVowels;
        for (;r > l;r--) {
            if (isSpell(input.substr(l, r - l + 1), vowelsLeft)) {
                cout << "Case #" << test << ": " << "Spell!" << endl;
                return;
            }

            if (isVowel(input[r])) {
                vowelsLeft--;
            }
        }

        if (isVowel(input[l])) {
            numVowels--;
        }

        r = n - 1;
    }

    cout << "Case #" << test << ": " << "Nothing." << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    FORO(t + 1) {
        solve(i);
    }

    return 0;
}
