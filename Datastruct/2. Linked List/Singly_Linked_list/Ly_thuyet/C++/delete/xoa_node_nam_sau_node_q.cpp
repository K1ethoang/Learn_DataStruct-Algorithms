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

// hàm xoá node sau node q (trong danh sach)
void delNodeAfterNodeQ(List &l)
{
    int x;
    cout << "\nNhap gia tri node q: ";
    cin >> x;
    Node *q = createNode(x);

    //  duyệt ds từ đầu đến cuối để tìm node q
    for (Node *t = l.Head; t != NULL; t = t->Next)
    {
        if (q->data == t->data)
        {
            Node *g = t->Next; // Node g chính là node nằm sau node t (nằm sau node q) <=> node cần xoá
            t->Next = g->Next; // cập nhật lại liên kết giữa node t (node q) với node sau node g
            delete g;
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
        cout << "\n\t\t*    3. Xoa node sau node q";
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
            delNodeAfterNodeQ(l);
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