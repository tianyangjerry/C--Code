#include <bits/stdc++.h>
#define endl '\n'
#define int long long

using namespace std;
const int N = 1e5 + 10;
const int inf = 2e18;
int a[N], b[N];
int n;

void solve()
{
    cin >> n;

    for (int i = 1; i <= n; ++ i)
    {
        int x; cin >> x;
        a[i] = i * i - x * x;
        b[i] = i * i + x * x;
    }

    //for (int i = 1; i <= n; ++ i) cout << b[i] << " ";

    sort(a + 1, a + n + 1);
    sort(b + 1, b + n + 1);
    int ans = max(a[n] - a[1], b[n] - b[1]);
    cout << ans << endl;
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    while (_ -- ) solve();
    return 0;
}