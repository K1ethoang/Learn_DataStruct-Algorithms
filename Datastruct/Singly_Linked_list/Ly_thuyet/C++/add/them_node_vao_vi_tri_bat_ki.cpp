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

void addNodeRandomPos(List &l, Node *p, int pos) // thêm node p vào vị trí pos trong ds l
{
    // ds đang rỗng
    if (l.Head == NULL || pos == 1)
    {
        addNodeBegin(l, p);
    }
    else if (pos == n + 1)
    {
        addNodeEnd(l, p);
    }
    else // pos nằm trong đoạn [2;n]
    {
        int currentPos = 0;
        Node *g = new Node;
        for (Node *t = l.Head; t != NULL; t = t->Next)
        {
            currentPos++;
            if (pos == currentPos)
            {
                Node *h = createNode(p->data);
                h->Next = t;
                g->Next = h;
                break;
            }
            g = t;
        }
    }
    n++;
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
        cout << "\n\t\t*    3. Them node p vao vi tri bat ki";
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
            cout << "\nNhap gia tri can them: ";
            cin >> x;
            Node *p = createNode(x);
            // nhập vi trí cần thêm
            int pos;
            do
            {
                cout << "\nNhap vi tri can them: ";
                cin >> pos;
                if (pos < 1 || pos > n + 1)
                {
                    cout << "\nVi tri can them phai nam trong doan [1 ; " << n + 1 << "]\n";
                    system("pause");
                }
            } while (pos < 1 || pos > n + 1);

            addNodeRandomPos(l, p, pos);
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