#include "Node.hpp"

class Stack
{
private:
    Node *pTop; // dùng con trỏ đầu để quản lí stack
    int size;

public:
    Stack();
    ~Stack();
    bool isEmpty();
    void push(const int &_data);
    int pop();
    int top();
    int sizeOf();
    void dislay();
};

Stack::Stack()
    : pTop(NULL), size(0) {}

// method giải phóng Stack
Stack::~Stack()
{
    Node *temp = NULL;
    while (pTop != NULL)
    {
        temp = pTop;
        pTop = pTop->pNext;
        delete temp;
    }
}

bool Stack::isEmpty()
{
    if (pTop == NULL)
        return true;
    return false; // danh sách có phần tử
}

void Stack::push(const int &_data)
{
    Node *temp = new Node(_data);
    if (pTop == NULL) // danh sách rỗng
    {
        pTop = temp;
    }
    else // danh sách đã có phần tử
    {
        // phần tử mới thêm vào sẽ liên kết với phần tử dưới nó
        temp->pNext = pTop;
        // cập nhật lại phần tử top
        pTop = temp;
    }
    size++;
}

int Stack::pop()
{
    // trả về giá trị của phần tử đầu và huỷ nó
    if (isEmpty())
    {
        cout << "\nStack rong";
    }
    else
    {
        size--;
        int x = pTop->data;
        // xoá phần tử đầu
        Node *t = pTop;
        // cập nhật lại phần tử đầu là thằng dưới nó
        pTop = t->pNext;
        delete t;
        return x;
    }
}

int Stack::top()
{
    return pTop->data;
}

int Stack::sizeOf()
{
    return this->size;
}

void Stack::dislay()
{
    if (isEmpty())
    {
        return;
    }
    else
    {
        for (Node *t = pTop; t != NULL; t = t->pNext)
        {
            cout << t->data << " ";
        }
    }
}