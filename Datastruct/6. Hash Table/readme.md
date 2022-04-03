# 1. Hash Table
- Bảng băm là một CTDL thường được sử dụng như một từ điển: mỗi phần tử trong bảng băm là một cặp (Key, Value). Nếu so sánh với mảng, khóa được xem như chỉ số của mảng, còn giá trị giống như giá trị mà ta lưu tại chỉ số tương ứng. Bảng băm không như các loại từ điển thông thường - ta có thể tìm được giá trị thông qua khóa của nó.
- Không may, không phải tất cả các kiểu dữ liệu đều có thể sắp xếp vào một từ điển đơn giản. Đây chính là lúc mà quá trình băm (hash) ra đời. Hash là quá trình khởi tạo một giá trị khóa (thường là 32 bit hoặc 64 bit) từ một phần dữ liệu. Nó có thể là n bit đầu tiên của dữ liệu, n bit cuối cùng, giá trị mod cho một số nguyên tố nào đó. Dựa theo giá trị hash, dữ liệu được chia vào các **bucket**:
- [Code build lại **Hash table**]()

|Image|
|---|
|![hash table](./image/hash-table.png)|

# 2. Complexity
- Gọi:
	- n là số phần tử ta cần lưu trong Hash table
	- k là số bucket
- Giá trị n/k được gọi là **load factor**. Khi **load factor** nhỏ (xấp xỉ 1), và giá trị của hàm Hash phân bố đều, độ phức tạp của các thao tác trên Hash table là O(1).

# 3. Collision handing (xử lý va chạm)
- Trường hợp một hash bucket chứa nhiều hơn một giá trị ta gọi đó là Hash collision (va chạm). Việc xử lý hash collision rất quan trọng đối với độ hiệu quả của bảng băm
## 3.1. Separate chaining
- Cài đặt các **danh sách liên kết** ở các bucket. Ví dụ:

|Image|
|---|
|![seperate chaining](./image/seperate-chaining.png)|

- ***Giải thích hình minh hoạ***:
 	- Mỗi bucket là 1 **danh sách liên kết**
	- John Smith và Sandra Dee cùng có giá trị hàm hash là 152, nên ở bucket 152, ta có 1 danh sách liên kết chứa 2 phần tử.
## 3.2. Open Addressing
- Khi xảy ra Hash collision, ta lưu vào một vị trí tiếp theo trong bảng băm. Ví dụ:

|Image|
|---|
|![Open Addressing](./image/open-addressing.png)|
- ***Giải thích hình minh hoạ***:
    - John Smith và Sandra Dee đều có giá trị Hash là 152. Vì ta đã lưu John Smith vào bucket 152, nên ta buộc phải lưu Sandra Dee vào bucket 153.
    - Ted Baker có giá trị Hash là 153, nhưng lúc này bucket 153 đã lưu thông tin của Sandra Dee, nên ta phải lưu giá trị của Ted Baker vào bucket 154.
- **Chú ý**:
	- Để cài đặt được cách này, Load factor phải nhỏ hơn 1.
	- Khi tìm kiếm 1 phần tử, ta phải kiểm tra tất cả các bucket bắt đầu từ bucket của giá trị Hash, đến khi bucket trống (ví dụ ta tìm Sandra Dee thì phải tìm bucket 152, 153; tìm Ted Baker thì phải tìm bucket 152, 153, 154. Nếu ta tìm 1 người khác có giá trị Hash là 152, thì phải tìm cả bucket 152, 153, 154 và 155 (chỉ khi bucket 155 trống, ta mới chắc chắn người đó không có trong Hash table).

[Click here to go top page](#1-hash-table)