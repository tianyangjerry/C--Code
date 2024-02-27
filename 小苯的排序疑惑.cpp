#include <bits/stdc++.h>
#define endl '\n'
#define int long long
#define ull unsigned long long
#define pii pair<int, int>
#define x first
#define y second

using namespace std;
const int N = 1e5 + 10, inf = 2e18, p = 13331;
int a[N];
void solve()
{
    int n; cin >> n;
    int maxx = -inf, minn = inf;
    for (int i = 1; i <= n; ++ i)
    {
        int x; cin >> x;
        a[i] = x;
        maxx = max(maxx, x);
        minn = min(minn, x);
    }
    //cout << maxx << " " << minn << endl;
    if (maxx == a[n] || minn == a[1]) cout << "Yes" << endl;
    else cout << "No" << endl;
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _; cin >> _;
    while (_ -- ) solve();
    return 0;
}