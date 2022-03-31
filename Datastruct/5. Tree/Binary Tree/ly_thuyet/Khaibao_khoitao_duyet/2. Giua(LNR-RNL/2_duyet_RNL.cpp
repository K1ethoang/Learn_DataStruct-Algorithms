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

// cách duyệt này đã sắp xếp tăng dần cho ta luôn
void output_LNR(Node *root);

// cách duyệt này đã sắp xếp giảm dần cho ta luôn
void output_RNL(Node *root)
{
    // nếu cây còn phần tử thì tiếp tục
    if (root != NULL)
    {
        output_RNL(root->right);
        cout << root->data << " ";
        output_RNL(root->left);
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
        cout << "2. Duyet theo LNR" << endl;
        cout << "3. Duyet theo RNL" << endl;
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
            cout << "\n\t\tDuyet cay theo LNR" << endl;
            output_LNR(root);
            system("pause");
            break;
        }
        case 3:
        {
            cout << "\n\t\tDuyet cay theo RNL" << endl;
            output_RNL(root);
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

void output_LNR(Node *root)
{
    // nếu cây còn phần tử thì tiếp tục
    if (root != NULL)
    {
        output_LNR(root->left);
        cout << root->data << " "; // xuất giá trị của node
        output_LNR(root->right);
    }
}