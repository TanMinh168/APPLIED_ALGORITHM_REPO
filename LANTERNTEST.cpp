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
    double maxDis = 0;
    a[0] = -a[1];
    for (int i = 1; i <= N; i++) {
        maxDis = max(maxDis, (double)(a[i] - a[i-1])/2);
    }
    if (a[N] < L) maxDis = max(maxDis, (double)(L - a[N]));
    printf("%0.9f\n", maxDis);
}
