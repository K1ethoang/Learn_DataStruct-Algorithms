#include <iostream>
using namespace std;

void insert(int *a, int n);
void display(int *a, int n);

void insertion_sort(int *a, int n)
{
    for (int i = 1; i < n; i++)
    {
        // 2 31 4
        int key = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > key)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key; // a[-1 + 1]
    }
}

int main()
{
    int n;
    cout << "\nNhap n: ";
    cin >> n;
    int *a = new int[n];
    cout << "\n\t\tNhap mang\n";
    insert(a, n);
    cout << "\n\t\tMang vua nhap\n";
    display(a, n);
    cout << "\n\t\tMang sau khi sort\n";
    insertion_sort(a, n);
    display(a, n);

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