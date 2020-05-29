#include <bits/stdc++.h>
#define MAX 30
using namespace std;

int N, M;///number of courses, semesters
int c[MAX]; ///number of credits
int A[MAX][MAX]; ///condition

int X[MAX]; ///X[i] is the semester to which course i is assigned to
int load[MAX];///load[i] number of credits assigned to semester i
int f_best;///optimal objective value

void input() {
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        cin >> c[i];
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> A[i][j];
        }
    }
}
bool check(int v, int k) {
    for (int i = 1; i <= k-1; i++) { /// duyệt qua các course được phân vào các semester trước course k
        if (A[i][k]) { /// nếu course i phải phân vào một semester trước semester của course k
            if (X[i] >= v) return false;
        }
        if (A[k][i]) { /// ngược lại
            if (X[i] <= v) return false;
        }
    }
    return true;
}
void solution() {
    int max_load = 0;
    for (int i = 1; i <= M; i++) {
        if (max_load < load[i]) max_load = load[i];
    }
    if (max_load < f_best) f_best = max_load;
}

void TRY(int k) {
    for (int v = 1; v <= M; v++) {
        if (check(v,k)) {
            X[k] = v;///assign course k to semester v
            load[v] = load[v] + c[k]; ///update load
            if (k == N) solution();
            else TRY(k+1);
            load[v] = load[v] - c[k]; ///recover
        }
    }
}

void solve() {
    f_best = 10000000;
    for (int i = 1; i <= M; i++) {
        load[i] = 0;
    }
    TRY(1);
    cout << f_best;
}
int main() {
    input();
    solve();
}
