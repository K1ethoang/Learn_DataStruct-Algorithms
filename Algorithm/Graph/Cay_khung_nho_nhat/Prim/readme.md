# Thuật Toán Prim

# Mã giả

```cpp
// n - số đỉnh
// E - tập cạnh

// Bước 1: Khởi tạo
V(mst) = {u};
V = V \ {u};
mst = {};
d = 0;

// Bước 2: Lặp
while(V != {})
{
    e = (x, y); // Cạnh ngắn nhất x thuộc V, y thuộc mst
    mst = mst U (e);
    d += d(e);
    V(mst) = V(mst) U {x};
    V = V \ {x};
}
```
