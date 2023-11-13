#include <bits/stdc++.h>
using namespace std;

#define ll long long

// input
int n, e;
// n: Số đỉnh
// e: Số cạnh
vector<vector<pair<int, int>>> g(100001);

void input()
{
    cin >> n >> e;
    for (int i = 1; i <= e; i++)
    {
        int x, y, w;
        cin >> x >> y >> w;
        g[x].push_back({y, w});
        g[y].push_back({x, w});
    }
}

const int INF = 1e9;
void dijkstra(int s)
{
    vector<bool> visited(n + 1, false);
    // Mảng lưu khoảng cách đường đi
    vector<ll> d(n + 1, INF);
    d[s] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    // {khoang cach, dinh}

    q.push({0, s});

    while (!q.empty())
    {
        // Chọn ra đỉnh có khoảng cách từ s nhỏ nhất
        pair<int, int> top = q.top();
        q.pop();

        int u = top.second;
        int l = top.first;

        if (visited[u])
            continue; // Đỉnh này được xét rồi

        visited[u] = true;
        for (auto it : g[u])
        {
            // Relaxation: Cập nhật khoảng cách từ s cho tới mọi đỉnh kề với u
            int v = it.first;
            int w = it.second;
            if (d[v] > d[u] + w)
            {
                d[v] = d[u] + w;
                q.push({d[v], v});
            }
        }
    }

    for (int i = 1; i <= n; i++)
        cout << d[i] << " ";
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    input();
    dijkstra(1);

    return 0;
}