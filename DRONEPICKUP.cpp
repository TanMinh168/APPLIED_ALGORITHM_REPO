#include <bits/stdc++.h>
using namespace std;
const int MAX = 3005;
int N, K, res;
int c[MAX], a[MAX], dp[MAX][105], v[MAX][105];
///dp[i][k]: kết quả của bài toán
///kết thúc ở trạm i và còn lại k trạm
///v[i][k]: đánh dấu những trạm trên lộ trình
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cout.tie(0);
    cin >> N >> K;
    for (int i = 1; i <= N; i++) {
        cin >> c[i];
    }
    for (int i = 1; i <= N; i++) {
        cin >> a[i];
    }
    res = -1;
    for (int i = 1; i <= N; i++) {
        dp[i][1] = c[i];
    }

    for (int i = N - 1; i >= 1; i--) {
    ///duyệt tất cả các trạm có thể bay đến trạm N
        if (i + a[i] >= N) {
            dp[i][2] = c[i] + c[N];
            v[i][2] = 1;
        }
    }

    for (int i = N - 2; i >= 2; i--) {
        /// duyệt các trạm từ cuối lên
        for (int j = i + 1; j <= min(N - 1, i + a[i]); j++) {
            /// duyệt các trạm sau trạm i mà có thể từ i bay được đến
            for (int k = 2; k <= K - 1; k++) {
                if (v[j][k] == 1) {
                    dp[i][k + 1] = max(dp[i][k + 1], dp[j][k] + c[i]);
                    v[i][k+1] = 1;
                }
            }
        }
    }

    for (int i = 2; i <= min(N, 1 + a[1]); i++) {
        for (int k = K; k >= 1; k--) {
            if (v[i][k] == 1) res = max(res, dp[i][k] + c[1]);
        }
    }
    cout << res;

    return 0;
    for (int i = 2; i <= N; i++) {
        for (int k = 2; k <= K; k++) {
            cout << "dp[" << i << "]["  << k << "] = " << dp[i][k] << endl;
            cout << "v[" << i << "]["  << k << "] = " << v[i][k] << endl;
        }
    }
}
