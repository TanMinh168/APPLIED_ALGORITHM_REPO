#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e5 + 5;
int V;
vector<int> a[MAX];
int p[MAX], visited[MAX]; /// p[v] parent of node v

void input() {
    cin >> V;
    for (int i = 1; i < V; i++) {
        int u, v;
        cin >> u >> v;
        a[u].push_back(v); a[v].push_back(u);
    }
}

void BFS(int u) {
    queue<int> Q;
    Q.push(u);
    while (!Q.empty()) {
        int v = Q.front(); Q.pop();
        for (int i = 0; i < a[v].size(); i++) {
            int x = a[v][i];
            if (visited[x]) {
                continue;
            } else {
                visited[x] = 1;
                p[x] = v;
                Q.push(x);
            }
        }
    }
}

void init() {
    for (int v = 1; v <= V; v++) {
        visited[v] = 0; /// color[v] = WHITE
    }
}

void solve() {
    init();
    BFS(1);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cout.tie(0);
    input();
    solve();
    for (int v = 2; v <= V; v++) {
        cout << p[v] << " ";
    }
}
