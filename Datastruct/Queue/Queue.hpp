#include "Node.hpp"

class Queue
{
private:
    Node *pFront;
    Node *pBack;
    int size;

public:
    Queue();
    ~Queue();
    bool isEmpty();
    void push(const int &x);
    int front();
    int back();
    void pop();
    int sizeOf();
    void display();
};

Queue::Queue()
    : pFront(NULL), pBack(NULL), size(0) {}

Queue::~Queue()
{
    if (isEmpty())
    {
        return;
    }
    else
    {
        Node *t = NULL;
        while (pFront != NULL)
        {
            t = pFront;
            pFront = pFront->pNext;
            delete t;
        }
    }
}

bool Queue::isEmpty()
{
    if (pFront == NULL)
    {
        return true;
    }
    return false; // danh sách có phần tử
}

// thêm vào cuối
void Queue::push(const int &x)
{
    Node *t = new Node(x);
    if (pFront == NULL)
    {
        pFront = pBack = t;
    }
    else
    {
        pBack->pNext = t;
        pBack = t;
    }
    size++;
}

int Queue::front()
{
    return pFront->data;
}

int Queue::back()
{
    return pBack->data;
}

void Queue::pop()
{
    if (isEmpty())
    {
        return;
    }
    else
    {
        size--;
        Node *t = pFront;       // con trỏ đầu
        pFront = pFront->pNext; // cập nhật lại phần tử đầu
        // xoá phần tử đầu
        delete t;
    }
}

int Queue::sizeOf()
{
    return this->size;
}

void Queue::display()
{
    for (Node *t = pFront; t != NULL; t = t->pNext)
    {
        cout << t->data << " ";
    }
}