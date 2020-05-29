#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e5;
int V, E;
vector<int> a[MAX];
int d[MAX]; /// d[v] is the level of v
int visited[MAX];

void input() {
    cin >> V >> E;
    int u, v;
    for (int i = 1; i <= E; i++) {
        cin >> u >> v;
        a[u].push_back(v); a[v].push_back(u);
    }
}

int BFS(int u) {
    queue<int> Q;
    Q.push(u);
    d[u] = 0;
    while (!Q.empty()) {
        int v = Q.front(); Q.pop(); /// pop the first element of queue
        for (int i = 0; i < a[v].size(); i++) {
            int x = a[v][i]; /// x is adjacent vertex of v
            if (d[x] > -1) { /// if color(x) = GRAY
                if (d[v] % 2 == d[x] % 2) return 0; ///if done color(u) = BLACK
            } else {
                d[x] = d[v] + 1;
                Q.push(x);
            }
        }
    }
}

void init() {
    for (int v = 1; v <= V; v++) {
        d[v] = -1; /// color(v) = WHITE
    }
}

void solve() {
    init();
    int ans = 1;
    for (int v = 1; v <= V; v++) {
        if (d[v] == -1) {
            if (!BFS(v)) {
                ans = 0; break;
            }
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
