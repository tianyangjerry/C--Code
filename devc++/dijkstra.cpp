#include <bits/stdc++.h>

using namespace std;

const int N = 510, M = 1e6 + 10;
int h[N], e[M], w[M], ne[M], idx;
int dist[N];
bool st[N];
int stop[N];
int n, m;

void add(int a, int b)
{
	e[idx] = b, w[idx] = 1, ne[idx] = h[a], h[a] = idx ++;
}

void bfs()
{
	memset(dist, 0x3f, sizeof dist);
	queue<int> q;
	q.push(1);
	dist[1] = 0;
	st[1] = 0;
	while (q.size())
	{
		auto t = q.front();
		q.pop();
		for (int i = h[t]; i != -1; i = ne[i])
		{
			int j = e[i];
			if (st[j] == 1) continue;
			st[j] = 1;
			dist[j] = dist[t] + w[i];
			q.push(j);
		}
	}
}

void solve()
{
	memset(h, -1, sizeof h);
	cin >> m >> n;
	getchar();
	while (m -- )
	{
		string line;
		getline(cin, line);
		stringstream ss;
		ss.str(line);
		int cnt = 0;
		while (ss >> stop[cnt]) cnt ++;
		for (int i = 0; i < cnt; ++ i) cout << stop[i] << " ";
		cout << endl;
		for (int i = 0; i < cnt - 1; ++ i)
		{
			for (int j = i + 1; j <= cnt - 1; ++ j)
			{
				add(stop[i], stop[j]);
			}
		}
	}
	bfs();
	if (dist[n] == 0x3f3f3f3f) cout << "NO";
	else cout << dist[n] - 1;
}

signed main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int _ = 1;
	while (_ -- ) solve();
	return 0;
}