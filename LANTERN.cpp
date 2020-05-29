#include <bits/stdc++.h>
using namespace std;
const int MAX = 1005;

int N;
long long L;
long long a[MAX];

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cout.tie(0);
    cin >> N >> L;
    for (int i = 1; i <= N; i++) {
        cin >> a[i];
    }
    sort(a+1, a+N+1);
    a[0] = -a[1];

    double l = 0, r = L, m;
    for (int i = 0; i < 60; i++) {
        m = (l + r)/2;
        int cnt = 0;
        for (int i = 1; i <= N; i++) {
            if ((double)(a[i] - a[i-1])/2 <= m) cnt++;
            else break;
        }
        if (a[N] < L) cnt += (L - a[N]) <= m ? 0 : -1;
        if (cnt == N) r = m;
        else l = m;
    }
    printf("%0.9f\n", m);
}
