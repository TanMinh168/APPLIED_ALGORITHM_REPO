#include <bits/stdc++.h>
#include <iostream>
using namespace std;
const int MAX = 1e5 + 5;
int V;
vector<int> a[MAX];
int visited[MAX];
vector<int> c[MAX]; /// c[v] children of v
int ans;

void input() {
    cin >> V;
    for (int i = 1; i < V; i++) {
        int u, v;
        cin >> u >> v;
        a[u].push_back(v); a[v].push_back(u);
    }
}

void init() {
    for (int v = 1; v <= V; v++) {
        visited[v] = 0;
    }
    ans = 0;
}

void BFS(int u) {
    queue<int> Q;
    Q.push(u);
    visited[u] = 1;
    while (!Q.empty()) {
        int v = Q.front(); Q.pop(); /// pop the first element of queue
        for (int i = 0; i < a[v].size(); i++) {
            int x = a[v][i];
            if (visited[x]) {
                continue;
            } else {
                c[v].push_back(x);
                visited[x] = 1;
                Q.push(x);
            }
        }
    }
}

void solve() {
    init();
    BFS(1);
    for (int v = 1; v <= V; v++) {
        if (c[v].empty()) ans++;
    }
    cout << ans;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cout.tie(0);
    input();
    solve();
}
