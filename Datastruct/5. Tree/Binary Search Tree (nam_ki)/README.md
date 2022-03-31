# Binary Search Tree (BST)
- Mỗi node luôn luôn có 0 - 2 nhánh con
- 
# Tài liệu để học
- [Youtube](https://www.youtube.com/playlist?list=PLimFJKGsbn1n6UkQnTjXhziglRzmJ2mlR)

# Xoá node
- Node x là node cần xoá
- Nếu x:
  - 1. Node lá: xoá bình thường - lúc này node x là node tự do (không có con trái và con phải)
  - 2. Node 1 con: trước khi xoá node x - chúng ta phải cập nhật mối liên kết giữa node cha của node x với node con (con trái hoặc con phải) của node x
  - 3. Node 2 con: trước khi huỷ thì ta cần tìm 1 node thế mạng cho node cần xoá 
    -  Tìm node thế mạng phải đảm bảo quy tắc cây nhị phân tìm kiếm
    -  Tìm node trái nhất của cây con phải (cây con phải của node cần xoá)
    -  Tìm node phải nhất của cây con trái (cây con trái của node cần xoá)