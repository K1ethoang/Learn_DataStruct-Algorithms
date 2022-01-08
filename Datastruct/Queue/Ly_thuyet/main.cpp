#include "Queue.hpp"

void menu(Queue &q);

int main()
{
    Queue q;
    menu(q);
    return 0;
}

void menu(Queue &q)
{
    int choose;
    bool exit = false;
    do
    {
        system("cls");
        cout << "\t\t=============== MENU ===============" << endl;
        cout << "\t\t\t1. Them 1 phan tu vao stack" << endl;
        cout << "\t\t\t2. Xuat stack" << endl;
        cout << "\t\t\t3. pop()" << endl;
        cout << "\t\t\t4. front()" << endl;
        cout << "\t\t\t5. back()" << endl;
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
            q.push(x);
            break;
        }
        case 2:
        {
            q.display();
            system("pause");
            break;
        }
        case 3:
        {
            q.pop();
            break;
        }
        case 4:
        {
            q.display();
            cout << endl
                 << q.front();
            system("pause");
            break;
        }
        case 5:
        {
            q.display();
            cout << endl
                 << q.back();
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