#include <iostream>
#include <fstream>
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

// hàm đọc file
void read_1(Node *&root, ifstream &fileIn)
{
    int n;
    fileIn >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        fileIn >> x;
        add(root, x);
    }
}

void read_2(Node *&root, ifstream &fileIn)
{
    while (!fileIn.eof())
    {
        int x;
        fileIn >> x;
        add(root, x);
        char c;
        fileIn >> c;
    }
}

// ! hàm xuất các node
void outputLeafNode(Node *root)
{
    if (root != NULL)
    {
        // xử lý node hiện tại
        if (root->left == NULL && root->right == NULL)
        {
            cout << root->data << " ";
        }
        outputLeafNode(root->left);
        outputLeafNode(root->right);
    }
}

// ! hàm xuất các node 1 con
void outputNodeHaveOneChild(Node *root)
{
    if (root != NULL)
    {
        // xử lý node hiện tại
        if ((root->left != NULL && root->right == NULL) || (root->left == NULL && root->right != NULL))
        {
            cout << root->data << " ";
        }
        outputNodeHaveOneChild(root->left);
        outputNodeHaveOneChild(root->right);
    }
}

// ! hàm xuất các node 1 con
void outputNodeHaveTwoChild(Node *root)
{
    if (root != NULL)
    {
        // xử lý node hiện tại
        if (root->left != NULL && root->right != NULL)
        {
            cout << root->data << " ";
        }
        outputNodeHaveTwoChild(root->left);
        outputNodeHaveTwoChild(root->right);
    }
}

// ! Hàm xuất node lớn nhất
void maxNode(Node *root)
{
    if (root->right != NULL)
    {
        // if (root->right == NULL)
        //     cout << root->data;
        maxNode(root->right);
    }
    else
        cout << root->data;
}

int main()
{
    Node *root = new Node();
    createBST(root); // khởi tạo cây
    ifstream fileIn_1, fileIn_2;
    fileIn_1.open("./file/input_1.txt", ios_base::in);
    fileIn_2.open("./file/input_2.txt", ios_base::in);
    read_1(root, fileIn_1);
    cout << "\n\tXuat cay theo dang NLR (input_1.txt)" << endl;
    output(root);
    read_2(root, fileIn_2);
    cout << "\n\tXuat cay theo dang NLR (input_2.txt)" << endl;
    output(root);
    cout << "\n\tNode la" << endl;
    outputLeafNode(root);
    cout << "\n\tNode co 1 con" << endl;
    outputNodeHaveOneChild(root);
    cout << "\n\tNode co 2 con" << endl;
    outputNodeHaveTwoChild(root);
    cout << "\n\tNode max" << endl;
    maxNode(root);

    fileIn_1.close();
    fileIn_2.close();
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