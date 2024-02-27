#include <bits/stdc++.h>
#define endl '\n'
#define int long long

using namespace std;
const int N = 2e5 + 10;

int n, m;
int a[N], b[N];
void solve()
{
    cin >> n >> m;

    for (int i = 1; i <= n; i ++ ) cin >> a[i];
    for (int i = 1; i <= m; i ++ ) cin >> b[i];

    sort(a + 1, a + n + 1, [](int x, int y) { return x > y; });
    sort(b + 1, b + m + 1);

    for (int i = 1; i <= n; ++ i) a[i] = a[i - 1] + a[i];
    for (int i = 1; i <= m; ++ i) b[i] = b[i - 1] + b[i];

    int res = 0;
    for (int k = 0; k <= n; ++ k)
    {
        int temp = a[k] - (a[n] - a[k]);
        temp += (b[m] - b[m - n + k]) - b[k];
        res = max(res, temp);
    }
    cout << res << endl;
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _; cin >> _;
    while (_ -- ) solve();
    return 0;
}