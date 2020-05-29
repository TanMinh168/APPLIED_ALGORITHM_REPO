#include <bits/stdc++.h>
using namespace std;
const int MAX = 605;
int W, H, N;
int w[205];
int h[205];
int dp[MAX][MAX];

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cout.tie(0);
    cin >> W >> H;
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> w[i] >> h[i];
    }
    for (int i = 1; i <= W; i++) {
        for (int j = 1; j <= H; j++) {
            /// dp[i][j]: the minimal rest for rectangle has w = i, h = j
            dp[i][j] = i * j;
            /// loop for all type of marble
            for (int k = 1; k <= N; k++) {
                /// if there is a marble has 2 dimensions equals exactly to this rectangle,
                /// the rest is 0
                if (i == w[k] && j == h[k]) {
                    dp[i][j] = 0;
                    break;
                }
            }
            /// if there is no marble satisfied, cut the rectangle vertically and horizontally
            /// loop for every unit of the width
            for (int k = 1; k < i; k++) {
                /// the rest of the rectangle is the minimum of both sides of the cut
                dp[i][j] = min(dp[i][j], dp[k][j] + dp[i - k][j]);
            }
            /// loop for every unit of the height
            for (int k = 1; k < j; k++) {
                /// the rest of the rectangle is the minimum of both sides of the cut
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[i][j - k]);
            }
        }
    }
    cout << dp[W][H];
}
