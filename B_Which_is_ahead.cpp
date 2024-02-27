#include <bits/stdc++.h>
#define endl '\n'
#define int long long
#define ull unsigned long long
#define pii pair<int, int>
#define x first
#define y second

using namespace std;
const int N = 1e5 + 10, inf = 2e18, p = 13331;

map<int, int> mp;
int n, q;
void solve()
{
    cin >> n;
    for (int i = 1; i <= n; ++ i)
    {
        int x; cin >> x;
        mp[x] = i;
    }
    cin >> q;
    while (q --)
    {
        int x, y; cin >> x >> y;
        int a1 = mp.find(x) == mp.end() ? -1 : mp[x];
        int a2 = mp.find(y) == mp.end() ? -1 : mp[y];
        if (a1 > a2) cout << y << endl;
        else cout << x << endl;
    }
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    while (_ -- ) solve();
    return 0;
}

//memset(g, inf, sizeof g);
//for (int i = 1; i <= n; ++ i){
//    for (int j = 1; j <= n; ++ j){
//        g[i][j] = inf;
//}}
