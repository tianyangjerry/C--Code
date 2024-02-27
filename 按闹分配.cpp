#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int n, q;
ll tc;

void solve()
{
    cin >> n >> q >> tc;
    vector<ll> a(n + 1, 0);
    for (int i = 1; i <= n; i ++ ) cin >> a[i];

    sort(begin(a) + 1, end(a));

    vector<ll> s(n + 1, 0);
    for (int i = 1; i <= n; i ++ ) s[i] = s[i - 1] + a[i];

    while (q -- )
    {
        ll x; cin >> x;
        ll c = min(1ll* n, x / tc);
        ll ans = s[n - c] + tc;
        cout << ans << "\n";
    }
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int _ = 1;
    while (_ -- )
    {
        solve();
    }
    return 0;
}   