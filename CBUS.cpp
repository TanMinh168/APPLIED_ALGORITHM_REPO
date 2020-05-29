#include <bits/stdc++.h>
#define MAX 25
using namespace std;

int n, N;  /// n: the number of passengers
int ob; /// ob: the number of on-board passengers
int cap;   /// cap: the capacity of the bus


int x[MAX];
bool visited[MAX];
long long c[MAX][MAX];
long long cost = 0;
long long ans = 1e18;
long long c_min = 1e18;

void input() {
    cin >> n >> cap;
    N = n << 1;
    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= N; j++) {
            cin >> c[i][j];
            if (c[i][j] == 0) continue;
            c_min = min (c[i][j], c_min);
        }
    }
}

void solution(){
    ans = min(ans, cost + c[x[N]][0]);
}

bool check(int v, int k) {
	if(visited[v]) return false; /// do not allow the bus turns back to the prior point
    if(v > n) return visited[v - n];
	if(ob == cap && v <= n) return false;
	return cost < ans;
}
void TRY(int k){
    if (cost + c_min*(N + 1 - k) >= ans) return;
    for(int v = 1; v <= N; v++){
        if (check(v, k)){
            x[k] = v;
            cost += c[x[k - 1]][v];
            visited[v] = true;
            if (v > n) ob--;
            else ob++;
            if(k == N) solution();
			else TRY(k+1);
            cost -= c[x[k - 1]][v];
        	visited[v] = false;           /// recover state
            if (v > n) ob++;
            else ob--;
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cout.tie(0);
    input();
	ob = 0;
	TRY(1);
	cout << ans;
}
