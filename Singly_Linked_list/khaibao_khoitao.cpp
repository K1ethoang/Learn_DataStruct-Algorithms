#include <iostream>
using namespace std;

// ! Bài toán: Nhập danh sách liên kết đơn các số nguyên. Tìm giá trị lớn nhát trong danh sách

// ? ================ KHAI BÁO DANH SÁCH LIÊN KẾT ĐƠN CÁC SỐ NGUYÊN =============

// * Khai báo
struct node
{
    int data;           // dữ liệu chứa trong 1 cái node
    struct node *pNext; // con trỏ dùng để liên kết giữa các cái node với nhau
};

// * Khai báo cấu trúc của danh sách liên kết đơn
struct list
{
    node *pHead; // node quản lí đầu danh sách
    node *pTail; // node quản lí cuói danh sách
};

// ? ================ KHỞI TẠO DANH SÁCH LIÊN KẾT ĐƠN CÁC SỐ NGUYÊN =============
void khoiTao(list &l)
{
    // cho 2 cái node trỏ đến NULL - vì danh sách liên kết đơn chưa có phần tử
    l.pHead = NULL;
    l.pTail = NULL;
}

// Hàm khởi tạo 1 cái node
node *khoiTaoNode(int x)
{
    node *temp = new node; // CẤP PHÁT VÙNG NHỚ CHO node temp
    if (temp == NULL)      // phòng hờ ram hết bộ nhớ
    {
        cout << "\nKhong du bo nho de cap phat :v";
        return NULL;
        dfadf
    }
    else
    {
        temp->data = x;     // truyền giá trị x vào cho cái data
        temp->pNext = NULL; // đầu tiên khai báo thì node đó chưa có liên kết đến node nào hết -> con trỏ của nó sẽ trỏ đến null
        return temp;        // trả về node temp vừa khởi tạo
    }
}

// * hàm thêm node p vào đầu danh sách liên kết
void themVaoDau(list &l, node *p)
{
    if (l.pHead == NULL) // Danh sách đang rỗng
    {
        l.pHead = l.pTail = p; // node đầu cũng chính là node cuối và là p
    }
    else
    {
        p->pNext = l.pHead; // cho con trỏ của node cần thêm liên kết đến node đầu - pHead
        l.pHead = p;        // cập nhật lại pHead chính là node p
    }
}

// * hàm thêm node p vào cuối danh sách liên kết đơn
void themVaoCuoi(list &l, node *p)
{
    if (l.pHead == NULL)       // Danh sách đang rỗng
        l.pHead = l.pTail = p; // node đầu cũng chính là node cuối và là p
    else
    {
        l.pTail->pNext = p; // cho con trỏ pTail liên kết đến node p
        l.pTail = p;        // cập nhật lại p là node pTail
    }
}

int main()
{
    list l;
    khoiTao(l); // khởi tạo danh sách liên két đơn

    int n;
    cout << "\nNhap so luong node can them: ";
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        int x; // data
        cout << "\nNhap gia tri so nguyen: ";
        cin >> x;
        node *p = khoiTaoNode(x); // khởi tạo 1 cái node số nguyên
        themVaoDau(l, p);         // thêm node p vào đầu danh sách liên kết đơn
    }

    system("pause");
    return 0;
}