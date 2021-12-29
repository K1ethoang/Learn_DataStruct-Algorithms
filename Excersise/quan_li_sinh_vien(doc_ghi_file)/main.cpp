#include <iostream>
#include <string>
#include <fstream>
using namespace std;

// khai bao cau truc sinh vien

struct Date
{
    int day, month, year;
};

struct Student
{
    string fullname;
    string code;
    Date dayOfBirth;
    float mediumScore;
};

// khai bao cau truc node
struct Node
{
    Student data;
    Node *pNext;
};

struct List
{
    Node *pHead;
    Node *pTail;
};

void createList(List &l);
Node *createNode(Student s);
void addNodeInTail(List &l, Node *p);

void readOneStudent(ifstream &fileIn, Student &s); // đọc 1 sinh viên từ file
void readDate(ifstream &fileIn, Date &date);
void importStudens(ifstream &fileIn, List &l);
void outputOneStudent(Student s);
void outputStudents(List l);

void freeMemory(List &l);

void inputOneStudent(Student &s);

int main(int argc, char *argv[])
{
    List l;
    createList(l);
    // mở file lên
    ifstream fileIn;
    fileIn.open("./sinhVien.txt", ios_base::in);
    importStudens(fileIn, l);
    cout << "\nDoc file thanh cong";

    outputStudents(l);
    system("pause");

    freeMemory(l);
    fileIn.close();
    return 0;
}

void createList(List &l)
{
    l.pHead = NULL;
    l.pTail = NULL;
}

Node *createNode(Student s)
{
    Node *p = new Node;
    if (p == NULL)
    {
        cout << "\nKhong du bo nho de cap phat";
        return NULL;
    }
    else
    {
        p->data = s;
        p->pNext = NULL;
    }
    return p;
}

void addNodeInTail(List &l, Node *p)
{
    if (l.pHead == NULL) // danh sách đang rỗng
        l.pHead = l.pTail = p;
    else
    {
        l.pTail->pNext = p; // node cuối trỏ tới node vừa thêm
        l.pTail = p;        // cập nhật lại pTail
    }
}

void readDate(ifstream &fileIn, Date &date)
{
    fileIn >> date.day;
    fileIn.seekg(1, ios::cur);
    fileIn >> date.month;
    fileIn.seekg(1, ios::cur);
    fileIn >> date.year;
}

void readOneStudent(ifstream &fileIn, Student &s)
{
    getline(fileIn, s.fullname, ','); // đọc đến dấu phẩy thì dừng
    // fileIn.seekg(1, ios::cur);
    getline(fileIn, s.code, ',');
    // fileIn.seekg(1, ios::cur);
    // readDate(fileIn, s.dayOfBirth);
    // fileIn.seekg(1, ios::cur);
    fileIn >> s.mediumScore;
}

void importStudens(ifstream &fileIn, List &l)
{
    while (!fileIn.eof()) // đọc đến cuối file thì dừng
    {
        Student student;
        readOneStudent(fileIn, student);
        string temp;
        getline(fileIn, temp); // lấy kí tự '\n'
        Node *p = createNode(student);
        addNodeInTail(l, p);
    }
}

void outputOneStudent(Student s)
{
    cout << "\nHo va ten: " << s.fullname << endl;
    cout << "Ma sinh vien: " << s.code << endl;
    cout << "Ngay Sinh: " << s.dayOfBirth.day << "/" << s.dayOfBirth.month << "/" << s.dayOfBirth.year << endl;
    cout << "Diem trung binh: " << s.mediumScore;
}

void outputStudents(List l)
{
    int count = 1;
    for (Node *t = l.pHead; t != NULL; t = t->pNext)
    {
        cout << "\n\n\t\tSINH VIEN [" << count++ << "]\n";
        outputOneStudent(t->data);
    }
}

void freeMemory(List &l)
{
    Node *temp = NULL;
    while (l.pHead != NULL)
    {
        temp = l.pHead;
        l.pHead = l.pHead->pNext;
        delete temp;
    }
}

// void inputOneStudent(Student &s)
// {
//     fflush(stdin);
//     cout << "\nNhap ho va ten: ";
//     getline(cin, s.fullname);
//     cout << "\nNhap ma sinh vien: ";
//     getline(cin, s.code);
//     cout << "\nNhap ngay thang nam: ";
//     cin >> s.dayOfBirth.day >> s.dayOfBirth.month >> s.dayOfBirth.year;
//     cout << "\nNhap diem: ";
//     cin >> s.mediumScore;
// }
