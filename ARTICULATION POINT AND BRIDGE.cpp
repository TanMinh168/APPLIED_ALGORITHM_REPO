#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e5+5;
int V, E;
vector <int> a[MAX];
int low[MAX];
int d[MAX];
bool ap[MAX];
int b;
int visited[MAX];
int p[MAX];
int t, ans;

void input() {
    cin >> V >> E;
    for (int i = 1; i <= E; i++) {
        int u, v;
        cin >> u >> v;
        a[u].push_back(v); a[v].push_back(u);
    }
}

int isBridge(int u, int v) {
    return 1;
}

void init() {
    for (int v = 1; v <= V; v++) {
        visited[v] = 0;
        low[v] = 2e9;
        d[v] = -1;
    }
    t = 0;
    ans = 0;
}

void DFS(int v, int p = -1) {
    visited[v] = 1;
    d[v] = low[v] = t++;
    int child = 0;
    for (int i = 0; i < a[v].size(); i++) {
        int x = a[v][i];
        if (x == p) continue;
        if (visited[x]) {
            low[v] = min(low[v], d[x]);
        } else {
            DFS(x, v);
            low[v] = min(low[v], low[x]);
            if (low[x] > d[v]) b++;
            if (low[x] >= d[v] && p != -1) {
                ap[v] = true;
            }
            child++;
        }
    }
    if (p == -1 && child > 1) ap[v] = true;
}

void solve() {
    init();
    for (int v = 1; v <= V; v++) {
        if (!visited[v]) DFS(v);
    }
    for (int v = 1; v <= V; v++) {
        if (ap[v]) ans++;
    }
    cout << ans << " " << b;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cout.tie(0);
    input();
    solve();
}
