#include <bits/stdc++.h>
using namespace std;

// declare function
void input_1();
void output_1();

void input_2();
void output_2();

void input_3();
void output_3();

void input_4();
void output_4();

void input_5();
void output_5();

int n, m;
// n: đỉnh (vertices)
// m : cạnh (edge)

// Code 1, 3, 4
vector<vector<int>> g(1000, vector<int>(1000, 0));

// Code 2, 4
vector<vector<int>> a(1000, vector<int>());

// Code 3
vector<pair<int, int>> edge;

int main()
{
    // code 1 input: danh sách cạnh -> ma trận kề
    // freopen("inp-out/inp1.txt", "r", stdin);
    // freopen("inp-out/out1.txt", "w", stdout);

    // code 2 input: danh sách cạnh -> danh sách kề
    // freopen("inp-out/inp1.txt", "r", stdin);
    // freopen("inp-out/out2.txt", "w", stdout);

    // code 3 input: ma trận kề -> danh sách cạnh
    // freopen("inp-out/inp3.txt", "r", stdin);
    // freopen("inp-out/out3.txt", "w", stdout);

    // code 4 input: ma trận kề -> danh sách kề
    // freopen("inp-out/inp3.txt", "r", stdin);
    // freopen("inp-out/out4.txt", "w", stdout);

    // code 5 input: danh sách kề -> ma trận kề
    freopen("inp-out/inp5.txt", "r", stdin);
    freopen("inp-out/out5.txt", "w", stdout);

    // Code 1
    // input_1();
    // output_1();

    // Code 2
    // input_2();
    // output_2();

    // Code 3
    // input_3();
    // output_3();

    // Code 4
    // input_4();
    // output_4();

    // Code 5
    input_5();
    output_5();

    return 0;
}

void input_1()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;

        g[x][y] = g[y][x] = 1;
    }
}

void output_1()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            cout << g[i][j] << " ";
        cout << endl;
    }
}

void input_2()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
}

void output_2()
{
    for (int i = 1; i <= n; i++)
    {
        cout << i << " : ";
        for (int x : a[i])
            cout << x << " ";
        cout << endl;
    }
}

void input_3()
{
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            cin >> g[i][j];
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (g[i][j] && i < j)
                edge.push_back({i, j});
        }
    }
}

void output_3()
{
    for (auto it : edge)
    {
        cout << it.first << " " << it.second << endl;
    }
}

void input_4()
{
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> g[i][j];
            if (g[i][j])
            {
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (g[i][j])
                a[i].push_back(j);
        }
    }
}

void output_4()
{
    output_2();
}

void input_5()
{
    cin >> n;

    cin.ignore();
    string s;
    int num;

    for (int i = 1; i <= n; i++)
    {
        getline(cin, s);
        stringstream ss(s);

        while (ss >> num)
        {
            g[i][num] = 1;
        }
    }
}

void output_5()
{
    output_1();
}