#include <bits/stdc++.h>
#include <algorithm>
#define MAX 10001
using namespace std;

long n;
long a[MAX];
long ans, tmp;

void input() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
}

void solve() {
    int i;
    for (i = n; i >= 1; i--) {
        if (a[i] < a[i+1]) {
            for (int j = i+1; j <= n; j++) {
                if (a[j] > a[i] && a[j+1] < a[i]) {
                    tmp = a[j];
                    a[j] = a[i];
                    a[i] = tmp;
                    break;
                }
            }
            sort(a+i+1, a+n+1);
            break;
        }
    }
    if (i == 0) ans = -1;
}

int main() {
    input();
    solve();
    if (ans == -1) cout << -1;
    else {
        for (int i = 1; i <= n; i++) {
            cout << a[i] << " ";
        }
    }
}
