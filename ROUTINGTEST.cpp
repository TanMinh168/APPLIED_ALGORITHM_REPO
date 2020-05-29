#include <bits/stdc++.h>
using namespace std;

int last;
int r[30];

void input() {
    ios::sync_with_stdio(false); cin.tie(0);
    cout.tie(0);
    char arr[30];
    gets(arr);
    int last = 0;

    for (int i = 0; i < strlen(arr); i+=2) {
        r[++last] =  (int)arr[i] - 48;
    }
    for (int i = 1; i <= last; i++) {
            cout << r[i] << " ";
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cout.tie(0);
    int route;
    scanf("%d\n", &route);

    input();
}
