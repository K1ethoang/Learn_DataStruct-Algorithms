# Disjoint Set Union (DSU)

- 3 thao tác chính:
  - make_set(a): tạo ra một tập hợp mới chỉ chứa phần tử a
  - union(a, b): gộp tập hợp chứa phần tử a và tập hợp chứa phần tử b thành một
  - find(v): cho biết đại diện của tập hợp có chứa phần tử v. Đại diện này sẽ là một phần tử của tập hợp đó và có thể thay đổi sau mỗi lần gọi thao tác union_sets. Ta có thể sử dụng đại diện đó để kiểm tra hai phần tử có nằm trong cùng một tập hợp hay không. a và b nằm trong cùng một tập hợp nếu như đại diện của hai tập chứa chúng là giống nhau và không nằm trong cùng một tập hợp nếu ngược lại
