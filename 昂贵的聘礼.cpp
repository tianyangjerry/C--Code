#include <bits/stdc++.h>
#define endl '\n'
#define pii pair<int, int>

using namespace std;

const int N = 110, M = 10010;
int e[M], w[M], h[N], ne[M], idx;
int level[N];
int dist[N];
bool st[N];
int m, n; //最大等级限制，物品数
void add(int a, int b, int c)
{
	e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx ++;
}

int dijkstra(int down, int up)
{
    memset(dist, 0x3f, sizeof dist);
    memset(st, 0, sizeof st);
    dist[0] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> heap;
    heap.push({0, 0});
    while (heap.size())
    {
        auto t = heap.top();
        heap.pop();
        int ver = t.second, distance = t.first;
        if (st[ver]) continue;
        st[ver] = true;
        for (int i = h[ver]; i != -1; i = ne[i])
        {
            int j = e[i];
            if (level[j] < down || level[j] > up) continue;
            if (dist[j] > dist[ver] + w[i])
            {
                dist[j] = dist[ver] + w[i];
                heap.push({dist[j], j});
            }
        }
    }
    return dist[1];
}

void solve()
{
    memset(h, -1, sizeof h);
	cin >> m >> n;
    for (int i = 1; i <= n; ++ i)
    {
        int price, l, cnt;
        cin >> price >> l >> cnt;
        level[i] = l;
        add(0, i, price);
        while (cnt -- )
        {
            int t, v;
            cin >> t >> v;
            add(t, i, v);
        }
    }

    int ans = 0x3f3f3f3f;
    for (int i = level[1] - m; i <= level[1]; ++ i)
    {
        ans = min(ans, dijkstra(i, i + m));
    }
    cout << ans << endl;
}

signed main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int _ = 1;
	while (_ -- ) solve();
	return 0;
}