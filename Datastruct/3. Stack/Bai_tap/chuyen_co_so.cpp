#include <iostream>
#include <stack>
using namespace std;

stack<int> convert(int radixToChange, int number)
{
    stack<int> result;
    while (number != 0)
    {
        result.push(number % radixToChange);
        number /= radixToChange;
    }
    return result;
}

void output(stack<int> s)
{
    cout << "\nKet qua: ";
    while (s.size() != 0)
    {
        // hệ 2 - 8
        if (s.top() < 10)
            cout << s.top();
        else
        {
            // hệ 16
            switch (s.top())
            {
            case 10:
                cout << "A";
                break;
            case 11:
                cout << "B";
                break;
            case 12:
                cout << "C";
                break;
            case 13:
                cout << "D";
                break;
            case 14:
                cout << "E";
                break;
            case 15:
                cout << "F";
                break;
            }
        }
        s.pop(); // xoá 1 phần tử
    }
}

int main()
{
    int n, radix;
    cout << "\nNhap so (he 10): ";
    cin >> n;
    cout << "\nNhap he can chuyen (2 - 8 - 16): ";
    cin >> radix;

    stack<int> s;
    s = convert(radix, n);
    output(s);
    return 0;
}