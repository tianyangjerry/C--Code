#include <bits/stdc++.h>
#define endl '\n'
#define int long long
#define pii pair<int, int>
#define x first
#define y second

using namespace std;
const int N = 5010;
pii f[N];
int g[N];
int n;

void solve()
{
    cin >> n;
    for (int i = 1; i <= n; ++ i)
    {
        int x, y; cin >> x >> y;
        f[i] = {x, y};
    }
    sort(f + 1, f + n + 1, [](pii a, pii b){
        return a.x < b.x;
    });
    /* for (int i = 1; i <= n; ++ i)
    {
        cout << f[i].x << " " << f[i].y << endl;
    } */
    int res = 0;
    for (int i = 1; i <= n; ++ i)
    {
        g[i] = 1;
        for (int j = 1; j < i; ++ j)
        {
            if (f[i].y > f[j].y)
            {
                g[i] = max(g[i], g[j] + 1);
            }
        }
        res = max(res, g[i]);
    }
    cout << res << endl;
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    while (_ -- ) solve();
    return 0;
}