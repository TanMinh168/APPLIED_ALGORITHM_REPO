#include <bits/stdc++.h>
using namespace std;
#define MAX 35

int n, K;
int m;
int G[MAX][MAX];
int a, b;
int res;
int x[MAX];
bool visited[MAX][MAX];
bool node[MAX];

bool check(int v, int k) {
    if (node[v]) return false;
    if (visited[x[k-1]][v]) return false;
    if (k > 1 && G[x[k-1]][v] == 0) return false;
    return true;
}

int backTrack(int k) {
    for (int v = 1; v <= n; v++) {
        if (check(v, k)) {
            x[k] = v;
            node[v] = true;
            visited[x[k-1]][v] = true;
            visited[v][x[k-1]] = true;
            if (k == K+1) res++;
            else backTrack(k+1);
            node[v] = false;
            visited[x[k-1]][v] = false;
            visited[v][x[k-1]] = false;
        }
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cout.tie(0);
    cin >> n >> K;
    cin >> m;
    for (int i = 1; i <= m; i++) {
        cin >> a >> b;
        G[a][b] = 1;
        G[b][a] = 1;
    }
    res = 0;
    cout << backTrack(1)/2;
}
