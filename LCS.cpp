#include <bits/stdc++.h>
#define MAX 10000000
using namespace std;
int a[MAX];
int N;
int s[MAX];
int res;

void input() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
}

void solve() {
    s[0] = 1;
    res = s[0];
    for (int i = 1; i < N; i++) {
        s[i] = 1;
        for (int j = 0; j < i; j++) {
            if (a[j] < a[i]) {
                if (s[i] < s[j]+1) s[i] = s[j]+1;
            }
        }
        if (s[i] > res) res = s[i];
    }
    cout << res;
}
 int main() {
    input();
    solve();
 }
