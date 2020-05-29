#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e6+5;
const int K = 20;

int n, m;
int a[MAX];
int s, t;
int dp[MAX][K];
int lg[MAX];
long long res = 0;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cin >> m;
    for (int i = 0; i < n; i++) {
        dp[i][0] = a[i];
    }
    lg[1] = 0;
    for (int i = 2; i <= MAX; i++) {
        lg[i] = lg[i/2] + 1;
    }
    for (int j = 1; j <= K; j++) {
        for (int i = 0; i + (1 << j) <= n; i++) {
            dp[i][j] = min(dp[i][j-1], dp[i + (1 << (j - 1))][j - 1]);
        }
    }
    for (int i = 1; i <= m; i++) {
        cin >> s >> t;
        int j = lg[t - s + 1];
        res += min(dp[s][j], dp[t - (1 << j) + 1][j]);
    }
    cout << dp[]
    cout << res;
    return 0;
    for (int j = 1; j <= K; j++) {
        for (int i = 0; i + (1 << j) <= n; i++) {
            cout << "dp[" << i << "]["  << j << "] = " << dp[i][j] << endl;
        }
    }
}
