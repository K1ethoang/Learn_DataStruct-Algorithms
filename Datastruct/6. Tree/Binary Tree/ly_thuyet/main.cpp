#include <iostream>
#include "Node.hpp"
using namespace std;

int main()
{
    Node *n = new Node();

    delete n;
    return 0;
}