#include <iostream>
using namespace std;

// ! nếu node có tồn tại thì trả về node đó, không thì trả về NULL

struct Node
{
    int data;
    Node *left;
    Node *right;
};

void createBST(Node *&root);
void add(Node *&root, const int &value);
void output_NLR(Node *root);
Node *findNode(Node *root, const int &value);
void menu(Node *&root);

int main()
{
    Node *root = new Node();
    createBST(root);
    menu(root);
    delete root;
    return 0;
}

void createBST(Node *&root)
{
    root = NULL;
}

void add(Node *&root, const int &value)
{
    if (root == NULL)
    {
        Node *p = new Node();
        p->data = value;
        p->left = NULL;
        p->right = NULL;
        root = p;
    }
    else
    {
        if (value < root->data)
            add(root->left, value);
        else if (value > root->data)
            add(root->right, value);
    }
}

void output_NLR(Node *root)
{
    if (root != NULL)
    {
        cout << root->data << " ";
        output_NLR(root->left);
        output_NLR(root->right);
    }
}

Node *findNode(Node *root, const int &value)
{
    // Nếu node rỗng thì trả về NULL
    if (root == NULL)
        return NULL;
    else // root != NULL
    {
        // nếu phần tử cần tìm mà nhỏ hơn node gốc thì duyệt (đệ quy) qua trái
        if (value < root->data)
            findNode(root->left, value);
        else if (value > root->data)
            findNode(root->right, value); // lớn hơn -> duyệt sang phải
        else                              // value == root->data
            return root;                  // trả về node cần tìm kiếm
    }
}

void menu(Node *&root)
{
    int choose;
    bool exit = false;
    do
    {
        system("cls");
        cout << "##############################" << endl;
        cout << "1. Them phan tu" << endl;
        cout << "2. In cay (NLR)" << endl;
        cout << "3. Tim kiem" << endl;
        cout << "4. Thoat" << endl;
        cout << "##############################" << endl;

        cout << "Nhap lua chon: ";
        cin >> choose;
        switch (choose)
        {
        case 1:
        {
            int value;
            cout << "\nNhap gia tri: ";
            cin >> value;
            add(root, value);
            break;
        }
        case 2:
        {
            cout << "\n\t\tIn cay (NLR)" << endl;
            output_NLR(root);
            system("pause");
            break;
        }
        case 3:
        {
            cout << "\n\t\tTim Kiem" << endl;
            int valueNeedToFind;
            cout << "\nNhap gia tri can tim: ";
            cin >> valueNeedToFind;
            Node *p = NULL;
            p = findNode(root, valueNeedToFind);
            cout << endl;
            output_NLR(root);
            if (p == NULL)
                cout << "\nKhong ton tai";
            else
                cout << "\nTon tai";
            system("pause");
            delete p;
            break;
        }
        case 4:
        {
            exit = true;
            break;
        }
        }
    } while (!exit);
}