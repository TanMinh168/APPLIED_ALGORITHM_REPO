#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;

int dp[1005][1005];

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cout.tie(0);
    string s;
    cin >> s;
    int n = s.size();
    s = " " + s;
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++) dp[0][i] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= i; j++) {
            if (s[i] == '(') dp[i][j] = dp[i - 1][j - 1];
            if (s[i] == ')') dp[i][j] = dp[i - 1][j + 1];
            if (s[i] == '?') dp[i][j] = (dp[i - 1][j + 1] + dp[i - 1][j - 1]) % MOD;
        }
    }
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= i; j++) cout << "dp[" << i << "]["  << j << "] = " << dp[i][j] << endl;
    }
    cout << dp[n][0];
    return 0;
}
