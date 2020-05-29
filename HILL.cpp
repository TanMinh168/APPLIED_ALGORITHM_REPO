#include <bits/stdc++.h>
using namespace std;
#define MAX 1000005

int preHill[MAX], sufHill[MAX], preValley[MAX], sufValley[MAX];

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<int> a(n + 2);

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (int i = 2; i <= n; i++) {
        preHill[i] = a[i] > a[i-1] ? preHill[i-1] + 1 : 0;
        preValley[i] = a[i] < a[i-1] ? preValley[i-1] + 1 : 0;
    }
    for (int i = n-1; i >= 1; i--) {
        sufHill[i] = a[i] > a[i+1] ? sufHill[i+1] + 1 : 0;
        sufValley[i] = a[i] < a[i+1] ? sufValley[i+1] + 1 : 0;
    }

    int hill = 0, valley = 0;
    for (int i = 1; i <= n; i++) {
        hill = max(hill, min(preHill[i], sufHill[i]));
        valley = max(valley, min(preValley[i], sufValley[i]));
    }
    cout << hill << " " << valley;
}

