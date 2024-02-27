#include <bits/stdc++.h>
#define endl '\n'
//#define int long long
#define ull unsigned long long
#define pii pair<int, int>

using namespace std;
const int N = 50010, M = 200010, inf = 2e18, p = 13331;

int n, m;
int e[M], w[M], ne[M], h[N], idx;
int source[20];
int dist[10][N];
bool st[N];
int res = inf;

void add(int a, int b, int c)
{
	e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx ++; 
}

void dijkstra(int start, int dist[])
{
    memset(dist, 0x3f, N * 4);
    dist[start] = 0;
    memset(st, 0, sizeof st);

	priority_queue<pii, vector<pii>, greater<pii>> heap;
	heap.push({0, start});
	while (heap.size())
    {
        auto t = heap.top();
        heap.pop();

        int ver = t.second;
        if (st[ver]) continue;
        st[ver] = true;

        for (int i = h[ver]; ~i; i = ne[i])
        {
            int j = e[i];
            if (dist[j] > dist[ver] + w[i])
            {
                dist[j] = dist[ver] + w[i];
                heap.push({dist[j], j});
            }
        }
    }
}

int dfs(int u, int start, int distance)
{
    if (u > 5) return distance;

    int res = inf;
    for (int i = 1; i <= 5; i ++ )
        if (!st[i])
        {
            int next = source[i];
            st[i] = true;
            res = min(res, dfs(u + 1, i, distance + dist[start][next]));
            st[i] = false;
        }

    return res;
}

void solve()
{
    cin >> n >> m;
    memset(h, -1, sizeof h);
    source[0] = 1;
    for (int i = 1; i <= 5; ++ i) cin >> source[i];
    for (int i = 1; i <= m; ++ i)
    {
    	int a, b, c; cin >> a >> b >> c;
    	add(a, b, c);
    	add(b, a, c);
	}
	
	for (int i = 0; i < 6; ++ i)
        dijkstra(source[i], dist[i]);
    memset(st, 0, sizeof st);
    cout << dfs(1, 0, 0) << endl;
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    while (_ -- ) solve();
    return 0;
}