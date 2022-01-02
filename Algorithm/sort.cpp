#include <iostream>
#include <algorithm>
using namespace std;

class Array
{
public:
    void input(int a[], int n);
    void output(int a[], int n);
};

class InsertionSort : public Array
{
public:
    void sort(int a[], int n);
};

class BubbleSort : public Array
{
public:
    void sort(int a[], int n);
};

class SelectionSort : public Array
{
public:
    void sort(int a[], int n);
};

class MergeSort : public Array
{
private:
    void merge(int a[], int l, int mid, int r);

public:
    void sort(int a[], int l, int r);
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
    // cout << "\n\tMang da nhap\n";
    // a.output(arr, n);
    // cout << endl;
    // cout << "\nStep: \n";
    // a.sort(arr, n);
    // a.output(arr, n);

    // BubbleSort b;
    // cout << "\n\t\tBUBBLE SORT\n";
    // cout << "\n\tMang da nhap\n";
    // b.output(arr, n);
    // cout << endl;
    // cout << "\nStep: \n";
    // b.sort(arr, n);
    // b.output(arr, n);

    // SelectionSort c;
    // cout << "\n\t\tSELECTION SORT\n";
    // cout << "\n\tMang da nhap\n";
    // c.output(arr, n);
    // cout << endl;
    // cout << "\nStep: \n";
    // c.sort(arr, n);
    // c.output(arr, n);

    MergeSort d;
    cout << "\n\t\tMERGE SORT\n";
    cout << "\n\tMang da nhap\n";
    d.output(arr, n);
    cout << endl;
    d.sort(arr, 0, n - 1);
    cout << "\n\tMang da sort\n";
    d.output(arr, n);

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

void InsertionSort::sort(int a[], int n)
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

void BubbleSort::sort(int a[], int n)
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

void SelectionSort::sort(int a[], int n)
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

void MergeSort::sort(int a[], int l, int r)
{
    if (l < r)
    {
        int mid = (l + r) / 2; // chia thành 2 dãy
        sort(a, l, mid);       // trộn 1/2 dãy bên trái
        sort(a, mid + 1, r);   // trộn 1/2 dãy bên phải
                               // trộn 2 dãy lại với nhau
        merge(a, l, mid, r);
    }
}

void MergeSort::merge(int a[], int l, int mid, int r)
{
    /*
        i: vị trí hiện tại trên dãy con trái
        j: vị trí hiện tại trên dãy con phải
        cur: vị trí hiện tại trên dãy tạm
    */
    int i = l, j = mid + 1, cur = l;
    // mảng phụ
    int *temp = new int[r - l + 1];
    while (i <= mid && j <= r)
    {
        if (a[i] < a[j])
        {
            // lấy phần tử bên dãy con trái
            temp[cur] = a[i];
            i++;
        }
        else // ai > aj
        {
            // lấy phần tử bên dãy phải
            temp[cur] = a[j];
            j++;
        }
        cur++; // end if
    }          // end while

    // khi 1 trong 2 dãy hết phần tử
    // hoàn tất dãy con trái
    for (; i <= mid; i++)
        temp[cur++] = a[i];

    // hoàn tất dãy con trái
    for (; j <= r; j++)
        temp[cur++] = a[j];

    // copy mảng phụ vào mảng chính
    for (cur = l; cur <= r; cur++)
        a[cur] = temp[cur];

    delete temp;
}