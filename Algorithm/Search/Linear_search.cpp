#include <iostream>
using namespace std;

void insert(int *a, int n);
void display(int *a, int n);

int linear_search(int *a, int n, int key)
{
    for (int i = 0; i < n; i++)
    {
        if (a[i] == key)
            return 1;
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
    if (linear_search(a, n, key) != -1)
        cout << "\n\tTon tai trong mang";
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