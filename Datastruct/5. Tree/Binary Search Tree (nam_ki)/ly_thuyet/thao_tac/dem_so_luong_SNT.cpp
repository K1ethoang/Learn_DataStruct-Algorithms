#include <iostream>
#include <cmath>
using namespace std;

// ! Đếm số lượng số nguyên tố trong cây nhị phân tìm kiếm

struct Node
{
    int data;
    Node *left;
    Node *right;
};

void createBST(Node *&root);
void add(Node *&root, const int &value);
void output_NLR(Node *root);
bool isPrimeNumber(const int &number);
void countPrimeNumber(Node *root, int &result);
void menu(Node *&root);

int main(void)
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

bool isPrimeNumber(const int &number)
{
    if (number < 2)
        return 0;
    else
    {
        if (number == 2)
            return 1;
        else
        {
            for (int i = 2; i <= sqrt(number); i++)
            {
                if (number % i == 0)
                    return 0;
            }
        }
    }
    return 1;
}

// đếm số lượng SNT
void countPrimeNumber(Node *root, int &result)
{
    if (root != NULL)
    {
        if (isPrimeNumber(root->data))
            result++;
        countPrimeNumber(root->left, result);
        countPrimeNumber(root->right, result);
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
        cout << "3. Dem so nguyen to" << endl;
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
            int result = 0;
            countPrimeNumber(root, result);
            cout << "\nSo nguyen to co trong cay: " << result << endl;
            output_NLR(root);
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