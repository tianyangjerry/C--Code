#include <bits/stdc++.h>
#define endl '\n'
#define int long long
#define ull unsigned long long
#define pii pair<int, int>
#define x first
#define y second

using namespace std;
const int N = 1e5 + 10, inf = 2e18, p = 13331;
int n, q;
map<char, char> mp;
void solve()
{
    cin >> n;
    string s; cin >> s;
    for (int i = 'a'; i <= 'z'; ++ i)
    {
        mp[i] = i;
    }
    cin >> q;
    while (q -- )
    {
        char a, b; cin >> a >> b;
        for (int i = 'a'; i <= 'z'; ++ i)
        {
            if (mp[i] == a) mp[i] = b;
        }
    }
    for (auto &x : s) x = mp[x];
    cout << s << endl;
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    while (_ -- ) solve();
    return 0;
}