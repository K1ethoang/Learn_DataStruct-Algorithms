#include "stack.hpp"
// nhập danh sách stack chứa các số nguyên
// xuất ra màn hình

void menu(Stack &s);

int main()
{
    Stack s;
    menu(s);
    return 0;
}

void menu(Stack &s)
{
    int choose;
    bool exit = false;
    do
    {
        system("cls");
        cout << "\t\t=============== MENU ===============" << endl;
        cout << "\t\t\t1. Them 1 phan tu vao stack" << endl;
        cout << "\t\t\t2. Xuat stack" << endl;
        cout << "\t\t\t0. Thoat" << endl;
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
            s.dislay();
            system("pause");
            break;
        }
        case 0:
        {
            exit = true;
            cout << "\nThoat thanh cong !";
            break;
        }
        }
    } while (!exit);
}