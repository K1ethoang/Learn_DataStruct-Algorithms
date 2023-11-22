# 1. BFS (Breadth First Search)

- Tư tưởng của thuật toán BFS là tìm kiếm ưu tiên chiều rộng hơn là chiều sâu. Thuật toán sẽ tìm kiếm xung quanh để mở rộng trước khi đi xuống sâu hơn

# 2. Mã giả:

```cpp
BFS(u){
	// Step 1: Khởi tạo
	queue = {}; // Tạo một hàng đợi rỗng
	push(queue, u); // Đẩy đỉnh u vào hàng đợi
	visited[u] = true; // Đánh dấu đỉnh u đã được thăm
	// Step 2: Lặp khi mà hàng đợi vẫn còn phần tử
	while(queue != {}){
		v = queue.front(); // Lấy ra đỉnh ở đầu hàng đợi
		queue.pop(); // Xoá đỉnh ở đầu hàng đợi
		<Thăm đỉnh v>;
		// Duyệt các đỉnh kề với v mà chưa được thăm và đẩy vào hàng đợi
		for(int x : ke[v]){
			if(!vistited[x]){ // Nếu x chưa được thăm
				push(queue, x);
				visited[x] = true;
			}
		}
	}
}
```

## [Code](./program.cpp)
