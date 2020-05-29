#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e5+5;
int V, E;
vector<int> a[MAX]; /// adjacent list
vector<int> r[MAX]; ///residual graph

///data structure for DFS
int f[MAX]; ///finishing time
char color[MAX];
int t;
int ncc;/// number of connected components in DFSr
int x[MAX]; ///sort list (increasingly finishing time) of vertexes visited by DFS
int id;

void input() {
    cin >> V >> E;
    for (int i = 1; i <= E; i++) {
        int u, v;
        cin >> u >> v;
        a[u].push_back(v);
    }
}

void buildResidualGraph(){
    for(int u = 1; u <= V; u++){
        for(int i = 0; i < a[u].size(); i++){
            int v = a[u][i];
            r[v].push_back(u);
        }
    }
}

void init() {
    for (int v = 1; v <= V; v++) {
        color[v] = 'W';
    }
    t = 0;
}

void DFS(int s) {
    t++;
    color[s] = 'G';
    for (int i = 0; i < a[s].size(); i++) {
        int v = a[s][i];
        if (color[v] == 'W') {
            DFS(v);
        }
    }
    t++;
    f[s] = t;
    color[s] = 'B';
    id++;
    x[id] = s;
}

void DFS() {
    init();
    id = 0;
    for (int v = 1; v <= V; v++) {
        if (color[v] == 'W') {
            DFS(v);
        }
    }
}

void DFSr(int s) {
    t++;
    color[s] = 'G';
    for (int i = 0; i < r[s].size(); i++) {
        int v = r[s][i];
        if (color[v] == 'W') {
            DFSr(v);
        }
    }
    color[s] = 'B';
}

void DFSr() {
    init();
    ncc = 0;
    for (int i = V; i >= 1; i--) {
        int v = x[i];
        if (color[v] == 'W') {
            ncc++;
            DFSr(v);
        }
    }
}

void solve() {
    DFS();
    buildResidualGraph();
    DFSr();
    cout << ncc;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cout.tie(0);
    input();
    solve();
}
