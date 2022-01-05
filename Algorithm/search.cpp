#include <iostream>
#include <algorithm>
using namespace std;

class Array
{
public:
    void input(int a[], int n);
    void output(int a[], int n);
};

class LinearSearch : public Array
{
public:
    int search(int a[], int n, int key);
};

class BinarySearch : public Array
{
public:
    int search(int a[], int l, int r, int key);
};

int main()
{
    int n;
    do
    {
        cout << "\nNhap n: ";
        cin >> n;
    } while (n <= 0);

    int a[n];

    // LinearSearch l;
    // l.input(a, n);
    // cout << "\n\t\tGIA TRI VUA NHAP\n";
    // l.output(a, n);
    // int key;
    // cout << "\nGia tri can tim: ";
    // cin >> key;
    // if (l.search(a, n, key) == -1)
    //     cout << "\nKhong co trong phan mang";
    // else
    //     cout << "\nCo trong mang";

    BinarySearch b;
    b.input(a, n);
    cout << "\n\t\tGIA TRI VUA NHAP\n";
    b.output(a, n);
    int key;
    cout << "\nGia tri can tim: ";
    cin >> key;
    // cần sort trước khi search -> đối với binarySearch
    sort(a, a + n);
    int posOfKey = b.search(a, 0, n - 1, key);
    if (b.search(a, 0, n - 1, key) == -1)
        cout << "\nKhong co trong phan mang";
    else
        cout << "\nCo trong mang";

    return 0;
}

void Array::input(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "\na[" << i + 1 << "]: ";
        cin >> a[i];
    }
}

void Array::output(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}

int LinearSearch::search(int a[], int n, int key)
{
    for (int i = 0; i < n; i++)
    {
        if (a[i] == key)
            return i;
    }
    return -1;
}

int BinarySearch::search(int a[], int l, int r, int key)
{
    if (l <= r)
    {
        int mid = (l + r) / 2;
        if (a[mid] == key)
            return mid;
        else if (a[mid] > key)
            return search(a, l, mid - 1, key);
        else // a[mid] < key
            return search(a, mid + 1, r, key);
    }
    return -1; // l > r
}