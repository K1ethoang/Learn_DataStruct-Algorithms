#include "Queue.hpp"

int main()
{
    int choose;
    bool exit = false;
    Queue<int> q;
    do
    {
        system("cls");
        cout << "\t\t=============== MENU ===============" << endl;
        cout << "\t\t\t1. Add an element to Queue" << endl;
        cout << "\t\t\t2. Display" << endl;
        cout << "\t\t\t3. Pop" << endl;
        cout << "\t\t\t4. Front" << endl;
        cout << "\t\t\t5. Back" << endl;
        cout << "\t\t\t6. Size" << endl;
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
            q.display();
            cout << endl;
            system("pause");
            break;
        }
        case 4:
        {
            cout << q.front() << endl;
            system("pause");
            break;
        }
        case 5:
        {
            cout << q.back() << endl;
            system("pause");
            break;
        }
        case 6:
        {
            cout << q.sizeOf() << endl;
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