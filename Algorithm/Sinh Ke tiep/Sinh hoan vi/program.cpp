#include <bits/stdc++.h>
using namespace std;

// Sinh xâu nhị phân

void generate(vector<int> &a, const int &n, bool &ok)
{
    int i = n - 2;
    while (i >= 0 && a[i] >= a[i + 1])
    {
        --i;
    }

    if (i == -1) // cấu hình cuối cùng
        ok = true;
    else
    {
        // Đi tìm thằng > a[i] trong đoạn [i+1, n-1];
        int j = n - 1;
        while (a[j] < a[i])
            --j;

        swap(a[i], a[j]);
        // Lật ngược lại để ra thằng lớn hơn mà nhỏ nhất
        // [i+1, n-1]
        reverse(a.begin() + i + 1, a.end());
    }
}

int main()
{
    freopen("inp.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    int n;
    bool ok = false;
    cin >> n;

    // Khởi tạo cấu hình đầu tiên
    vector<int> a(n, 0);
    iota(a.begin(), a.end(), 1); // làm cho phần tử tăng dần

    while (!ok)
    {
        // In ra cấu hình đầu tiên
        for (int &x : a)
            cout << x << " ";
        cout << endl;

        generate(a, n, ok);
    }

    return 0;
}