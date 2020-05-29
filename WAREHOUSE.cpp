#include <bits/stdc++.h>
using namespace std;
const int MAX = 1000;

int N, T, D; /// N: number of stations, T: total of time, D: the max jump
int a[MAX], t[MAX];
int dp[MAX][105];
int ans = 0;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cout.tie(0);
    cin >> N >> T >> D;
    for (int i = 1; i <= N; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= N; i++) {
        cin >> t[i];
    }
    for (int i = 1; i <= N; i++) {
        for (int k = t[i]; k <= T; k++) {
            for (int j = i - 1; j >= max(0, i - D); j--) {
                dp[i][k] = max(dp[j][k - t[i]] + a[i], dp[i][k]);
            }
        ans = max(ans, dp[i][k]);
        }
    }
    cout << ans;
}
