#include <bits/stdc++.h>
using namespace std;

// Bài 1: Đếm thành phần liên thông trên lưới

int n, m;
// n : Số hàng
// m : Số cột
vector<vector<char>> a;
vector<vector<bool>> visited;

vector<int> dx({-1, 0, 0, 1});
vector<int> dy({0, -1, 1, 0});

void inp()
{
    cin >> n >> m;
    a.resize(n + 1, vector<char>(m + 1));
    visited.resize(n + 1, vector<bool>(m + 1, false));

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            cin >> a[i][j];
        }
    }
}

void bfs(const int &i, const int &j)
{
    queue<pair<int, int>> Q;
    // {i, j}
    Q.push({i, j});
    visited[i][j] = true;

    while (!Q.empty())
    {
        pair<int, int> u = Q.front();
        Q.pop();
        cout << u.first << " " << u.second << endl;

        // Duyệt các đỉnh kề
        for (int k = 0; k < 4; ++k)
        {
            int i1 = u.first + dx[k];
            int j1 = u.second + dy[k];
            // Kiểm tra ô vẫn nằm trên lưới
            if (i1 >= 1 && i1 <= n && j1 >= 1 && j1 <= m && a[i1][j1] == 'x' && !visited[i1][j1])
            {
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
    int cnt = 0;

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            if (a[i][j] == 'x' && !visited[i][j])
            {
                cout << "Thanh phan lien thong thu: " << cnt + 1 << endl;
                bfs(i, j);
                cnt++;
            }
        }
    }

    cout << "So thanh phan lien thong: " << cnt;

    return 0;
}