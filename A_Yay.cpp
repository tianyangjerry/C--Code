#include <bits/stdc++.h>
#define endl '\n'
#define int long long
#define ull unsigned long long
#define pii pair<int, int>
#define x first
#define y second

using namespace std;
const int N = 1e5 + 10, inf = 2e18, p = 13331;

void solve()
{
    string s; cin >> s;
    map<char, int> mp;
    for (auto c : s) mp[c] ++;
    for (int i = 0; i < s.size(); ++ i)
    {
        if (mp[s[i]] == 1)
        {
            cout << i + 1 << endl;
            break;
        }
    }
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    while (_ -- ) solve();
    return 0;
}