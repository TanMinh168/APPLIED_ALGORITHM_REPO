#include <bits/stdc++.h>
using namespace std;
#define MAX 105

int n, route, last; /// n: number of photo-shooting spots, route: number of planned routes, last: length of each route
int c[MAX][MAX];    /// c[i][j]: cost from spot i to spot j
int r[MAX];         /// r[i]: spot i in a route
int x[MAX];
int cost;           /// total cost of route so far
int minCost;        /// minimal cost
bool visited[MAX];
int res[15];

bool check(int v, int k) {
    if (visited[v]) return false;
    if (c[x[k-1]][r[v]] == 0) return false;
    return true;
}

int backTrack(int k) {
    for (int v = 2; v < last; v++) {
        if (check(v, k)) {
            x[k] = r[v];
            cost += c[x[k-1]][x[k]];
            visited[v] = true;
            if (k == last - 1) {
                minCost = c[x[k]][x[last]] == 0 ? minCost : min(cost + c[x[k]][x[last]], minCost);
            }
            else backTrack(k+1);
            cost -= c[x[k-1]][x[k]];
            visited[v] = false;
        }
    }
    if (minCost == 2000) return 0;
    return minCost;
}

void input() {
    char arr[30];
    gets(arr);
    last = 0;
    for (int i = 0; i < strlen(arr); i+=2) {
        r[++last] =  (int)arr[i] - 48;
    }
    x[1] = r[1]; x[last] = r[last];
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cout.tie(0);
    scanf("%d %d\n", &n, &route);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) scanf("%d ", &c[i][j]);
        scanf("\n");
    }

    for (int i = 1; i <= route; i++) {
        input();
        cost = 0; minCost = 2000;
        cout << backTrack(2) << endl;
    }
    return 0;
    for (int i = 1; i < route; i++) {
        cout << res[i] << endl;
    }
    cout << res[route];
}
