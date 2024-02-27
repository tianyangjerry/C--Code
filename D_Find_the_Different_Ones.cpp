#include <bits/stdc++.h>
#define endl '\n'

using namespace std;
using i64 = long long;
const int N = 1e5 + 10;

void solve()
{
    int n; cin >> n;
    vector<i64> a(n);

    vector<int> b;

    for (int i = 0; i < n; ++ i) cin >> a[i];
    for (int i = 0; i < n; ++ i)
    {
        if (a[i] != a[i - 1]) b.push_back(i);
    }

    for (auto i : b) cout << i << " ";
    cout << endl;

    b.push_back(0x3f3f3f3f);
    int q; cin >> q;
    while (q -- )
    {
        int l, r; cin >> l >> r;
        int p = *lower_bound(b.begin(), b.end(), l);
        if (p + 1 <= r)
        {
            cout << p << " " << p + 1 << endl;
        }
        else cout << "-1 -1" << endl;
    }
    cout << endl;
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _; cin >> _;
    while (_ -- ) solve();
    return 0;
}