#include <bits/stdc++.h>
using namespace std;

string s;
string p;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cout.tie(0);
    cin >> s;
    cin >> p;
    int f = s.find(p);
    while(f != string::npos) {
        cout << f << endl;
        f = s.find(p, f+1);
    }
}
