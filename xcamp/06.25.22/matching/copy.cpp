#include <iostream>
#include <math.h>
#include <string>
#include <algorithm>
#include <fstream>
#include <map>
#include <vector>
#include <queue>
#include <deque>
#include <utility>
#include <climits>
#include <set>
#include <bitset>
#include <unordered_map>
#include <unordered_set>

#define mp make_pair
#define pb push_back
#define pq priority_queue
#define ll long long
#define umap unordered_map
#define uset unordered_set
#define endl '\n'
#define FOR(Z) for (int i = 0; i < (Z); i++)

using namespace std;

string s1;
string s2;
int occurences = 0;

const int P = 37;
const long long MODULUS = 10e12 + 9;

int windowSize;
long long s1Hash = 0;
long long s2Hash = 0;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> s1 >> s2;

    // edge case
    if (s1.size() < s2.size()) {
        cout << 0 << endl;
        return 0;
    }

    windowSize = s2.size();

    for (int i = 0; i < windowSize; i++) {
        s1Hash += (int)((s1[i] % 'a' + 1) * pow(P, (windowSize - i - 1))) % MODULUS;
        s2Hash += (int)((s2[i] % 'a' + 1) * pow(P, (windowSize - i - 1))) % MODULUS;
    }
    if (s1Hash == s2Hash) occurences++;

    // INCLUSIVE
    int L = 0;
    int R = L + windowSize;

    for (int i = 0; i < s1.size() - windowSize; i++) {
        int removedVal = ((s1[L] % 'a' + 1) * pow(P, windowSize - 1));
        s1Hash -= removedVal;

        while (s1Hash < 0) s1Hash += MODULUS;

        s1Hash *= P;
        s1Hash += (s1[R] % 'a' + 1);
        s1Hash %= MODULUS;


        if (s1Hash == s2Hash) occurences++;

        L++;
        R++;
    }

    cout << occurences << endl;

}