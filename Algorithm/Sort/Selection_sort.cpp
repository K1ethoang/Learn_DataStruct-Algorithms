#include <iostream>
using namespace std;

void insert(int *a, int n);
void display(int *a, int n);

void selection_sort(int *a, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (a[minIndex] > a[j])
                minIndex = j;
        }
        if (minIndex != i)
        {
            int temp = a[i];
            a[i] = a[minIndex];
            a[minIndex] = temp;
        }
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
    selection_sort(a, n);
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