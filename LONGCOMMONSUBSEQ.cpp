#include <bits/stdc++.h>
#define MAX 10001
using namespace std;

int N, M;
int x[MAX], y[MAX];
int common[MAX][MAX];

void input() {
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        cin >> x[i];
    }
    for (int i = 1; i <= M; i++) {
        cin >> y[i];
    }
}

void solve() {
    for (int i = 0; i <= N; i++) {
        common[i][0] = 0;
    }
    for (int i = 0; i <= M; i++) {
        common[0][i] = 0;
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            if (x[i] == y[j]) common[i][j] = common[i-1][j-1]+1;
            else common[i][j] = max(common[i-1][j], common[i][j-1]);
        }
    }
    cout << common[N][M];
}

int main() {
    input();
    solve();
}
