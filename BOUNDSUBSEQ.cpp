#include <bits/stdc++.h>
using namespace std;

int a[20005];

int main() {
    int res = 0;
    int n, m, M;
    cin >> n >> m >> M;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        int sum = 0;
        for (int j = i; j >= 1; j--) {
            sum += a[j];
            if (sum >= m && sum <= M) res++;
        }
    }
    cout << res;
    return 0;
}
