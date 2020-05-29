#include <bits/stdc++.h>
using namespace std;
#define MAX 1005

int N, m, M;
const int mod = 1e9+7;
int res[MAX], a[MAX];

int countPlan(int N) {
    if (a[N]) return res[N];
    if (N == 0) return 1;
    if (N < m && N != 0) return 0;
    long long sum = 0;
    for (int i = m; i <= M; i++) {
        sum += (countPlan(N-i-1))%mod;
    }
    res[N] = N > M ? sum : sum + 1;
    a[N] = 1;
    return res[N];
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cout.tie(0);

    cin >> N >> m >> M;
    cout << countPlan(N) + countPlan(N-1);
}
