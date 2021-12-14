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

// Hàm xoá đàu
void delNodeBegin(List &l)
{
    if (l.Head == NULL)
    {
        return;
    }
    else
    {
        Node *p = l.Head;      // node p la node se xoa
        l.Head = l.Head->Next; // cập nhật lại l.Head là phần tử kế tiếp
        delete p;
    }
}

// Hàm xoá cuối
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
                delete l.Tail;  // xoá đi phần tử cuối
                t->Next = NULL; // Cho con trỏ của node kế cuối trỏ tới null
                l.Tail = t;     // cập nhật lại l.Tail
                return;         // tránh có lỗi không mong muốn xảy ra
            }
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
        cout << "\n\t\t*    3. Xoa node dau tien";
        cout << "\n\t\t*    4. Xoa node cuoi cung";
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
            delNodeBegin(l);
            break;
        }
        case 4:
        {
            delNodeEnd(l);
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