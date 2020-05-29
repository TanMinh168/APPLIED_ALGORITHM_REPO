#include <bits/stdc++.h>
#include <vector>
#define MAX 100001
using namespace std;
int N, M; /// N: number of vertexes, M: number of edges
vector<int> a[MAX]; /// adjacent array of each vertex
int visited[MAX];
int ans;

void input() {
    cin >> N >> M;
    for (int i = 1; i <= M; i++) {
        int u, v;
        cin >> u >> v;
        a[u].push_back(v); a[v].push_back(u);
    }
}

void init() {
    for (int i = 1; i <= N; i++) {
        visited[i] = 0;
    }
}

void DFS(int u) {
    for (int i = 0; i < a[u].size(); i++) {
        int v = a[u][i];
        if (!visited[v]) {
            visited[v] = 1;
            DFS(v);
        }
    }
}

void solve() {
    init();
    ans = 0;
    for (int v = 1; v <= N; v++) {
        if (!visited[v]) {
            ans++;
            DFS(v);
        }
    }
    cout << ans;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cout.tie(0);
    input();
    solve();
}
