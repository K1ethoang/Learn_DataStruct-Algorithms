#include <iostream>
#include <string>
using namespace std;

struct item
{
    string name;
    string drink;
    item *pNext;

    item() // constructor
    {
        name = "empty";
        drink = "empty";
        pNext = NULL;
    }

    item(string _name, string _drink) // hàm khởi tạo có tham số
        : name(_name), drink(_drink), pNext(NULL)
    {
    }
};

class HashTable
{
private:
    static const int tableSize = 10;

    item *table[tableSize]; // một mảng chứ các phần tử con trỏ có kiểu dữ liệu là item

public:
    HashTable(); // constructor
    int hashFunction(string key);
    void insert(string name, string drink);
    int numberOfItemsInIndex(int index);
    void printTable();
    void printItemsInIndex(int index);
    void findDrink(string name);
    void remove(string name);
};

int main()
{
    HashTable hashTable;
    hashTable.insert("Kim", "Iced Mocha");
    hashTable.insert("Emma", "Strawberry Smoothie");
    hashTable.insert("Annie", "Hot Chocolate");
    hashTable.insert("Sarah", "Passion Tea");
    hashTable.insert("Pepper", "Caramel Mocha");
    hashTable.insert("Mike", "Chai Tea");
    hashTable.insert("Steve", "Apple Cider");
    hashTable.insert("Bill", "Root Beer");
    hashTable.insert("Marie", "Skinny Latte");
    hashTable.insert("Susan", "Water");
    hashTable.insert("Joe", "Green Tea");

    // hashTable.printItemsInIndex(9);
    hashTable.printTable();
    string name;
    // while (name != "exit")
    // {
    //     cout << "Search for ";
    //     cin >> name;
    //     if (name != "exit")
    //         hashTable.findDrink(name);
    // }
    while (name != "exit")
    {
        cout << "Remove ";
        cin >> name;
        if (name != "exit")
            hashTable.remove(name);
    }
    return 0;
}

HashTable::HashTable()
{
    for (int i = 0; i < tableSize; i++)
    {
        table[i] = new item(); // tạo ra ô nhớ cho mảng băm
    }
}

int HashTable::hashFunction(string key)
{
    int hash = 0;
    for (int i = 0; i < key.length(); i++)
    {
        hash += (int)key[i];
    }
    return hash % tableSize;
}

void HashTable::insert(string name, string drink)
{
    int index = hashFunction(name);
    // nếu lúc đầu chưa có phần tử nào thì thêm
    if (table[index]->name == "empty")
    {
        table[index]->name = name;
        table[index]->drink = drink;
    }
    // nếu có rồi thì thêm vào đầu giống dslk
    else
    {
        // áp dụng tư tưởng thêm vào đầu dslk
        item *temp = new item(name, drink); // tạo ra 1 ô nhớ cho ptu cần thêm
        temp->pNext = table[index];         // cập nhật mlk của ptu cần thêm là ptu nằm đầu
        table[index] = temp;                // cập nhật lại ptu đầu là ptu vừa thêm
    }
}

int HashTable::numberOfItemsInIndex(int index)
{
    int count = 0;
    if (table[index]->name == "empty")
        return count;
    else
    {
        for (item *ptr = table[index]; ptr != NULL; ptr = ptr->pNext)
            count++;
    }
    return count;
}

void HashTable::printTable()
{
    int number;
    for (int i = 0; i < tableSize; i++)
    {
        printItemsInIndex(i);
    }
}

void HashTable::printItemsInIndex(int index)
{
    item *ptr = table[index];
    if (ptr->name == "empty")
    {
        cout << "\t-------------------------\n";
        cout << "\tIndex = " << index << " is empty\n";
        cout << "\t-------------------------\n";
    }
    else
    {
        cout << "\t-------------------------\n";
        cout << "\tIndex = " << index << " contains the following item\n";
        cout << "\t-------------------------\n";
        for (item *t = ptr; t != NULL; t = t->pNext)
        {
            cout << t->name << endl;
            cout << t->drink << endl;
            cout << "-------------------------\n";
        }
    }
}

void HashTable::findDrink(string name)
{
    int index = hashFunction(name);
    bool foundName = false;
    string drink;
    // duyệt qua từng phần tử trong cái index đó
    for (item *ptr = table[index]; ptr != NULL; ptr = ptr->pNext)
    {
        if (ptr->name == name)
        {
            foundName = true;
            drink = ptr->drink;
            break;
        }
    }
    if (foundName)
        cout << "Favorite drink = " << drink << endl;
    else
        cout << name << "'s info was not found in the hashTable" << endl;
}

void HashTable::remove(string name)
{
    int index = hashFunction(name);
    item *delPtr, *ptr1, *ptr2;
    // bucket không có phần tử nào
    if (table[index]->name == "empty" && table[index]->drink == "empty")
        cout << name << " was not found in the Hash Table" << endl;
    // chỉ có 1 phần tử trong bucket và đúng với phần tử cần xoá
    else if (table[index]->name == name && table[index]->pNext == NULL)
    {
        table[index]->name = "empty";
        table[index]->drink = "empty";
        cout << name << " was removed from the Hash Table" << endl;
    }
    // phần tử cần xoá nằm ở đầu
    else if (table[index]->name == name)
    {
        delPtr = table[index];
        table[index] = table[index]->pNext;
        delete delPtr;
        cout << name << " was removed from the Hash Table" << endl;
    }
    // bucket chứa nhiều item nhưng phần tử đầu ko phải phần tử cần xoá
    else
    {
        ptr1 = table[index];
        ptr2 = table[index]->pNext;
        while (ptr2 != NULL && ptr2->name != name)
        {
            ptr1 = ptr2;
            ptr2 = ptr2->pNext;
        }
        // nếu không có phần tử cần xoá
        if (ptr2 == NULL)
            cout << name << " was not found in the Hash Table" << endl;
        // nếu có phần tử cần xoá
        else
        {
            delPtr = ptr2;
            ptr2 = ptr2->pNext;
            ptr1->pNext = ptr2; // cập nhật lại mlk giữa ptu trước ptu xoá với ptu sau ptu xoá
            delete delPtr;
            cout << name << " was removed from the Hash Table" << endl;
        }
    }
}