#include <iostream>
using namespace std;

// tính giai thừa
int factorial(int n)
{
    // bài toán cơ sở
    if (n == 0)
        return 1;
    // công thức quy nạp
    else
        return n * factorial(n - 1);
}

// tính fibonacci
int fibonacci(int n)
{
    cout << "\nCan tinh F" << n;
    if (n <= 2)
        return 1;
    else
        return fibonacci(n - 1) + fibonacci(n - 2);
}

// in tu 0 -> n - 1
void printElement(int a[], int n, int index)
{
    if (index == n)
        return;
    else
    {
        cout << a[index] << " ";
        printElement(a, n, ++index);
    }
}

// đệ quy có nhớ
int f[1000];
int fibonacci2(int n)
{
    cout << "\nCan tinh F" << n;
    if (f[n] != 0)
        return f[n];

    if (n <= 2)
    {
        f[1] = 1;
        f[2] = 1;
    }

    f[n] = fibonacci2(n - 1) + fibonacci2(n - 2);
    return f[n];
}

// khử đệ quy
int fibo(int n)
{
    int ff[n];
    // bài toán cơ sở
    ff[1] = 1;
    ff[2] = 1;
    for (int i = 3; i <= n; i++)
    {
        // công thức quy nạp
        ff[i] = ff[i - 1] + ff[i - 2];
    }

    return ff[n];
}

int main()
{
    // int n = 10;
    // cout << "\nNhap n: ";
    // cin >> n;
    // cout << "==> " << n << "! = " << factorial(n);
    // cout << "==> Fibonnaci of" << n << " = " << fibonacci(n);
    // cout << "==> So buoc cua thap ha noi: " << thapHaNoi(n);

    // int n = 5;
    // int a[] = {1, 4, 5, 2, 3};
    // printElement(a, n, 0);

    // cout << "\nFibo2: " << fibonacci2(10);
    cout << "\nFibo: " << fibo(10);

    return 0;
}