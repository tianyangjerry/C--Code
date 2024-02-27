#include <bits/stdc++.h>
#define endl '\n'
#define int long long
#define ull unsigned long long
#define pii pair<int, int>
#define x first
#define y second

using namespace std;
const int N = 1e7 + 10, inf = 2e18, p = 131;

int n, m;
int mp[N];
bool vis[N];
int d[N];
int ans;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

bool check(int x, int y)
{
    return x >= 1 && x <= n && y >= 1 && y <= m;
}

void dijkstra(int x1, int y1, int x2, int y2)
{
    memset(d, 0x3f, sizeof d);
    memset(vis, 0, sizeof vis);
    d[(x1 - 1) * p + y1] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> q;
    q.push({0, (x1 - 1) * p + y1});
    while (q.size())
    {
        int u = q.top().y;
        q.pop();
        if (vis[u]) continue;
        vis[u] = 1;
        int x = (u - 1) / p + 1, y = (u - 1) % p + 1;
        for (int i = 0; i < 4; ++ i)
        {
            int nx = x + dx[i], ny = y + dy[i];
            if (check(nx, ny) && d[u] + mp[nx * p + ny] < d[(nx - 1) * p + ny])
            {
                d[(nx - 1) * p + ny] = d[u] + mp[nx * p + ny];
                q.push({d[(nx - 1) * p + ny], (nx - 1) * p + ny});
            }
        }
    }
    cout << d[(x2 - 1) * p + y2] << endl;
}


void solve()
{
    cin >> n >> m;
    for (int i = 1; i <= n; ++ i)
        for (int j = 1; j <= m; ++ j)
            cin >> mp[i * p + j];
    int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;

    dijkstra(x1, y1, x2, y2);
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    while (_ -- ) solve();
    return 0;
}