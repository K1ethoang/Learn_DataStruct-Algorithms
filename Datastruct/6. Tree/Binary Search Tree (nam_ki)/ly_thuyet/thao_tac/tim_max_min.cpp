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
void menu(Node *&root);

int maxResult = INT_MIN; // gán cho biến max là giá trị bé nhất của kiểu int
// hàm tìm phần tử max
int maxNode(Node *root)
{
    // ta đều biết cứ duyệt về phải thì phần tử cuối (node lá) sẽ là max
    if (root != NULL)
    {
        // xử lý
        maxResult = root->data;
        maxNode(root->right);
    }
    return maxResult;
}

int minResult = INT_MIN; // gán min là giá trị lớn nhất của kiểu int
int minNode(Node *root)
{
    // ta đều biết cứ duyệt về phải thì phần tử cuối (node lá) sẽ là min
    if (root != NULL)
    {
        minResult = root->data;
        maxNode(root->left);
    }
    return minResult;
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

void output_NLR(Node *root)
{
    if (root != NULL)
    {
        cout << root->data << " ";
        output_NLR(root->left);
        output_NLR(root->right);
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
        cout << "3. Node max" << endl;
        cout << "4. Node min" << endl;
        cout << "5. Thoat" << endl;
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
            int result = maxNode(root);
            cout << "\nMax la: " << result << endl;
            system("pause");
            break;
        }
        case 4:
        {
            int result = minNode(root);
            cout << "\nMin la: " << result << endl;
            system("pause");
            break;
        }
        case 5:
        {
            exit = true;
            break;
        }
        }
    } while (!exit);
}