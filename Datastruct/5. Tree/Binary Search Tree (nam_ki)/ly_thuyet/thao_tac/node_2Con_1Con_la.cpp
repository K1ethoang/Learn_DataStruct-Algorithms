#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

void createBST(Node *&root);
void add(Node *&root, const int &value);
void output(Node *root);
void menu(Node *&root);

// xuất các node có 2 con
void nodeHaveTwoChild(Node *root)
{
    if (root != NULL)
    {
        // xử lí
        if (root->left != NULL && root->right != NULL)
            cout << root->data << " ";
        nodeHaveTwoChild(root->left);
        nodeHaveTwoChild(root->right);
    }
}

// xuất các node có 1 con
void nodeHaveAChild(Node *root)
{
    if (root != NULL)
    {
        if ((root->left != NULL && root->right == NULL) || (root->right != NULL && root->left == NULL))
            cout << root->data << " ";
        nodeHaveAChild(root->left);
        nodeHaveAChild(root->right);
    }
}

// xuất các node lá
void leafNode(Node *root)
{
    if (root != NULL)
    {
        if (root->left == NULL && root->right == NULL)
            cout << root->data << " ";
        leafNode(root->left);
        leafNode(root->right);
    }
}

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

void output(Node *root)
{
    if (root != NULL)
    {
        cout << root->data << " ";
        output(root->left);
        output(root->right);
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
        cout << "2. In cay" << endl;
        cout << "3. In cac Node co 2 con" << endl;
        cout << "4. In cac Node co 1 con" << endl;
        cout << "5. In cac Node la" << endl;
        cout << "6. Thoat" << endl;
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
            output(root);
            system("pause");
            break;
        }
        case 3:
        {
            nodeHaveTwoChild(root);
            system("pause");
            break;
        }
        case 4:
        {
            nodeHaveAChild(root);
            system("pause");
            break;
        }
        case 5:
        {
            leafNode(root);
            system("pause");
            break;
        }
        case 6:
        {
            exit = true;
            break;
        }
        }
    } while (!exit);
}