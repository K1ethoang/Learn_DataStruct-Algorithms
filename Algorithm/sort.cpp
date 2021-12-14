#include <iostream>
#include <algorithm>
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

class InsertionSort : public Array
{
public:
    void sort(int a[], int n)
    {
        for (int i = 1; i < n; i++)
        {
            int key = a[i];
            int j = i - 1;
            while (j >= 0 && a[j] > key)
            {
                a[j + 1] = a[j];
                j--;
            }
            a[j + 1] = key; // a[-1 + 1] = key
            output(a, n);
            cout << endl;
        }
    }
};

class BubbleSort : public Array
{
public:
    void sort(int a[], int n)
    {
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = 0; j < n - i - 1; j++)
            {
                if (a[j] > a[j + 1])
                    swap(a[j], a[j + 1]);
            }
            output(a, n);
            cout << endl;
        }
    }
};

class SelectionSort : public Array
{
public:
    void sort(int a[], int n)
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
                swap(a[i], a[minIndex]);
            output(a, n);
            cout << endl;
        }
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

    int arr[n];
    Array brr;
    brr.input(arr, n);

    // InsertionSort a;
    // cout << "\n\t\tINSERTION SORT\n";
    // cout << "\nStep: \n";
    // a.sort(arr, n);
    // a.output(arr, n);

    // BubbleSort b;
    // cout << "\n\t\tBUBBLE SORT\n";
    // cout << "\nStep: \n";
    // b.sort(arr, n);
    // b.output(arr, n);
    // BubbleSort b;

    SelectionSort c;
    cout << "\n\t\tSELECTION SORT\n";
    cout << "\nStep: \n";
    c.sort(arr, n);
    c.output(arr, n);

    return 0;
}