// started : 02/16/22
// finished: 02/16/22

#include <bits/stdc++.h>

#define ALL(arr) arr.begin(), arr.end()
#define ll long long
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define endl "\n"

using namespace std;

void solve(int caseNum) {
    string kingdom; cin >> kingdom;

    char finalLetter = kingdom.at(kingdom.size() - 1);

    char vowels[] = {'A', 'E', 'I', 'O', 'U', 'a', 'e', 'i', 'o', 'u'};
    const int VOWELS_CNT = 10;

    bool endsInVowel = false;
    for (int i = 0;i < VOWELS_CNT;i++) {
        if (finalLetter == vowels[i]) {
            endsInVowel = true;
        }
    }

    cout << "Case #" << caseNum << ": " << kingdom << " is ruled by ";
    if (endsInVowel) {
        cout << "Alice." << endl;
    }
    else if (finalLetter == 'Y' || finalLetter == 'y') {
        cout << "nobody." << endl;
    }
    else {
        cout << "Bob." << endl;
    }
}

int main() {
    int t; cin >> t;

    for (int i = 0;i < t;i++) {
        solve(i + 1);
    }
}
