#include <iostream>
using namespace std;

int n = 0; // số lượng node

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
        cout << "\nKhong du bo nho de cap phat";
        return NULL;
    }
    else
    {
        p->data = x;
        p->Next = NULL;
    }
    return p;
}

void output(List &l)
{
    for (Node *t = l.Head; t != NULL; t = t->Next)
    {
        cout << t->data << " ";
    }
}

// ! ADD NODE
// thêm vào đầu danh sách
void addNodeBegin(List &l, Node *p)
{
    if (l.Head == NULL)
    {
        l.Head = l.Tail = p;
    }
    else
    {
        p->Next = l.Head;
        l.Head = p;
    }
}

// thêm vào cuối danh sách
void addNodeEnd(List &l, Node *p)
{
    if (l.Head == NULL)
    {
        l.Head = l.Tail = p;
    }
    else
    {
        l.Tail->Next = p;
        l.Tail = p;
    }
}

// thêm node p vào sau node q
void addNodePAfterNodeQ(List &l, Node *p)
{
    int x;
    cout << "\nNhap gia tri node Q: ";
    cin >> x;
    Node *q = createNode(x);

    if (l.Head == NULL)
    {
        cout << "\n(!) Chua co node nao trong danh sach (!)\n";
        system("pause");
    }
    else
    {
        for (Node *t = l.Head; t != NULL; t = t->Next)
        {
            if (q->data == t->data && t == l.Tail) // nếu node q là node cuối
            {
                Node *h = createNode(p->data);
                addNodeEnd(l, h);
                n++;
            }
            else if (q->data == t->data)
            {
                Node *h = createNode(p->data);
                h->Next = t->Next; // h tro den node dang sau node q
                t->Next = h;
                n++;
            }
        }
    }
}

// thêm node p vào trước node q
void addNodepBeforeNodeQ(List &l, Node *p)
{
    int x;
    cout << "\nNhap gia tri node Q: ";
    cin >> x;
    Node *q = createNode(x);

    if (l.Head == NULL)
    {
        cout << "\n(!) Chua co node nao trong danh sach (!)\n";
        system("pause");
    }
    else
    {
        Node *g = new Node;
        for (Node *t = l.Head; t != NULL; t = t->Next)
        {
            if (l.Head->data == q->data)
            {
                addNodeBegin(l, p);
                n++;
            }
            if (q->data == t->data)
            {
                Node *h = createNode(p->data);
                h->Next = t;
                g->Next = h;
                n++;
            }
            g = t; // node nằm trước node q
        }
    }
}

void addNodeRandom(List &l, Node *p, int pos)
{
    if (l.Head == NULL || n == 1) // chưa có node nào hoặc có 1 node
    {
        addNodeBegin(l, p);
        n++;
    }
    else if (pos == n + 1) // cuối danh sách
    {
        addNodeEnd(l, p);
        n++;
    }
    else // [2; n]
    {
        int currentrPos = 0;
        Node *g = new Node;
        for (Node *t = l.Head; t != NULL; t = t->Next)
        {
            currentrPos++;
            if (pos == currentrPos)
            {
                Node *h = createNode(p->data);
                h->Next = t;
                g->Next = h;
                break;
            }
            g = t;
        }
        n++;
    }
}

// ! DELETE

// hàm xoá node đầu
void delNodeBegin(List &l)
{
    if (l.Head == NULL) // nếu danh sách không có node nào
    {
        return;
    }
    else
    {
        Node *g = l.Head;      // node g là node cần xoá (node đầu)
        l.Head = l.Head->Next; // cập nhật mối liên kết đến node kế tiếp
        delete g;
        n--;
    }
}

// hàm xoá cuối
void delNodeEnd(List &l)
{
    if (l.Head == NULL) // trong danh sách không có node nào
    {
        return;
    }
    else if (l.Head->Next == NULL) // có 1 node trong ds
    {
        delNodeBegin(l);
    }
    else
    {
        // duyệt đến node kế cuối
        for (Node *t = l.Head; t != NULL; t = t->Next)
        {
            if (t->Next == l.Tail)
            {
                delete l.Tail;
                t->Next = NULL; // cập nhật lại mối liên kết của node cuối
                l.Tail = t;
                n--;
                return;
            }
        }
    }
}

// hàm xoá node p nằm sau node q
void delNodePAfterNodeQ(List &l)
{
    int x;
    cout << "\nNhap gia tri node Q: ";
    cin >> x;
    Node *q = createNode(x);

    for (Node *t = l.Head; t != NULL; t = t->Next)
    {
        if (q->data == t->data && t->Next == NULL) // node cuối là node q
        {
            return;
        }
        // khi tìm được node q
        else if (q->data == t->data)
        {
            Node *g = t->Next; // node nằm sau node q
            t->Next = g->Next; // cập nhật lại mối liên kết giữa node q và node sau node xoá
            delete g;          // xoá node p
            n--;
        }
        l.Tail = t; // cập nhật lại node cuối
    }
}

