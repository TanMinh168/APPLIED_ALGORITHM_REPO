#include <bits/stdc++.h>
#define MAX 30
using namespace std;
int n; ///the number of passengers
long c[MAX][MAX];
int a[MAX]; /// permutation array
long long ans = 1e18;
long long cost;

int main() {
    cin >> n;
    for (int i = 0; i <= 2*n; i++) {
        for (int j = 0; j <= 2*n; j++) {
            cin >> c[i][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        a[i] = i;
    }
    do {
        cost = 0;
        for (int i = 1; i <= n; i++) {
            cost += c[a[i]][a[i]+n];
        }
        for (int i = 1; i < n; i++) {
            cost += c[a[i]+n][a[i+1]];
        }
        cost += c[0][a[1]] + c[a[n]+n][0];
        ans = min(ans, cost);
    } while ( next_permutation(a + 1, a + n + 1));

    cout << ans;
    return 0;
    for (int i = 1; i <= n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
    cout << "ans = " << ans << endl;
}
