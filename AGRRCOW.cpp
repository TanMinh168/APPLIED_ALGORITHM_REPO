#include <bits/stdc++.h>
#define MAX 100000
using namespace std;

long long N, C; /// N: the number of stalls, C: the number of cows
long long x[MAX]; ///x[i]: the location of stall i
long long l, r, m;

bool check(long long max_val) {
    long long pos = x[0];
    long long cow = 1;
    for (int i = 1; i < N; i++) {
        if (x[i]-pos >= max_val) {
            pos = x[i];
            cow++;
            if (cow == C) return true;
        }
    }
    return false;
}

int main() {
    int test;
    cin >> test;
    while (test--) {
        cin >> N >> C;
        for (int i = 0; i < N; i++) {
            cin >> x[i];
        }
        sort(x, x+N);
        l = x[0];
        r = x[N-1];
        long long maximum = -1;
        while (l < r) {
            m = (l+r)/2;
            if (check(m)) {
                if (m > maximum) maximum = m;
                l = m+1;
            } else {
                r = m;
            }
        }
        cout << maximum;
    }
    return 0;
}
