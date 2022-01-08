#include <iostream>
using namespace std;

// khai báo biến toàn cục
int n = 0; // số lượng node

// * Nhập danh sách liên kết đơn các số nguyên
struct Node
{
    int data;
    Node *Next;
};

struct List
{
    Node *Head;
    Node *Tail;
};

void createList(List &l)
{
    l.Head = NULL;
    l.Tail = NULL;
}

Node *createNode(int x)
{
    Node *p = new Node;
    if (p == NULL)
    {
        cout << "\n\tKhong du bo nho de cap phat";
        return NULL;
    }
    else
    {
        p->data = x;
        p->Next = NULL;
    }
    return p;
}

void addNodeBegin(List &l, Node *New)
{
    if (l.Head == NULL)
        l.Head = l.Tail = New;
    else
    {
        New->Next = l.Head;
        l.Head = New;
    }
}

void addNodeEnd(List &l, Node *New)
{
    if (l.Head == NULL)
        l.Head = l.Tail = New;
    else
    {
        l.Tail->Next = New;
        l.Tail = New;
    }
}

void outputList(List l)
{
    for (Node *t = l.Head; t != NULL; t = t->Next)
    {
        cout << t->data << "  ";
    }
}

// ham xoa dau
void delNodeBegin(List &l)
{
    if (l.Head == NULL)
    {
        return;
    }
    else
    {
        Node *p = l.Head;
        l.Head = l.Head->Next;
        delete p;
    }
}
// hàm xoá cuối
void delNodeEnd(List &l)
{
    if (l.Head == NULL)
    {
        return;
    }
    else if (l.Head->Next == NULL) // có 1 phần tử
    {
        delNodeBegin(l);
    }
    else
    {
        for (Node *t = l.Head; t != NULL; t = t->Next)
        {
            if (t->Next == l.Tail)
            {
                delete l.Tail;
                t->Next = NULL;
                l.Tail = t; // cap nhat lai node Tail
                return;
            }
        }
    }
}

// hàm xoá node có khoá k bất kì
void delNodeRandom(List &l, int x)
{

    // nếu node cần xoá nằm đầu danh sách
    if (l.Head->data == x)
    {
        delNodeBegin(l);
    }
    // nếu node cần xoá nằm cuối
    else if (l.Tail->data == x)
    {
        delNodeEnd(l);
    }
    else
    {
        Node *g = new Node; // node nằm trước node cần xoá
        for (Node *t = l.Head; t != NULL; t = t->Next)
        {
            // phat hien phan tu can xoa
            if (t->data == x)
            {
                g->Next = t->Next; // cập nhật liên kết giữa node q và node nằm sau node cần xoá
                delete t;
                return;
            }
            g = t;
        }
    }
}

void menu(List &l)
{
    int luaChon;
    bool thoat = false;
    do
    {
        system("cls");
        cout << "\n\n\t\t*************** MENU ***************";
        cout << "\n\t\t*    1. Them node vao danh sach";
        cout << "\n\t\t*    2. Xuat danh sach lien ket don";
        cout << "\n\t\t*    3. Xoa node bat ki";
        cout << "\n\t\t*    0. Thoat";
        cout << "\n\t\t*************** END ***************";

        cout << "\n\t\t-> Nhap luc chon: ";
        cin >> luaChon;

        switch (luaChon)
        {
        case 0:
        {
            cout << "\nBan da chon thoat chuong trinh";
            system("pause");
            thoat = true;
            break;
        }
        case 1:
        {
            int x;
            cout << "\nNhap gia tri so nguyen: ";
            cin >> x;
            Node *p = createNode(x);
            addNodeEnd(l, p);
            n++;
            break;
        }
        case 2:
        {
            outputList(l);
            system("pause");
            break;
        }
        case 3:
        {
            int x;
            cout << "\nNhap node can xoa: ";
            cin >> x;
            delNodeRandom(l, x);
            break;
        }
        default:
        {
            cout << "\nKhong xac dinh";
            system("pause");
            break;
        }
        }
    } while (!thoat);
}

int main()
{

    List l;
    createList(l); // luôn luôn gọi hàm khởi tạo ds liên kết đơn trước khi thao tác với ds
    menu(l);
    return 0;
}