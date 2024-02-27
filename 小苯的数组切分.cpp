#include <bits/stdc++.h>
#define endl '\n'
#define int long long
#define ull unsigned long long
#define pii pair<int, int>
#define x first
#define y second

using namespace std;
const int N = 1e5 + 10, inf = 2e18, p = 13331;
int a[N], yihuo[N], huo[N];

void solve()
{
    int n; cin >> n;
    for (int i = 1; i <= n; i ++ ) cin >> a[i];

    for (int i = 1; i <= n; ++ i) yihuo[i] = yihuo[i - 1] ^ a[i];
    for (int i = 1; i <= n - 1; ++ i) huo[i] = huo[i + 1] | a[i];
    int ans = 0;
    for (int i = 1; i <= n - 2; ++ i)
    {
        ans = max(ans, yihuo[i] + huo[i + 1] + a[n]);
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