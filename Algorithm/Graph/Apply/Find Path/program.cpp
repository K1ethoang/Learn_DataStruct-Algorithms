#include <bits/stdc++.h>
using namespace std;

int n, m, s, t;
vector<vector<int>> adj;
vector<int> parent;
vector<bool> visited;

void input()
{
    cin >> n >> m >> s >> t;

    adj.resize(n + 1);
    parent.resize(n + 1, -1);
    visited.resize(n + 1, false);

    for (int i = 1; i <= m; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
}

void bfs(const int &s)
{
    queue<int> Q;

    Q.push(s);
    visited[s] = true;

    while (!Q.empty())
    {
        int u = Q.front();
        Q.pop();

        for (int v : adj[u])
        {
            if (!visited[v])
            {
                Q.push(v);
                visited[v] = true;
                // Ghi nhận cha của v là u
                parent[v] = u;
            }
        }
    }
}

void findPath(const int &s, const int &t)
{
    bfs(s);
    if (!visited[t])
        cout << "No exist path!" << endl;
    else
    {
        // Truy vết đường đi
        vector<int> path;
        int tempT = t;
        // bắt đầu từ đỉnh t
        while (tempT != s)
        {
            path.push_back(tempT);
            // Lần ngược lại
            tempT = parent[tempT];
        }
        path.push_back(s);
        reverse(path.begin(), path.end());
        for (int x : path)
            cout << x << " ";
    }
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    input();
    findPath(s, t);
    return 0;
}