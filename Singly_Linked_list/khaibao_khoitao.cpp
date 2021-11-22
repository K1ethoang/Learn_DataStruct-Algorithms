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
typedef struct node NODE; // thay thế struct node = NODE

// * Khai báo cấu trúc của danh sách liên kết đơn
struct list
{
    NODE *pHead; // node quản lí đầu danh sách
    NODE *pTail; // node quản lí cuói danh sách
};
typedef struct list LIST;

// ? ================ KHỞI TẠO DANH SÁCH LIÊN KẾT ĐƠN CÁC SỐ NGUYÊN =============
void khoiTao(LIST &l)
{
    // cho 2 cái node trỏ đến NULL - vì danh sách liên kết đơn chưa có phần tử
    l.pHead = NULL;
    l.pTail = NULL;
}

int main()
{
    NODE x;
    system("pause");
    return 0;
}