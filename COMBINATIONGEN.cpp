#include <bits/stdc++.h>
#define MAX 10000
using namespace std;

int n, m; ///n: the number of elements, m: the length of sequence
int a[MAX]; /// the combination array
int index = 0;
int ans = 0;

void input() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> a[i];
    }
    return;
}

int solve() {
    if (a[m] != n) {
        a[m]++;
        return ans;
    }
    int i;
    for (i = m-1; i > 0; i--) {
        if (a[i] != n-m+i) {
            a[i]++;
            break;
        }
    }
    if (i == 0) {
        ans = -1;
        return ans;
    }
    while (i <= m) {
        a[i+1] = a[i]+1;
        i++;
    }
    return ans;
}

int main() {
    input();
    solve();
    if (ans == -1) cout << -1;
    else for (int i = 1; i <= m; i++) {
        cout << a[i] << " ";
    }
    return 0;
}
