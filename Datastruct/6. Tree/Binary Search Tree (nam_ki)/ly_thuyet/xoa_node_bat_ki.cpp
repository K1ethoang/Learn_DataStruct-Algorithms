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

/* - Node x là node cần xoá
- Nếu x:
  - 1. Node lá: xoá bình thường - lúc này node x là node tự do (không có con trái và con phải)
  - 2. Node 1 con: trước khi xoá node x - chúng ta phải cập nhật mối liên kết giữa node cha của node x với node con (con trái hoặc con phải) của node x
  - 3. Node 2 con:
 */
// hàm xoá node bất kì
void removeNode(Node *&root, const int &data)
{
    // nếu cây đang rỗng
    if (root == NULL)
        return; // kết thúc hàm luôn
    else
    {
        if (data < root->data)
            removeNode(root->left, data); // duyệt sang nhánh trái của cây
        else if (data > root->data)
            removeNode(root->right, data); // duyệt sang nhánh phải của cây
        else                               // data == root->data - đã tìm ra cái node cần xoá
        {
            Node *temp = root; // node t là node thế mạng - tí nữa ta xoá nó
                               // xoá được cho cả node lá
                               // nếu nhánh trái NULL <=> đây là node có 1 con chính là con phải
            if (root->left == NULL)
            {
                root = root->right; // duyệt sang phải của cái node cần xoá
                // để update mlk giữa node cha của node cần xoá với node con của node cần xoá
            }
            // nếu nhánh phải NULL <=> đây là node có 1 con chính là con trái
            else if (root->right == NULL)
            {
                root = root->left; // duyệt sang trái của cái node cần xoá
                // để update mlk giữa node cha của node cần xoá với node con của node cần xoá
            }
            delete temp; // xoá node cần xoá
        }
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
        cout << "2. In cay (NLR)" << endl;
        cout << "3. Xoa node bat ki" << endl;
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
            output(root);
            system("pause");
            break;
        }
        case 3:
        {
            cout << "\n\t\tXoa node bat ki" << endl;
            int value;
            cout << "\nNhap gia tri can xoa: ";
            cin >> value;
            removeNode(root, value);
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