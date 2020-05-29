#include <bits/stdc++.h>
using namespace std;
const int MAX = 50005;

int N;
int a, b;
typedef struct point {
    int id;
    int x;
    int y;
} point;
point p[MAX];

class pointPair {
    public :
    point a;
    point b;
    double dist;
};

double findDist(point a, point b) {
    return sqrt((a.x - b.x) *  (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}


bool sortByX(point a, point b) {
    return a.x < b.x;
}

bool sortByY(point a, point b) {
    return a.y < b.y;
}

pointPair findMinDist(int l, int r) {
    if (r - l == 1) {
        pointPair tmp;
        tmp.a = p[l];
        tmp.b = p[r];
        return tmp;
    }
    int m = (l + r)/2;
    if (r - l == 2) {
        pointPair pp1, pp2, pp3;
        pp1.a = p[l];
        pp1.b = p[r];
        pp1.dist = findDist(p[l], p[r]);
        pp2.a = p[l];
        pp2.b = p[m];
        pp2.dist = findDist(p[l], p[m]);
        pp3.a = p[r];
        pp3.b = p[m];
        pp3.dist = findDist(p[r], p[m]);
        return pp1.dist < pp2.dist ? pp1.dist < pp2.dist ? pp1 : pp3 : pp2.dist < pp3.dist ? pp2 : pp3;
    }
    pointPair L = findMinDist(l, m);
    pointPair R = findMinDist(m+1, r);
    return findDist(L.a, L.b) < findDist(R.a, R.b) ? L : R;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cout.tie(0);
    cin >> N;
    int Id = 0;
    for (int i = 0; i < N; i++) {
        cin >> a >> b;
        p[i].x = a;
        p[i].y = b;
        p[i].id = Id++;
    }
    sort(p, p+N, sortByX);
    cout << "point array : " << endl;
    for (int i = 0; i < N; i++) {
        cout << p[i].x << " " << p[i].y << endl;
    }

    pointPair cloPair = findMinDist(0, N-1);
    double d = cloPair.dist;
    cout << "d = " << d << endl;
    int m = (N-1)/2;
    point strip[N];
    int id = 0;
    for (int i = 0; i < N; i++) {
        if (abs(p[i].x - p[m].x) <= d) strip[id++] = p[i];
    }
    sort(strip, strip+id, sortByY);
    cout << "strip array : " << endl;
    for (int i = 0; i < id; i++) {
        cout << strip[i].id << endl;
    }
    double minStrip = 1000000;
    pointPair tmp;
    pointPair stripAns;
    for (int i = 0; i < id; i++) {
        for (int j = 1; j <= 7 && j < id - i; j++) {
            tmp.a = strip[i]; tmp.b = strip[i+j];
            tmp.dist = findDist(tmp.a, tmp.b);
            if (tmp.dist < minStrip) {
                minStrip = tmp.dist;
                stripAns = tmp;
            }
        }
    }
    pointPair res = minStrip < d ? stripAns : cloPair;
    double resDist = min(minStrip, d);
    if (res.a.id > res.b.id) {
        int tmp = res.a.id;
        res.a.id = res.b.id;
        res.b.id = tmp;
    }
    printf("%d %d %0.6f\n", res.a.id, res.b.id, resDist);
}
