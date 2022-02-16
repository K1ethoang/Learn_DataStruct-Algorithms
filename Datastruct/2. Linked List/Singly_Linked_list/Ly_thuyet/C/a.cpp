#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *Next;
};
typedef struct Node Node;

struct List
{
    Node *Head;
    Node *Tail;
};
typedef struct List List;

void createList(List &l)
{
    l.Head = NULL;
    l.Tail = NULL;
}

Node *createNode(int x)
{
    Node *New = (Node *)malloc(sizeof(Node));

    if (New == NULL)
    {
        printf("\nAllocation error!");
        return NULL;
    }
    else
    {
        New->data = x;
        New->Next = NULL;
    }
    return New;
}

void addTopList(List &l, Node *p)
{
    if (l.Head == NULL)
    {
        l.Head = l.Tail = p;
    }
    else
    {
        p->Next = l.Head;
        l.Head = p;
    }
}

void addEndList(List &l, Node *p)
{
    if (l.Head == NULL)
    {
        l.Head = l.Tail = p;
    }
    else
    {
        l.Tail->Next = p;
        l.Tail = p;
    }
}

void outputList(List l, int n)
{
    for (Node *t = l.Head; t != NULL; t = t->Next)
    {
        printf("%5d", t->data);
    }
}

int maxElement(List l, int n)
{
    int max = l.Head->data;
    for (Node *t = l.Head; t != NULL; t = t->Next)
    {
        if (max < t->data)
            max = t->data;
    }
    return max;
}
int main()
{
    List listNode;
    createList(listNode);

    int n;

    printf("Enter numbers of Node you need: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        int x;
        printf("\nEnter value of Node [%d]: ", i + 1);
        scanf("%d", &x);
        Node *p = createNode(x);
        addTopList(listNode, p);
    }

    printf("\n\n\tImported list\n");
    outputList(listNode, n);

    printf("\n\n\tMax element in list\n");
    printf("%d", maxElement(listNode, n));

    printf("\nFinished Program");
    return 0;
}