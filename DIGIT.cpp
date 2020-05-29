#include <stdio.h>
using namespace std;
long N, tmp;
int Q = 0;
int c[7];
bool m[7];

void input() {
    scanf("%l", &N);
    printf("%l", N);
}

bool check(int v) {
    return !m[v];
}

int solution() {

    if (c[0]*1000+(c[1]-c[2]+c[3])*100+(c[4]-6+c[5])*10+2*c[6]-2 == N)
        Q++;
    return Q;
}

int TRY(int k) {
    for (int v = 1; v < 10; v++) {
        if (check(v)) {
            c[k] = v;
            m[v] = true;
            if (k == 6) solution();
            else TRY(k+1);
            m[v] = false;
        }
    }
}


void solve() {
    TRY(0);
    printf("%d", Q);
}

int main() {
    input();
    solve();
}
