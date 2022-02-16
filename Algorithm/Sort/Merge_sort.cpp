#include <iostream>
using namespace std;

void insert(int *a, int n);
void display(int *a, int n);

void merge(int *a, int l, int mid, int r)
{
	/*
	   i: vị trí hiện tại trên dãy con trái
	   j: vị trí hiện tại trên dãy con phải
	   cur: vị trí hiện tại trên dãy tạm
   */
	int i = l, j = mid + 1, cur = l;
	// mảng phụ
	int *temp = new int[r - l + 1];
	// Trộn
	while (i <= mid && j <= r)
	{
		if (a[i] < a[j])
		{
			// lấy phần tử bên dãy con trái
			temp[cur] = a[i];
			i++;
		}
		else // a[i] >> a[j]
		{
			// lấy phần tử bên dãy con phải
			temp[cur] = a[j];
			j++;
		}
		cur++;
	}
	// khi 1 trong 2 dãy hết phần tử
	// hoàn tất dãy con trái
	for (; i <= mid; i++)
		temp[cur++] = a[i];
	// hoàn tất dãy con phải
	for (; j <= r; j++)
		temp[cur++] = a[j];
	// copy mảng phụ vào mảng chính
	for (cur = l; cur <= r; cur++)
		a[cur] = temp[cur];
	// giải phóng vùng nhớ mảng tạm
	delete temp;
}

void merge_sort(int *a, int l, int r)
{
	if (l < r)
	{
		int mid = (l + r) / 2;	   // chia thành 2 dãy
		merge_sort(a, l, mid);	   // trộn 1/2 dãy bên trái
		merge_sort(a, mid + 1, r); // trộn 1/2 dãy bên phải
		merge(a, l, mid, r);	   // trộn 2 dãy lại với nhau
	}
}

int main()
{
	int n;
	cout << "\nNhap n: ";
	cin >> n;
	int *a = new int[n];
	cout << "\n\t\tNhap mang\n";
	insert(a, n);
	cout << "\n\t\tMang vua nhap\n";
	display(a, n);
	cout << "\n\t\tMang sau khi sort\n";
	merge_sort(a, 0, n - 1);
	display(a, n);

	delete[] a;
	return 0;
}

void insert(int *a, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "\nNhap a[" << i << "]: ";
		cin >> a[i];
	}
}

void display(int *a, int n)
{
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		count++;
		cout << a[i] << " ";
		if (count == 10)
		{
			cout << endl;
			count = 0;
		}
	}
}