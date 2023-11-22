#include <bits/stdc++.h>
using namespace std;

struct Edge
{
    int u, v;
    int w;

    Edge() {}

    Edge(int _u, int _v, int _w) : u(_u), v(_v), w(_w) {}
};

int n, m;
vector<vector<pair<int, int>>> adj; // danh sách kề
vector<bool> used;                  // used[i] = true : i thuộc tập V(mst), used[i] = false : i thuộc tập v

void inp()
{
    cin >> n >> m;
    adj.resize(n + 1);
    used.assign(n + 1, false);

    for (int i = 0; i < m; i++)
    {
        int x, y, w;
        cin >> x >> y >> w;
        adj[x].push_back({y, w});
        adj[y].push_back({x, w});
    }
}

void prim(int u)
{
    // Khởi tạo
    vector<Edge> mst; // Cây khung
    int d = 0;        // Tổng trọng số
    used[u] = true;   // Đưa đỉnh u vào tap V(mst)

    // Lặp
    while (mst.size() < n - 1)
    {
        // e = (x, y) : Cạnh ngắn nhất x thuộc V, y thuộc mst
        int min_w = INT_MAX;
        int X, Y; // Lưu 2 đỉnh cạnh e

        for (int i = 1; i <= n; i++)
        {
            // Nếu đỉnh i thuộc tập V(mst)
            if (used[i])
            {
                // Duyệt danh sách kề của đỉnh i
                for (auto it : adj[i])
                {
                    int j = it.first, w = it.second;
                    if (!used[j] && w < min_w)
                    {
                        min_w = w;
                        X = j;
                        Y = i;
                    }
                }
            }
        }

        mst.push_back(Edge(X, Y, min_w));
        d += min_w;
        used[X] = true; // Cho đỉnh X vao V(mst) và loại X khỏi tập v
    }

    cout << d << endl;
    for (auto e : mst)
        cout << e.u << " " << e.v << " " << e.w << endl;
}

int main()
{
    freopen("inp.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    inp();
    prim(1);

    return 0;
}