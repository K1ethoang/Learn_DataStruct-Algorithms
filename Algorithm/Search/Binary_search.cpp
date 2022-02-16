#include <iostream>
#include <algorithm>
using namespace std;

void insert(int *a, int n);
void display(int *a, int n);

int binary_search(int *a, int l, int r, int key)
{
    if (l <= r)
    {
        int mid = (l + r) / 2;
        if (key == a[mid])
            return mid;
        else if (key < a[mid])
            return binary_search(a, l, mid - 1, key);
        else // key > a[mid]
            return binary_search(a, mid + 1, r, key);
    }
    return -1;
}

int main()
{
    int n;
    cout << "\nNhap n: ";
    cin >> n;
    int *a = new int[n];
    cout << "\n\t\tNhap mang\n";
    insert(a, n);
    int key;
    cout << "\nNhap gia tri can tim: ";
    cin >> key;
    // cần sort trước khi dùng thuật toán binary này
    sort(a, a + n);
    if (binary_search(a, 0, n - 1, key) != -1)
        cout
            << "\n\tTon tai trong mang";
    else
        cout << "\n\tKhong ton tai trong mang";

    delete[] a;
    return 0;
}

void insert(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "\nNhap a[" << i << "]: ";
        cin >> a[i];
    }
}

void display(int *a, int n)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        count++;
        cout << a[i] << " ";
        if (count == 10)
        {
            cout << endl;
            count = 0;
        }
    }
}