#include <bits/stdc++.h>
using namespace std;

int n;
string s;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cout.tie(0);
    cin >> n;
    cin >> s;
    int i;
    for (i = n - 1; i >= 0; i--) {
        if (s[i] == '0') {
            s[i] = '1';
            break;
        }
    }
    if (i == -1) cout << -1;
    else {
        for (int j = i+1; j < n; j++) s[j] = '0';
        cout << s;
    }
}
