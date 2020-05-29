#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e5+5;

int N, K;
int a[MAX];
int res = 0;

int solve(int x, int l, int r) {
    cout << x << " " << a[l] << " " << a[r] << endl;
    if (l >= r) return 0;
    int sum = x + a[l] + a[r];
    if (sum == K) {
        cout << x << " " << a[l] << " " << a[r] << endl;
        return 1 + solve(x, l + 1, r - 1);
    }
    else if (sum < K) return solve(x, l + 1, r);

    else return (x, l, r - 1);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cout.tie(0);
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    sort (a, a+N);
    cout << solve(a[2], 3, 5);
    return 0;
    for (int i = 0; i < N - 2; i++) {
        cout << solve(a[i], i + 1, N - 1) << endl;
    }
    ///cout << res;
}
