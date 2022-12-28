#include <iostream>
#include <stack>
#include <iomanip>
#include <string>
using namespace std;

bool Operator_C1_Greater_Operator_C2(char c1, char c2); // Kiểm tra xem C1 có lớn hơn C2 không
// nếu c1 > c2 : return 1;
string convert(string s);

int main()
{
    string s, result;
    cout << "\nNhap bieu thuc trung to can chuyen doi: ";
    cin >> s;
    cout << "\nBieu thuc vua nhap: " << s << endl;
    cout << "\n\t\tKet qua\n\n";
    result = convert(s);
    cout << "\n\tOutput: " << result;
    return 0;
}

bool Operator_C1_Greater_Operator_C2(char c1, char c2)
{
    if ((c1 == '^' || c1 == '*' || c1 == '/') && (c2 == '+' || c2 == '-' || c2 == '('))
        return 1;
    return 0;
}

void displayS(stack<char> s)
{
    while (s.size() != 0)
    {
        cout << s.top();
        s.pop();
    }
}

string convert(string s)
{
    string output;
    stack<char> stack;
    cout << left << setw(6) << "i" << left << setw(10) << "exp[i]" << left << setw(40) << "output" << left << "stack" << endl;
    for (int i = 0; i < s.size(); i++)
    {
        char expI = s[i];
        if ((expI >= 'a' && expI <= 'z') || (expI >= 'A' && expI <= 'Z') || (expI >= '0' && expI <= '9'))
            output.push_back(expI);
        else if (expI == '(')
            stack.push(expI);
        else if (expI == '+' || expI == '-' || expI == '^' || expI == '*' || expI == '/')
        {
            if (stack.size() == 0)
                stack.push(expI);
            else
            {
                while (Operator_C1_Greater_Operator_C2(stack.top(), expI))
                {
                    output.push_back(stack.top());
                    stack.pop();
                    if (stack.size() == 0)
                        break;
                }
                stack.push(expI);
            }
        }
        else if (expI == ')')
        {
            while (stack.top() != '(')
            {
                output.push_back(stack.top());
                stack.pop();
            }
            stack.pop(); // xoá '('
        }
        cout << left << setw(6) << i << left << setw(10) << expI << left << setw(40) << output << left;
        displayS(stack);
        cout << endl;
    }
    while (stack.size() != 0)
    {
        output.push_back(stack.top());
        stack.pop();
    }
    return output;
}