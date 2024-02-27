#include <bits/stdc++.h>
#define endl '\n'
#define int long long

using namespace std;
const int N = 2e5 + 10;
priority_queue<int, vector<int>, greater<int>> q;
int n;

void solve()
{
    cin >> n;
    for (int i = 1; i <= n; ++ i)
    {
        int x; cin >>  x;
        q.push(x);
    }
    int ans = 0;
    while (q.size() > 1)
    {
        int x = q.top(); q.pop();
        int y = q.top(); q.pop();
        ans += x + y;
        q.push(x + y);
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