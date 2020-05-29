#include <bits/stdc++.h>
using namespace std;
const long long MAX = 1e6+5;

int N;
long long M;
long long H[MAX];

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cout.tie(0);
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        cin >> H[i];
    }
    long long l = 0, r = *max_element(H+1, H+N+1);
    long long m;
    long long minDif = 1e10;
    long long ans;
    while (r - l > 1) {
        m = (l+r)/2;
        long long sum = 0;
        for (int i = 1; i <= N; i++) {
            if (H[i] > m) sum += H[i] - m;
        }
        if (sum == M) {
            ans = m; break;
        }
        if (sum > M) {
            l = m;
            if (sum - M < minDif) ans = m;
        }
        else r = m;
    }
    cout << ans;
}
