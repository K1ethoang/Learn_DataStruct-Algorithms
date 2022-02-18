#pragma once
#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *pLeft;  // node liên kết bên trái của cây <=> cây con trái
    Node *pRight; // node liến kết bên phải của cây <=> cây con phải
    Node();
    Node(int value);
};

Node::Node()
{
}

Node::Node(int value)
    : data(value), pLeft(NULL), pRight(NULL) {}