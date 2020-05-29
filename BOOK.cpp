#include <bits/stdc++.h>
#define MAX 500
using namespace std;

int B, S; /// B: the number of books
          /// S: the number of scribes
long long l, r, m;
long long p[MAX]; /// p[i]: the number of pages of book i
long long first[MAX]; /// first[i]: the indexes of the first books in each part
long long most_valid_first[MAX]; /// the most valid first[]

void update(long long max_val) {
    long long sum = 0, tmp = first[max_val];

    for(long long i = first[max_val+1] - 1; i >= tmp; i--) {
        sum += p[i];

        if(sum == m) {
            first[max_val] = i;
            break;
        } else if(sum > m) {
            first[max_val] = i+1;
            break;
        }
    }
}

bool check() {
    for (int i = 0; i < S; i++)
        first[i] = i;
    first[S] = B;

    for (int i = S-1; i >= 0; i--) {
        update(i);
    }

    if (first[0] > 0) return false;
    return true;
}

int main() {
    int test;
    cin >> test;
    while(test--) {
        cin >> B >> S;
        long long sum_page = 0;
        for (int i = 0; i < B; i++) {
            cin >> p[i];
            sum_page += p[i];
        }
        l = *max_element(p, p+B), r = sum_page;
        while (l < r) {
            m = (l+r)/2;
            if (check()) {
                r = m;
                for (int i = 0; i < S; i++) {
                    most_valid_first[i] = first[i];
                }
            } else {
                l = m+1;
            }
        }

        /// Print the books assigned to scribe 0 -> S-1
        for (int i = 0; i < S-1; i++) {
            for (int j = most_valid_first[i]; j < most_valid_first[i+1]; j++)
                cout << p[j] << " ";
            cout << " / ";
        }

        /// Print the books assigned to scribe S
        for (int i = most_valid_first[S-1]; i < B; i++) {
            cout << p[i];
            if (i == B-1) break;
            cout << " ";
        }
        cout << endl;
    }
    return 0;
}
