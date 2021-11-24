#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    Node *next;
};
typedef struct Node Node;

struct list
{
    Node *pHead;
    Node *pTail;
};

Node createNode(int x)
{
    Node p = (Node)malloc(sizeof(Node));
    p.x = x;
    p.next = NULL;
    return p;
}

int main()
{

    Node a = createNode(3);
    printf("%d", a.x);
    printf("\n%x", a.next);

    return 0;
}