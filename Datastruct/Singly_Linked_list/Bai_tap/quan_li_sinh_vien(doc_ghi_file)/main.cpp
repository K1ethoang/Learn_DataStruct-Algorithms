#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <cstring>
using namespace std;

// khai bao cau truc sinh vien
struct Student
{
    string fullname;
    string code;
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
void importStudens(ifstream &fileIn, List &l);
void outputOneStudent(Student s);
void outputStudents(List l);
void swapTwoStudent(Student &s1, Student &s2);
void sortAscendingByMediumScore(List &l);
void writeOneStudent(ofstream &fileout, Student s);
void saveFileAscendingByMediumScore(List l);
void saveFileTopStudentsWithHigestMediumScore(List l);
void findStudentByCode(List l);
string splitName(const string &s);
void findStudentByName(List l);

void freeMemory(List &l);

int main(int argc, char *argv[])
{
    List l;
    createList(l);
    // mở file lên
    ifstream fileIn;
    fileIn.open("./file/sinhVien.txt", ios_base::in);
    importStudens(fileIn, l);
    outputStudents(l);
    findStudentByName(l);
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

void readOneStudent(ifstream &fileIn, Student &s)
{
    getline(fileIn, s.fullname);
    getline(fileIn, s.code);
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

// 2. Sắp xếp danh sách sinh viên tăng dần theo điểm trung bình
// và ghi vào file SAPXEPDIEMMAX.TXT
void swapTwoStudent(Student &s1, Student &s2)
{
    Student temp = s1;
    s1 = s2;
    s2 = temp;
}

void sortAscendingByMediumScore(List &l)
{
    // selection sort
    for (Node *t = l.pHead; t->pNext != NULL; t = t->pNext)
    {
        Node *min = t;
        for (Node *k = t->pNext; k != NULL; k = k->pNext)
        {
            if (min->data.mediumScore > k->data.mediumScore)
                min = k;
        }
        if (min != t)
            swapTwoStudent(t->data, min->data); // hoán vị 2 data của 2 cái node
    }
}

// lưu thông tin 1 sinh viên
void writeOneStudent(ofstream &fileout, Student s)
{
    fileout << s.fullname << endl;
    fileout << s.code << endl;
    fileout << s.mediumScore << endl;
}

void saveFileAscendingByMediumScore(List l)
{
    ofstream fileout;
    fileout.open("./file/sapXepDiemMax.txt", ios::out);
    // gọi lại sort để sort danh sách sinh viên tăng dần theo điểm
    sortAscendingByMediumScore(l);
    // lưu tất cả thông tin sinh viên vào file
    for (Node *t = l.pHead; t != NULL; t = t->pNext)
    {
        writeOneStudent(fileout, t->data);
    }

    fileout.close();
}
// 3. In danh sách sinh viên có điểm trung bình cao nhất
// vào file DIEMTRUNGBINHMAX.TXT

void saveFileTopStudentsWithHigestMediumScore(List l)
{
    // sort để tìm điểm cao nhất
    sortAscendingByMediumScore(l);
    // số điểm cao nhất trong danh sách
    float maxScore = l.pTail->data.mediumScore;

    ofstream fileout;
    fileout.open("./file/diemTrungBinhMax.txt", ios::out);
    // tìm những sinh viên có số điểm = maxScore;
    for (Node *cur = l.pHead; cur != NULL; cur = cur->pNext)
    {
        if (cur->data.mediumScore == maxScore)
        {
            writeOneStudent(fileout, cur->data);
        }
    }
    fileout.close();
}

// 4. Tìm kiếm thông tin sinh viên dựa vào mã số sinh viên
void findStudentByCode(List l)
{
    string code;
    cout << "\n\nNhap ma so sinh vien can tim: ";
    cin >> code;
    for (Node *cur = l.pHead; cur != NULL; cur = cur->pNext)
    {
        if (code == cur->data.code)
        {
            outputOneStudent(cur->data);
            cout << endl;
        }
    }
}

// 5. Tìm kiếm thông tin sinh viên dựa vào tên sinh viên
string splitName(const string &s)
{
    string ss;
    int length = 0;
    for (int i = s.length() - 1; i >= 0; i--)
    {
        length++;
        if (s[i] == ' ')
        {
            ss = s.substr(i + 1, length - 1);
            break;
        }
    }
    return ss;
}

void findStudentByName(List l)
{
    string name; // tên cần tìm
    cout << "\n\nNhap ten sinh vien can tim: ";
    cin >> name;
    for (Node *cur = l.pHead; cur != NULL; cur = cur->pNext)
    {
        string s = splitName(cur->data.fullname); // tên được tách ra
        // c_str(): chuyển string -> char*
        if (stricmp(s.c_str(), name.c_str()) == 0) // hàm so sánh không phân biệt hoa - thường
        {
            outputOneStudent(cur->data);
            cout << endl;
        }
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
