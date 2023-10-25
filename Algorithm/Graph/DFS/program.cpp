#include <bits/stdc++.h>
using namespace std;

// input
int n, m;
// n: Số đỉnh
// m: Số cạnh
vector<vector<int>> grh(1001);
vector<bool> visited(1001, 0);

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

void dfs(int u)
{
    cout << u << " ";
    // Danh dau u da duoc tham
    visited[u] = true;
    for (int v : grh[u])
        // Neu dinh v chua duoc tham
        if (!visited[v])
            dfs(v);
}

int main()
{
    freopen("input.txt", "r", stdin);
    input();
    dfs(3);
    return 0;
}