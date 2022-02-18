#include "Node.hpp"

class BT
{
private:
    Node *root;
    int size;

public:
    BT(); // constructor
    void add(Node *root, const int &value);

    void free(Node *root);
};

BT::BT()
    : root(NULL), size(0) {}

void BT::add(Node *root, const int &value)
{
    Node *p = new Node(value);
    // cây rỗng
    if (root == NULL)
        root = p;
    else // cây có tồn tại phần tử
    {
        // nhỏ hơn thì qua trái
        if (p->data < root->data) // duyệt qua trái để thêm phần tử
            add(root->pLeft, value);
        // nhỏ hơn thì qua phải
        else if (p->data > root->data) // duyệt qua phải để thêm phần tử
            add(root->pRight, value);
    }
}