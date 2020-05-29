#include<iostream>
using namespace std;

typedef long long int ll;

const int MAX = 505;

ll M, K;                // Lưu số lượng cuốn sách, và số phần cần chia
ll Left,Right, mid;
ll Page[MAX];           // Lưu số lượng trang sách của mỗi cuốn
ll Index[MAX];          // Mảng lưu chỉ số của phần tử đầu tiên của mỗi phần
ll ValidIndex[MAX];     // Kết quả cuối cùng

// Cập nhật lại từng phần sao cho tổng mỗi phần không lớn hơn mid
void Update(ll id)
{
    ll sum = 0, t = Index[id];

    for(ll i = Index[id + 1] - 1; i >= t; i--)
    {
        sum += Page[i];

        if(sum == mid)
        {
            Index[id] = i;
            break;
        }else if(sum > mid)
        {
            Index[id] = i + 1;
            break;
        }
    }
}

// Kiểm tra xem với với số lượng lớn nhất của các phần là mid
// có hợp lệ hay không
bool IsValid()
{
    for(int i = 0; i < K; i++)
        Index[i] = i;
    Index[K] = M;

    // Cập nhật lại từng phần
    for(int i = K - 1; i >= 0; i--)
        Update(i);

    // Nếu sau
    if (Index[0] > 0) return false;

    return true;
}

int main()
{

    int T;
    cin >> T;

    for(int tc = 0; tc < T; tc++)
    {
        ll max_page = 0;        // Tìm ra cuốn sách có nhiều trang nhất
        ll sum_page = 0;        // Tìm tổng số trang

        cin >> M >> K;

        for(int i = 0; i < M; i++)
        {
            cin >> Page[i];

            if(Page[i] > max_page) max_page = Page[i];
            sum_page += Page[i];
        }

        // Khi chia ra thành các phần, thì tổng lớn nhất của các phần
        // sẽ nằm trong khoảng từ Left = max_page (số trang nhiều nhất)
        // và Right = sum_page (số trang nhiều nhất)
        Left  = max_page;
        Right = sum_page;

        // Triển khai thuật toán chia để trị
        while (Left < Right)
        {
            mid = (Left + Right) / 2;

            if (IsValid())
            {
                Right = mid;

                // Ta dùng mảng để lưu lại chỉ số của các phần tử
                // để phân chia các phần.
                for(int i = 0; i < K; i++)
                    ValidIndex[i] = Index[i];
            }
            else
            {
                Left = mid + 1;
            }
        }

        // In ra kết quả
        for(int i = 0; i < K - 1; i++)
        {
            for(int j = ValidIndex[i]; j < ValidIndex[i+1]; j++)
                cout << Page[j] << " ";
            cout << "/ ";
        }

        for(int i = ValidIndex[K-1]; i < M; i++)
        {
            cout << Page[i];
            if(i == M-1) break;
            cout << " ";
        }

        cout << endl;
    }

    return 0;
}
