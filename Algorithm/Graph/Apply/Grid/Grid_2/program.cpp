#include <bits/stdc++.h>
using namespace std;

// Bài 2: Kiểm tra đường đi giữa 2 điểm trên lưới
// o : có đường đi
// x : ko có đường đi

int n, m, x, y;
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
    visited.resize(n + 1, vector<bool>(m + 1, 0));

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
            if (a[i][j] == 'A')
            {
                x = i;
                y = j;
            }
        }
    }
}

bool bfs(const int &i, const int &j)
{
    queue<pair<int, int>> Q;
    Q.push({i, j});
    visited[i][j] = true;

    while (!Q.empty())
    {
        pair<int, int> u = Q.front();
        Q.pop();

        cout << u.first << " " << u.second << endl;

        // Duyệt các đỉnh kề
        for (int k = 0; k < 4; k++)
        {
            int i1 = dx[k] + u.first;
            int j1 = dy[k] + u.second;
            // Kiểm tra ô vẫn nằm trên lưới
            if (i1 >= 1 && i1 <= n && j1 >= 1 && j1 <= m && !visited[i1][j1] && a[i1][j1] != 'x')
            {
                cout << i1 << " " << j1 << endl;
                if (a[i1][j1] == 'B')
                    return true;
                Q.push({i1, j1});
                visited[i1][j1] = true;
            }
        }
    }
    return false;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    inp();
    if (bfs(x, y))
        cout << "Co duong di" << endl;
    else
        cout << "Khong co duong di" << endl;
    return 0;
}