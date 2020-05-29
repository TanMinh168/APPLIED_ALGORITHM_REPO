#include <bits/stdc++.h>
#define MAX  30
using namespace std;

int N;  /// the number of customers
int K;  /// the number of trucks
int Q;  /// the capacity of each truck
int d[MAX]; /// d[i]:  the demand for load of customer i

int Y[MAX]; /// Y[k] is the first point of truck k
int X[MAX]; /// X[i] is the next point of point i
int segments; /// the number of segments
bool visited[MAX];
int ans;
int load[MAX];/// load[k] is the remainder of load in truck k

void input() {
    cin >> N >> K >> Q;
    for (int i = 1; i <= N; i++) {
        cin >> d[i];
    }
}

bool check_X(int v, int k) {
    if (v > 0) {
        if(visited[v]) return false;
        if(load[k] + d[v] > Q) return false; /// condition for load
    }
    return true;
}
void solution() {
    ans++;
    //return;
    for(int k = 1; k <= K; k++) {
        cout << "0";
        int u = Y[k]; /// the first point of departure of truck k
        while (u > 0) {
            cout <<  " - " << u;
            u = X[u];
        }
        cout << " - 0" << endl;
    }
    cout << "--------------" <<endl;
}
void TRY_X(int s, int k) { /// try value for X[s], in the departure of truck k
    for (int v = 0; v <= N; v++) {
        if(check_X(v, k)) {
            X[s] = v; /// the next point of s is point v, in the departure of truck k
            visited[v] = true; segments++; load[k] += d[v];
            if(v == 0){/// truck k returned
                if(k==K){
                    if(segments == N + K) solution();
                } else {
                    TRY_X(Y[k+1], k+1);
                }
            } else {
                TRY_X(v,k);
            }
            visited[v] = false; segments--; load[k]-=d[v]; /// recover
        }
    }

}

bool check_Y(int v, int k) {
    if(visited[v]) return false;
    if(load[k]+d[v] > Q) return false;
    return true;
}

void TRY_Y(int k) {
    for (int v = Y[k-1]+1; v <= N; v++) {
        if (check_Y(v,k)) {
          Y[k] = v;
          visited[v] = true; segments++; load[k]+=d[v];
          if(k==K) { ///done with first point of each truck
            TRY_X(Y[1],1);
          } else {
            TRY_Y(k+1);
          }
          visited[v] = false; segments --; load[k]-=d[v];
        }

    }
}

void solve() {
    ans = 0;
    Y[0] = 0;
    segments = 0;
    for(int k = 1; k <= K; k++) load[k]=0;
    TRY_Y(1);
}
int main(){
    input();
    solve();
    cout << ans;
}
