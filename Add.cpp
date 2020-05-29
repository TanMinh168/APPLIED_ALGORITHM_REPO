#include <iostream>
using namespace std;

int main() {
    unsigned long long a, b, c;
    cin >> a >> b;

    unsigned long long a0 = a%10;
    unsigned long long a1 = (a-a0)/10;
    unsigned long long b0 = b%10;
    unsigned long long b1 = (b-b0)/10;
    unsigned long long c0 = (a0+b0)%10;
    unsigned long long c1 = a1+b1+(a0+b0-c0)/10;
    if (c1>0) cout << c1;
    cout << c0;
}

