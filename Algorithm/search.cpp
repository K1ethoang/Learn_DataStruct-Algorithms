#include <iostream>
using namespace std;

class Array
{
public:
    void input(int a[], int n)
    {
        for (int i = 0; i < n; i++)
        {
            cout << "\na[" << i + 1 << "]: ";
            cin >> a[i];
        }
    }

    void output(int a[], int n)
    {
        for (int i = 0; i < n; i++)
        {
            cout << a[i] << " ";
        }
    }
};

class LinearSearch : public Array
{
public:
    int search(int a[], int n, int key)
    {
        for (int i = 0; i < n; i++)
        {
            if (a[i] == key)
                return i;
        }
        return -1;
    }
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

    LinearSearch l;
    l.input(a, n);
    cout << "\n\t\tGIA TRI VUA NHAP\n";
    l.output(a, n);
    int key;
    cout << "\nGia tri can tim: ";
    cin >> key;
    int posOfKey = l.search(a, n, key);
    cout << "\nVi tri cua gia tri do la: " << posOfKey;

    return 0;
}