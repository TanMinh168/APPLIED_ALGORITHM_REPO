#include <bits/stdc++.h>
#define MAX 400
using namespace std;
int n, m; ///n: the number of the cities, m: the number of routes
int a[MAX], b[MAX];
long long c[MAX][MAX];
int X[MAX]; ///X[i] is the i th city traveled
long long cost = 0;
long long ans = 1e18;
long long c_min = 1e18;
bool travel[MAX];
long long t = 1e18;

void input() {
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) c[i][j]=1e18;
    }

    for (int i = 1; i <= m; i++) {
        cin >> a[i] >> b[i];
        cin >> c[a[i]][b[i]];
        c_min = min(c_min, c[a[i]][b[i]]);
    }
}

void solution() {
    ans = min(ans, cost + c[X[n]][X[1]]); /// update minimal cost
}

void TRY(int k) {
    if (cost + c_min*(n+1-k) >= ans) return;
    for (int v = 1; v <= n; v++) {
        if (travel[v] == false) {
            X[k] = v; /// assign city v to the travel
            cost = cost + c[X[k-1]][X[k]]; /// update cost
            travel[v] = true; /// update city traveled
            if (k == n) solution();
            else TRY(k+1);
            cost = cost - c[X[k-1]][X[k]]; ///recover cost
            travel[v] = false; ///recover city traveled
        }
    }
}

int main() {
    input();
    X[1] = 1; travel[1] = true;
    TRY(2);
    cout << ans;
    return 0;
}
