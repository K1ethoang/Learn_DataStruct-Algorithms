#include <bits/stdc++.h>
using namespace std;

struct Edge
{
    int u, v;
    int w;

    Edge() {}

    Edge(int _u, int _v, int _w)
        : u(_u), v(_v), w(_w) {}

    bool operator<(const Edge &e)
    {
        return (this->w < e.w);
    }
};

const int MAX_N = 1001;
int n, m;
vector<int> parent, sz;
vector<Edge> edge;

void make_set()
{
    for (int i = 1; i <= n; i++)
    {
        parent[i] = i;
        sz[i] = 1;
    }
}

int find(int u)
{
    if (u == parent[u])
        return u;
    return parent[u] = find(parent[u]);
}

bool Union(int u, int v)
{
    int a = find(u);
    int b = find(v);

    if (a == b) // Khong the gop a, v voi nhau
        return false;

    if (sz[a] < sz[b])
        swap(a, b);
    parent[b] = a;
    sz[a] += sz[b];
    return true;
}

void inp()
{
    cin >> n >> m;
    parent.resize(n + 1);
    sz.resize(n + 1);

    for (int i = 0; i < m; i++)
    {
        int x, y, w;
        cin >> x >> y >> w;
        Edge e = Edge(x, y, w);
        edge.push_back(e);
    }
}

void kruskal()
{
    // Tao cay khung cuc tieu rong
    vector<Edge> mst;
    int d = 0; // tong trong so
    // Sap xep canh theo trong so tang dan
    sort(edge.begin(), edge.end());
    // Lặp
    for (int i = 0; i < m; i++)
    {
        if (mst.size() == n - 1)
            break;

        Edge e = edge[i]; // Cạnh nhỏ nhất
        if (Union(e.u, e.v))
        {
            mst.push_back(e);
            d += e.w;
        }
    }
    // Trả về kết quả
    if (mst.size() != n - 1)
        cout << "Do thi khong lien thong!\n";
    else
    {
        cout << "MST : " << d << endl;
        for (const auto &e : mst)
            cout << e.u << " " << e.v << " " << e.w << endl;
    }
}

int main()
{
    freopen("inp.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    inp();
    make_set();
    kruskal();

    return 0;
}