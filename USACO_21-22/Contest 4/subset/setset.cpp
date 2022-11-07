// started : 03/28/22
// finished: 03/28/22
// problem : http://www.usaco.org/index.php?page=viewproblem&cpid=1218

#include <bits/stdc++.h>

#define ALL(arr) arr.begin(), arr.end()
#define ll long long
#define hashmap unordered_map
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define endl "\n"
#define BIG_NUMBER (ll)pow(10, 18)
#define LETTER_CNT 18

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // pre-compute the relationship between letters 
    string s, t; cin >> s >> t;

    // vector<char> letters;
    // for (char letter = 'a';letter <= 'r';letter++) {
    //     letters.pb(letter);
    // }

    vector<vector<bool>> letterRelationships(LETTER_CNT, vector<bool>(LETTER_CNT, 0));
    for (char i = 'a';i <= 'r';i++) {
        for (char j = 'a';j <= 'r';j++) {
            string str1 = "", str2 = "";
            for (char k : s) {
                if (k == i || k == j) {
                    str1 += k;
                }
            }

            for (char k : t) {
                if (k == i || k == j) {
                    str2 += k;
                }
            }

            if (str1 == str2) {
                letterRelationships[i - 97][j - 97] = true;
            }
            else {
                letterRelationships[i - 97][j - 97] = false;
            }
        }
    }

    // for (vector<bool> a : letterRelationships) {
    //     for (bool b : a) {
    //         cout << b << " ";
    //     }
    //     cout << endl;
    // }

    int q; cin >> q;
    for (int query = 0;query < q;query++) {
        string input; cin >> input;

        bool yayNay = true;
        for (char i : input) {
            for (char j : input) {
                if (!letterRelationships[i - 97][j - 97]) {
                    cout << "N";
                    yayNay = false;
                    break;
                }
            }
            if (!yayNay) {
                break;
            }
        }

        if (yayNay) {
            cout << "Y";
        }
    }
}