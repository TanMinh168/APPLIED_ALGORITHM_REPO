#include <bits/stdc++.h>
#define MAX 1000000
using namespace std;

long long M; /// N: the number of trees, M: the amount of wood
int N, a[MAX];

long long pile_up(int height) {
    long long pile = 0;
    for (int i = 0; i < N; i++) {
        if ( a[i] > height ) pile += a[i] - height;
    }
    return pile;
}

int main() {
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    int l = 0, r = *max_element(a, a+N);

    while (r - l > 1) {
        int m = (l+r)/2;
        long long pile = pile_up(m);
        if (pile > M) {
            l = m+1;
        }
        else if (pile < M) {
           r = m-1;
        } else {
            l = m;
            break;
        }
    }
    cout << l;
}
