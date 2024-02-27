#include <bits/stdc++.h>
#define endl '\n'
#define int long long
#define pii pair<int, int>
#define x first
#define y second

using namespace std;
const int N = 1e5 + 10, inf = 2e18;
int a[N];

void solve()
{
    int n; cin >> n;
    for (int i = 1; i <= n; ++ i) cin >> a[i];

    int ans1 = 0, ans2 = 0;
    bool flag = false;
    for (int i = n; i >= 1; -- i)
    {
        if (flag == false) 
        {
            flag = true;
            ans1 += a[i];
        }
        else 
        {
            flag = false;
            ans2 += a[i];
        }
    }
    //cout << ans1 << " " << ans2 << endl;
    if (ans1 > ans2) cout << "Alice" << endl;
    else cout << "Bob" << endl;
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _; cin >> _;
    while (_ -- ) solve();
    return 0;
}