#include <bits/stdc++.h>
#define endl '\n'
#define int long long
#define ull unsigned long long
#define pii pair<int, int>
#define x first
#define y second

using namespace std;
const int N = 1e5 + 10, inf = 2e18, p = 13331;

int n, m;
int pre[N];
int S[N];
int find(int x)
{
	if (pre[x] != x) pre[x] = find(pre[x]);
	return pre[x];
}

void merge(int x, int y)
{
    x = find(x), y = find(y);
    if (x == y) return;
    S[find(y)] += S[find(x)];
	pre[find(x)] = find(y);
}

void solve()
{
    cin >> n >> m;
    for (int i = 1; i <= n; ++ i) 
    {
        pre[i] = i; S[i] = 1;
    }

    int x, y;
    for (int i = 1; i <= m; ++ i)
    {
        cin >> x >> y;
        merge(x, y);
    }
    int ans = 0;
    set<int> st;
    for (int i = 1; i <= n; ++ i)
    {
        st.insert(find(i));
        if (pre[i] == i)
        {
            ans = max(ans, S[find(i)]);
        }
    }
    cout << st.size() << endl;
    cout << ans << endl;
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    while (_ -- ) solve();
    return 0;
}