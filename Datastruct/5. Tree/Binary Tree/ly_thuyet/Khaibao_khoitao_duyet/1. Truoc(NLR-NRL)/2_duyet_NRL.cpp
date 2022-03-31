#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

void createTree(Node *&root)
{
    root = NULL;
}

void add(Node *&root, const int &value)
{
    Node *p = new Node();
    // node rỗng
    if (root == NULL)
    {
        p->data = value;
        root = p;
        root->left = NULL;
        root->right = NULL;
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
    // duyệt cây cho đến hết
    if (root != NULL)
    {
        cout << root->data << " "; // xuất dữ liệu trong node
        output_NLR(root->left);    // duyệt qua trái
        output_NLR(root->right);   // duyênt qua phải
    }
}

void output_NRL(Node *root)
{
    // node có data
    if (root != NULL)
    {
        cout << root->data << " ";
        output_NRL(root->right);
        output_NRL(root->left);
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
        cout << "2. Duyet theo NLR (*)" << endl;
        cout << "3. Duyet theo NRL" << endl;
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
            cout << "\n\t\tDuyet cay theo NLR" << endl;
            output_NLR(root);
            system("pause");
            break;
        }
        case 3:
        {
            cout << "\n\t\tDuyet cay theo NRL" << endl;
            output_NRL(root);
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