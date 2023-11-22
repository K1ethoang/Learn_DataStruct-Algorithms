# Thuật Toán Kruskal

# Mã giả

```cpp
// n - số đỉnh
// E - tập cạnh
// Bước 1: Khởi tạo
MST = {};
d(MST) = 0;

// Bước 2: Sắp xếp
<Sort các cạnh thuộc độ dài>

// Bước 3: Lặp
while(|MST| < n && E != {})
{
    e = <Cạnh ngắn nhất thuộc E>;
    E = E \ {e};
    if(MST U (e) không tạo chu trình){
        MST = MST U e
        d(MST) += d(e)
    }
}
```
