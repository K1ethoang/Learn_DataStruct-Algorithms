#include <iostream>
using namespace std;

// ! Đề: nhập vào cây nhị phân các số nguyên. Xuất ra màn hình các phần tử của cây nhị phân

struct Node
{
    int data;
    Node *pLeft;
    Node *pRight;
};

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
        p->pLeft = NULL;
        p->pRight = NULL;
        root = p;
    }
    else // cây có tồn tại phần tử
    {
        // nhỏ hơn thì qua trái
        if (value < root->data) // duyệt qua trái để thêm phần tử
            add(root->pLeft, value);
        // nhỏ hơn thì qua phải
        else if (value > root->data) // duyệt qua phải để thêm phần tử
            add(root->pRight, value);
    }
}

// Hàm xuất cây nhị phân theo NLR
void output_NLR(Node *root)
{
    // duyệt cây cho đến hết
    if (root != NULL)
    {
        cout << root->data << " "; // xuất dữ liệu trong node
        output_NLR(root->pLeft);   // duyệt qua trái
        output_NLR(root->pRight);  // duyênt qua phải
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
        cout << "3. Thoat" << endl;
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