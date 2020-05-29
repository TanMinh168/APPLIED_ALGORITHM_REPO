#include <bits/stdc++.h>
using namespace std;
int N, F; /// N: the number of pies; F: the number of friends
int test;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cout.tie(0);
    cin >> test;
    while(test--) {
        cin >> N >> F;
        int R[N+1];
        for (int i = 1; i <= N; i++) {
            cin >> R[i];
        }
        sort(R+1, R+N+1);

        double l = 0, r = 4e8, m;

        for (int i = 0; i < 50; i++) {
            m = (l+r)/2;

            int cnt = 0;

            for (int i = N; i > 0 && cnt <= F; i--) {
                cnt += (int)floor(acos(-1) * R[i] * R[i] / m);
            }
            if (cnt > F) l = m;
            else r = m;
        }
        printf("%0.6f\n", m);
    }
}


