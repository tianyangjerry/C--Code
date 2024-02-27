#include <bits/stdc++.h>
#define endl '\n'
#define int long long
#define pii pair<int, int>
#define x first
#define y second

using namespace std;
const int N = 1010;

int n, m, k;
int a[N], b[N], f[N][N];
void solve()
{
    cin >> n >> m >> k;
    for (int i = 1; i <= k; i ++ ) cin >> a[i] >> b[i];

    for (int i = 1; i <= k; ++ i)
    {
        for (int j = n; j >= a[i]; -- j)
        {
            for (int v = m; v >= b[i]; -- v)
            {
                f[j][v] = max(f[j][v], f[j - a[i]][v - b[i]] + 1);
            }
        }
    }

    cout << f[n][m] << " ";

    int ans = m;
    for (int i = 0; i <= m; ++ i)
    {
        if (f[n][i] == f[n][m])
        {
           ans = min(ans, i);
        }
    }

    cout << m - ans << endl;
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    while (_ -- ) solve();
    return 0;
}