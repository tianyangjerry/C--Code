#include <bits/stdc++.h>
#define endl '\n'
//#define int long long
#define pii pair<int, int>
#define x first
#define y second

using namespace std;
const int N = 1e5 + 10;

int t, c, ts, te;
struct node{
    int u, v;
};
vector<node> g[N];
int d[N];
bool vis[N];

int dijkstra(int s, int e)
{
    priority_queue<pii, vector<pii>, greater<pii>> heap;
    heap.push({0, s});
    memset(d, 0x3f, sizeof d);
    d[s] = 0;
    while (heap.size())
    {
        auto t = heap.top();
        heap.pop();
        int u = t.y;
        if (vis[u]) continue;
        vis[u] = true;
        for (auto v : g[u])
        {
            if (d[v.u] > d[u] + v.v)
            {
                d[v.u] = d[u] + v.v;
                heap.push({d[v.u], v.u});
            }
        }
    }
    return d[e] == 0x3f3f3f3f ? -1 : d[e];
}

void solve()
{
    cin >> t >> c >> ts >> te;
    for (int i = 1; i <= c; i ++ )
    {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }

    cout << dijkstra(ts, te) << endl;
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    while (_ -- ) solve();
    return 0;
}