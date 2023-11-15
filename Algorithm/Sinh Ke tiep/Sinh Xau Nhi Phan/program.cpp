#include <bits/stdc++.h>
using namespace std;

// Sinh xâu nhị phân

void generate(vector<int> &a, const int &n, bool &ok)
{
    int i = n - 1;
    while (i >= 0 && a[i] == 1)
    {
        a[i] = 0;
        --i;
    }
    if (i == -1) // Cấu hình cuối cùng
        ok = false;
    else
        a[i] = 1;
} 

int main()
{
    freopen("inp.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    int n;
    bool ok = true;
    cin >> n;

    // Khởi tạo cấu hình đầu tiên
    vector<int> a(n, 0);

    while (ok)
    {
        // In ra cấu hình đầu tiên
        for (int &x : a)
            cout << x << " ";
        cout << endl;

        generate(a, n, ok);
    }

    return 0;
}