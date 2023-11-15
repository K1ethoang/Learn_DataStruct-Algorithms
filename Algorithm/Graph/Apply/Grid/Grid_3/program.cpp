#include <bits/stdc++.h>
using namespace std;

// Bài 3: Tìm số bước đi tối thiểu giữa 2 ô trên lưới
// o : có đường đi
// x : ko có đường đi

int n, m, a1, b1, a2, b2;
// n : Số hàng
// m : Số cột
vector<vector<char>> a;
vector<vector<bool>> visited;
vector<vector<int>> d; // d[i][j] lưu số bước đi từ ô bắt đầu đến ô i,j
vector<int> dx({-1, 0, 0, 1});
vector<int> dy({0, -1, 1, 0});

void inp()
{
    cin >> n >> m;
    a.resize(n + 1, vector<char>(m + 1));
    visited.resize(n + 1, vector<bool>(m + 1, 0));
    d.resize(n + 1, vector<int>(m + 1, 0));

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
            if (a[i][j] == 'A')
            {
                a1 = i;
                b1 = j;
            }
            else if (a[i][j] == 'B')
            {
                a2 = i;
                b2 = j;
            }
        }
    }
}

void bfs(const int &i, const int &j)
{
    queue<pair<int, int>> Q;
    Q.push({i, j});
    visited[i][j] = true;

    while (!Q.empty())
    {
        pair<int, int> u = Q.front();
        Q.pop();

        // Duyệt các đỉnh kề
        for (int k = 0; k < 4; k++)
        {
            int i1 = dx[k] + u.first;
            int j1 = dy[k] + u.second;
            // Kiểm tra ô vẫn nằm trên lưới
            if (i1 >= 1 && i1 <= n && j1 >= 1 && j1 <= m && !visited[i1][j1] && a[i1][j1] != 'x')
            {
                d[i1][j1] = d[u.first][u.second] + 1;
                if (a[i1][j1] == 'B')
                    return;
                Q.push({i1, j1});
                visited[i1][j1] = true;
            }
        }
    }
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    inp();
    bfs(a1, b1);
    if (d[a2][b2])
    {
        cout << "Co duong di" << endl;
        cout << "So buoc di ngan nhat: " << d[a2][b2] << endl;
    }
    else
        cout << "Khong co duong di" << endl;
    return 0;
}