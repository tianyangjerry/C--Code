#include <bits/stdc++.h>
#define endl '\n'
#define int long long

using namespace std;
const int N = 2e5 + 10;
priority_queue<int, vector<int>, greater<int>> q;

int n;
string a, b;

void solve()
{
    int x = 0, y = 0;
    cin >> n >> a >> b;

    for (int i = 0; i < n; ++ i)
    {
        int t = (a[i] - '0') - (b[i] - '0');
        if (t > 0) x ++;
        if (t < 0) y ++;
    }

    int ans = max(x, y);
    cout << ans << endl;
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _; cin >> _;
    while (_ -- ) solve();
    return 0;
}