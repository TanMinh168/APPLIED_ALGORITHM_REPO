#include <bits/stdc++.h>
using namespace std;
const long long MAX = 1e5 + 5;

int T, N, C;
int x[MAX];

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cout.tie(0);
    cin >> T;
    while (T--) {
        cin >> N >> C;
        for (int i = 1; i <= N; i++) {
            cin >> x[i];
        }
        sort (x+1, x+N+1);
        int l = 0, r = x[N]/C+1, m;
        int ans;
        while (r - l > 1) {
            m = (l+r)/2;
            int c = 1;
            int tmp = x[1];
            int i;
            for (i = 2; i <= N; i++) {
                if (x[i] - tmp >= m) {
                    c++; tmp = x[i];
                }
            }
            if (c < C) r = m;
            else l = m;o
        }
        cout << m;
    }

}
