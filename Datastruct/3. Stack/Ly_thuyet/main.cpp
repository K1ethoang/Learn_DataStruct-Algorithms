#include "Stack.hpp"
// nhập danh sách stack chứa các số nguyên
// xuất ra màn hình

int main()
{
    int choose;
    bool exit = false;
    Stack<int> s;
    do
    {
        system("cls");
        cout << "\t\t=============== MENU ===============" << endl;
        cout << "\t\t\t1. Add an element to Stack" << endl;
        cout << "\t\t\t2. Display" << endl;
        cout << "\t\t\t3. Pop" << endl;
        cout << "\t\t\t4. Top" << endl;
        cout << "\t\t\t5. Size" << endl;
        cout << "\t\t\t0. Exit" << endl;
        cout << "\t\t=============== <#<3 ===============" << endl;
        cout << "\t\t\tNhap lua chon: ";
        cin >> choose;
        switch (choose)
        {

        case 1:
        {
            int x;
            cout << "\nNhap phan tu can them: ";
            cin >> x;
            s.push(x);
            break;
        }
        case 2:
        {
            s.display();
            cout << endl;
            system("pause");
            break;
        }
        case 3:
        {
            s.pop();
            cout << endl;
            s.display();
            cout << endl;
            system("pause");
            break;
        }
        case 4:
        {
            s.display();
            cout << endl;
            cout << s.top() << endl;
            system("pause");
            break;
        }
        case 5:
        {
            cout << s.sizeOf() << endl;
            system("pause");
            break;
        }
        case 0:
        {
            exit = true;
            break;
        }
        }
    } while (!exit);
    cout << "\nThoat thanh cong !";
    return 0;
}