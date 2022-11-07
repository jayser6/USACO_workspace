// started : 01/21/22
// finished: 01/22/22
// Problem : No Time to Paint (USACO Silver) http://usaco.org/index.php?page=viewproblem2&cpid=1087

#include <bits/stdc++.h>

#define ll long long
#define pb push_back
#define mp make_pair
#define f first
#define s second

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    //FILE* fp = fopen("C:\\Users\\jayse\\cpp-workspace\\xcamp\\1.16.22\\fp.in", "r");

    // const char* path = "C:\\fp.in";
    // FILE* fp = fopen(path, "r");
    //ifstream fin("fp.in");
    // ofstream fout("painting.out");


    int n, q;
    // if (fp == NULL) {
    //     printf("no such file.");
    //     return 0;
    // }
    // fin >> n >> q;
    // fscanf(fp, "%d %d", &n, &q);
    scanf("%d %d", &n, &q);


    char colorIn[100000];
    // fscanf(fp, "%s", colorIn);
    scanf("%s", colorIn);

    string color = colorIn;
    color = "!" + color + "!"; // 1-index the string from the front and the back

    vector<int> prefixSum(n + 2, 0), suffixSum(n + 2, 0);

    stack<char> overlap; // abcd b a
    for (int i = 1;i <= n;i++) {
        prefixSum[i] = prefixSum[i - 1];
        while (!overlap.empty() && overlap.top() > color[i]) {
            overlap.pop();
        }
        if (overlap.empty() || overlap.top() < color[i]) {
            overlap.push(color[i]);
            prefixSum[i]++;
        }
    }

    overlap = stack<char>(); // clear the stack
    for (int i = n;i >= 1;i--) {
        suffixSum[i] = suffixSum[i + 1];
        while (!overlap.empty() && overlap.top() > color[i]) {
            overlap.pop();
        }
        if (overlap.empty() || overlap.top() < color[i]) {
            overlap.push(color[i]);
            suffixSum[i]++;
        }
    }

    for (int i = 0;i < q;i++) {
        int a, b; //fin >> a >> b;
        // fscanf(fp, "%d %d", &a, &b);
        scanf("%d %d", &a, &b);

        int output = prefixSum[a - 1] + suffixSum[b + 1];
        printf("%d\n", output);
        // fout << output << endl;
    }
}
