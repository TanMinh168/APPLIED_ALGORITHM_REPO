o#include <bits/stdc++.h>
#define MAX 31
using namespace std;

int m, n; /// m: the number of teachers, n: the number of courses
int k; /// k: the number of paired conflicting courses
int conflict[MAX][MAX]; /// conflict[i][j]: course i conflict to course j
int load[MAX]; /// load[i]: the number of courses assigned to teacher i
int teach[MAX][MAX]; /// teach[i][j]: mark that teacher i can teach course j
int taught[MAX][MAX]; /// taught[i][j] đánh dấu gv i đã dạy môn j
bool cant_assign;
int ans = 30;

bool cmp(int p, int q) {
    return load[p] < load[q];
}

int get_ans() {
    return *max_element(load + 1, load + n + 1);
}

void arrange(int i) { /// arrange(i): phân công môn i cho 1 giáo viên nào đó
    if (get_ans() >= ans) return; ///nếu có 1 gv dạy nhiều hơn kết quả đã ghi nhận thì thoát
    if (i > n) { /// nếu đã phân công hết các môn thì cập nhật kết quả
        ans = min(ans, get_ans()); ///update minimal load
        return;
    }
    vector < int > index; /// the set of teachers can teach course i

    for (int j = 1; j <= m; j++) {/// duyệt tất cả các giáo viên
        for (int k = 1; k < i; k++) { /// duyệt các môn k trước môn i
            if (conflict[k][i] && taught[j][k]) { /// nếu môn k conflict với môn i và môn k đã được dạy bởi gv j
                ///gán cant_assign = 1 đánh dấu giáo viên j không thể dạy môn i
                cant_assign = true;
                break;
            }
        }
        if (teach[j][i] == 1 && !cant_assign) {
            index.push_back(j); /// đưa giáo viên j vào danh sách các gv có thể dạy môn i
        }
        cant_assign = false;
    }

    ///sort the teachers can teach course i according to the load of them
    sort(index.begin(), index.end(), cmp); /// tìm giáo viên có số môn ít nhất để giao cho môn i
    for (int j : index) {
        load[j] = load[j] + 1;
        taught[j][i] = 1;
        arrange(i+1);
        load[j] = load[j] - 1;
        taught[j][i] = 0;
    }
}

int main() {
    cin >> m >> n;
    for (int j = 1; j <= m; j++) {
        int x; /// x: the number courses teacher j can teach
        cin >> x;
        while (x--) {
            int p;
            cin >> p;
            teach[j][p] = 1;
        }
    }
    cin >> k;
    while (k--) {
        int p1, p2; /// p1 and p2 is two courses conflict
        cin >> p1 >> p2;
        if (p1 > p2) {
            swap(p1, p2);
        }
        conflict[p1][p2] = 1;
    }
    ans = MAX;
    arrange(1);
    for (int i = 1; i <= n; i++) {
        int check = 0;
        for (int j = 1; j <= m; j++) {
            if (teach[j][i] == 1) {
                check = 1;
                break;
            }
        }
        if (check == 0) {
            cout << -1;
            return 0;
        }
    }
    cout << ans << endl;
}

