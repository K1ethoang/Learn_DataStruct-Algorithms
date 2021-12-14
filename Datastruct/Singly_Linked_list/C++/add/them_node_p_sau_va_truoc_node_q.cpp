#include <iostream>
using namespace std;

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

// thêm node p vào sau node q (nằm trong dslk đơn)
void addNodePAfterNodeQ(List &l, Node *p)
{
    int x;
    cout << "\nNhap gia tri node q: ";
    cin >> x;
    Node *q = createNode(x);

    // nếu ds chỉ có 1 phần tử mà phần tử đó cũng chình là node q
    // ==> bài toán trở thành kĩ thuật thêm vào cuối ds
    // if (q->data == l.Head->data && l.Head->Next == NULL)
    // {
    //     addNodeEnd(l, p);
    // }
    // else
    // {
    // duyệt ds để tìm node q
    for (Node *t = l.Head; t != NULL; t = t->Next)
    {
        // nếu node q có tồn tại thì...
        if (q->data == t->data)
        {
            Node *h = createNode(p->data); // tạo 1 node mới để thêm vào
            h->Next = t->Next;             // node g trỏ đến thằng đằng sau node q
            t->Next = h;                   // node q trỏ đến thằng node g
        }
    }
    // }
}
// Thêm 1 node p vào trước node q (tồn tai trong dslk đơn)
void addNodePBeforeNodeQ(List &l, Node *p)
{
    int x;
    cout << "\nNhap gia tri node q: ";
    cin >> x;
    Node *q = createNode(x);

    // nếu ds chỉ có 1 phần tử mà phần tử đó cũng chình là node q
    // ==> bài toán trở thành kĩ thuật thêm vào đầu danh sách
    if (q->data == l.Head->data && l.Head->Next == NULL)
    {
        addNodeBegin(l, p);
    }
    else
    {
        Node *g = new Node; // Node giữ liên kết với node nằm trước node q
        // duyệt ds để tìm node q
        for (Node *t = l.Head; t != NULL; t = t->Next)
        {
            // nếu node q có tồn tại thì...
            if (q->data == t->data)
            {
                // thực hiện bài toán thêm node p và sau node h <=> thêm node p vào trước node q
                Node *h = createNode(p->data); // tạo 1 node h <=> node p
                h->Next = t;
                g->Next = h;
            }
            g = t; // giữ liên kết với node nằm trước node q trong ds
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
        cout << "\n\t\t*    3. Them node p vao sau node q";
        cout << "\n\t\t*    4. Them node p vao truoc node q";
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
            cout << "\nNhap gia tri node p can them vao sau: ";
            cin >> x;
            Node *p = createNode(x);
            addNodePAfterNodeQ(l, p);
            break;
        }
        case 4:
        {
            int x;
            cout << "\nNhap gia tri node p can them vao truoc: ";
            cin >> x;
            Node *p = createNode(x);
            addNodePBeforeNodeQ(l, p);
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