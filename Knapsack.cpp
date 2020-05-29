#include <bits/stdc++.h>
using namespace std;
const int MAX = 35;
int n, b;   /// n: number of objects, b: the capacity of the knapsack
int w[MAX]; ///w[i]: weight of object i
int v[MAX]; ///v[i]: value of object i
int r[MAX][1000005]; ///r[i][j]: result of problem when we put the subset of the object from i to n into the knapsack of capacity j

int dp(int i, int c) {
    ///stop condition
    if (c < 0) return -2e9;
    if (i > n) return 0;
    ///check if r[i][c] has already been computed
    if (r[i][c] != 0) return r[i][c];
    ///base case
    r[i][c] = max(dp(i+1, c), v[i] + dp(i+1, c - w[i]));
    return r[i][c];
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cout.tie(0);
    cin >> n >> b;
    for (int i = 1; i <= n; i++) {
        cin >> w[i] >> v[i];
    }
    cout << dp(1, b);
}
