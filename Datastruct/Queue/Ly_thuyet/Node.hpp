#pragma once

#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *pNext;

    Node();
    Node(int _data);
};

Node::Node()
{
}

Node::Node(int _data)
    : data(_data), pNext(NULL) {}