// hàm xoá node p trước node q
void delNodePBeforeNodeQ(List &l)
{
    int x;
    cout << "\nNhap gia tri node Q: ";
    cin >> x;
    Node *q = createNode(x);

    Node *g = new Node;
    for (Node *t = l.Head; t != NULL; t = t->Next)
    {
        if (q->data == t->Next->data)
        {
            g->Next = t->Next; //  cập nhật lại liên kết giữa node trước node p và node sau node p
            delete t;
            n--;
        }
        g = t; // node nằm trước node cần xoá
    }
}

// hàm xoá 1 node có khoá k bất kì
void delNodeRandom(List &l, Node *p)
{
    if (l.Head->data == p->data) // node đầu
    {
        delNodeBegin(l);
    }
    else if (l.Tail->data == p->data)
    {
        delNodeEnd(l);
    }
    else
    {
        Node *g = new Node; // node nằm trước node cần xoá
        for (Node *t = l.Head; t != NULL; t = t->Next)
        {
            // khi tìm đc node cần xoá
            if (t->data == p->data)
            {
                g->Next = t->Next; // cập nhật lại mối liến kết với node sau node p
                delete t;
                n--;
                return;
            }
            g = t; // vị trí node trước node p
        }
    }
}

// ! FREE MEMORY
// Hàm giải phóng vùng nhớ cho danh sách liên kết đơn
void freeMemory(List &l)
{
    // duyệt từ đầu đến cuối ds liên kết
    Node *t = NULL;
    while (l.Head != NULL)
    {
        t = l.Head;
        l.Head = l.Head->Next;
        delete t;
    }
}

void menu(List &l)
{
    int choose;
    bool exit = false;
    do
    {
        system("cls");
        cout << "\t\t~~~~~~~~~~~~~~~~~~~~~~~~ MENU ~~~~~~~~~~~~~~~~~~~~~~~~";
        cout << "\n\t\t|     1. Them node vao danh sach lien ket";
        cout << "\n\t\t|     2. Xuat danh sach lien ket";
        cout << "\n\t\t|     3. Them node p vao sau node q";
        cout << "\n\t\t|     4. Them node p vao truoc node q";
        cout << "\n\t\t|     5. Them 1 node vao vi tri bat ki";
        cout << "\n\t\t|     6. Xoa node dau";
        cout << "\n\t\t|     7. Xoa node cuoi";
        cout << "\n\t\t|     8. Xoa node p nam sau node q";
        cout << "\n\t\t|     9. Xoa node p nam truoc node q";
        cout << "\n\t\t|     10. Xoa node co khoa k bat ki";
        cout << "\n\t\t|     0. Thoat chuong trinh";
        cout << "\n\t\t~~~~~~~~~~~~~~~~~~~~~~ THANK YOU  ~~~~~~~~~~~~~~~~~~~~~~~";

        cout << "\n\t\tNhap lua chon -> ";
        cin >> choose;
        switch (choose)
        {
        case 0:
        {
            cout << "\n(*) Ban da chon thoat chuong trinh (*)\n";
            system("pause");
            exit = true;
            break;
        }
        case 1:
        {
            n++;
            int x;
            cout << "\n(?) Nhap gia tri so nguyen: ";
            cin >> x;
            Node *p = createNode(x);
            addNodeEnd(l, p);
            break;
        }
        case 2:
        {
            output(l);
            system("pause");
            break;
        }
        case 3:
        {
            int x;
            cout << "\nNhap gia tri node P can them vao sau: ";
            cin >> x;
            Node *p = createNode(x);
            addNodePAfterNodeQ(l, p);
            break;
        }
        case 4:
        {
            int x;
            cout << "\nNhap gia tri node P can them vao truoc: ";
            cin >> x;
            Node *p = createNode(x);
            addNodepBeforeNodeQ(l, p);
            break;
        }
        case 5:
        {
            int x, pos;
            cout << "\nNhap gia tri node can them: ";
            cin >> x;
            Node *p = createNode(x);

            do
            {
                cout << "\nNhap vi tri can them: ";
                cin >> pos;

                if (pos < 1 || pos > n + 1)
                {
                    cout << "\nChi co the them node trong doan [1 ; " << n + 1 << "]\n";
                    system("pause");
                }

            } while (pos < 1 || pos > n + 1);
            addNodeRandom(l, p, pos);
            break;
        }
        case 6:
            delNodeBegin(l);
            break;
        case 7:
            delNodeEnd(l);
            break;
        case 8:
            delNodePAfterNodeQ(l);
            break;
        case 9:
            delNodePBeforeNodeQ(l);
            break;
        case 10:
        {
            int x;
            cout << "\nNhap node can xoa: ";
            cin >> x;
            Node *p = createNode(x);
            delNodeRandom(l, p);
            break;
        }
        default:
            cout << "\n(?) Khong xac dinh (?)\n";
            system("pause");
        }
    } while (!exit);
}

int main()
{
    List l;
    createList(l);

    menu(l);
    freeMemory(l);
    return 0;
}