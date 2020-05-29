#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e5+5;

int n, L1, L2;
int a[MAX];
int dp[MAX];/// dp[i] the max gold hunted in warehouse i
int ans = 0;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cout.tie(0);
    cin >> n >> L1 >> L2;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        if (i - L1 < 0) dp[i] = a[i];
        for (int j = i - L1; j >= max(0, i - L2); j--) {
            dp[i] = max(dp[i], dp[j] + a[i]);
        }
        ans = max(dp[i], ans);
    }
    cout << ans;
}
