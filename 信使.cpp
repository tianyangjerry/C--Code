#include <bits/stdc++.h>
#define endl '\n'
//#define int long long
#define pii pair<int, int>
#define x first
#define y second

using namespace std;
const int N = 1e5 + 10;
int n, m, d[N];
void dijkstra()
{
    memset(d, 0x3f, sizeof (d));
    d[1] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> q;
    q.push({0, 1});
    while (q.size())
    {
        
    }
}

void solve()
{
    dijkstra();
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    while (_ -- ) solve();
    return 0;
}