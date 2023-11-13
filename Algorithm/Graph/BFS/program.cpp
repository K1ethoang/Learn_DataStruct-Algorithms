#include <bits/stdc++.h>
using namespace std;

// input
int n, m;
// n: Số đỉnh
// m: Số cạnh
vector<vector<int>> grh(1001);
vector<bool> visited(1001, 0);

// Nhập danh sách kề
void input()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        grh[x].push_back(y);
        grh[y].push_back(x);
    }
}

void bfs(int u)
{
    queue<int> q;      // Tạo một hàng đợi rỗng
    q.push(u);         // Đẩy đỉnh u vào hàng đợi
    visited[u] = true; // Đánh dấu là đỉnh u đã được thăm

    while (!q.empty())
    {
        int v = q.front(); // Lấy ra đỉnh ở đầu hàng đợi
        q.pop();           // Xoá đỉnh ở đầu hàng đợi
        cout << v << " ";
        // Duyệt các đỉnh kề với đỉnh v mà chưa được thăm và đẩy vào hàng đợi
        for (int x : grh[v])
        {
            if (!visited[x]) // Nếu x chưa được thăm
            {
                q.push(x);
                visited[x] = true;
            }
        }
    }
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    input();
    bfs(1);
    return 0;
}