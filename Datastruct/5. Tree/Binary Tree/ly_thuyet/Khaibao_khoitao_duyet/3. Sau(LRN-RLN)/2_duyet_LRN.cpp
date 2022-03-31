#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

void createTree(Node *&root);

void add(Node *&root, const int &value);

// Hàm xuất cây nhị phân theo LRN
void output_LRN(Node *root)
{
    if (root != NULL)
    {
        output_LRN(root->left);
        output_LRN(root->right);
        cout << root->data << " ";
    }
}

// Hàm xuất cây nhị phân theo RLN
void output_RLN(Node *root)
{
    if (root != NULL)
    {
        output_RLN(root->right);
        output_RLN(root->left);
        cout << root->data << " ";
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
        cout << "2. Duyet theo LRN" << endl;
        cout << "3. Duyet theo RLN" << endl;
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
            cout << "\n\t\tDuyet cay theo LRN" << endl;
            output_LRN(root);
            system("pause");
            break;
        }
        case 3:
        {
            cout << "\n\t\tDuyet cay theo RLN" << endl;
            output_RLN(root);
            system("pause");
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

int main()
{
    Node *root = new Node();
    createTree(root);
    menu(root);
    delete root;
    return 0;
}

void createTree(Node *&root)
{
    root = NULL;
}

// hàm thêm
void add(Node *&root, const int &value)
{
    // node rỗng
    if (root == NULL)
    {
        Node *p = new Node();
        p->data = value;
        p->left = NULL;
        p->right = NULL;
        root = p;
    }
    else // cây có tồn tại phần tử
    {
        // nhỏ hơn thì qua trái
        if (value < root->data) // duyệt qua trái để thêm phần tử
            add(root->left, value);
        // nhỏ hơn thì qua phải
        else if (value > root->data) // duyệt qua phải để thêm phần tử
            add(root->right, value);
    }
}