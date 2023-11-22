# 1. DFS (Depth First Search)

- Thuật toán tìm kiếm theo chiều sâu: Ưu tiên duyệt xuống nhất có thể trước khi quay lại

# 2. Mã giả:

```cpp
// Bat dau duyet tu dinh u
DFS(u){
	<Tham Dinh u>;
	visited[u] = true; // Danh dau la u da duoc tham
	// Duyet cac dinh ke voi dinh u
	for(v : adj[u]){
		if(!visited[u]){ // Neu v chua duoc tham
			DFS(v);
		}
	}
}
```

# 3. Độ phức tạp

- Độ phức tạp của thuật toán DFS phụ thuộc vào cách biểu diễn ma trận:
  - Đồ thị G = <V, E>
  - Biểu diễn bằng ma trận kề : O(V \* V)
  - Biểu diễn bằng danh sách cạnh: O(V \* E)
  - Biểu diễn bằng danh sách kề: O(V + E)

## [Code](./program.cpp)
