#include <bits/stdc++.h>
#define endl '\n'
#define int long long

using namespace std;
const int N = 1e5 + 10;
int n, a[N], f[N], g[N];

void solve()
{
    cin >> n;
    for (int i = 1; i <= n; ++ i) cin >> a[i];
    for (int i = 1; i <= n; ++ i)
    {
        f[i] = 1;
        for (int j = 1; j < i; ++ j)
            if (a[j] < a[i])
                f[i] = max(f[i], f[j] + 1);
    }

    for (int i = n; i >= 1; -- i)
    {
        g[i] = 1;
        for (int j = n; j > i; -- j)
            if (a[j] > a[i])
                g[i] = max(g[i], g[j] + 1);
    }
    int ans = 0;
    for (int i = 1; i <= n; ++ i)
        ans = max(ans, f[i] + g[i] - 1);
    cout << ans << endl;
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    while (_ -- ) solve();
    return 0;
}