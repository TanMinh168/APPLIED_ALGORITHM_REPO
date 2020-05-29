#include <bits/stdc++.h>
using namespace std;

long long n, k, m, T;
#define MAX 100005

int ckm(int k, int n) {
    if (a[k][n]) return res[k][n];
    if (k == 1) return n;
    if (k == n) return 1;
    if (k > n) return 0;
    res[k][n] = (ckm(k-1, n-1) + ckm(k, n-1))%m;
    a[k][n] = 1;
    return res[k][n];
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cout.tie(0);
    cin >> T;
    while(T--) {
        cin >> n >> k >> m;
        int a[n][n];
        long long res[n][n];
        cout << ckm(k, n);
    }
}
