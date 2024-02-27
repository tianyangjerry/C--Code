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
    for (int i = 0; i < s.size(); ++ i)
    {
        int t = (s[i] - '0') * 2;
        if (t > 9) t -= 9;
        s[i] = t + '0';
    }
    //cout << s << endl;
    for (int i = 0; i < s.size(); ++ i)
    {
        int t = (s[i] - '0') + 2;
        if (t > 9) t -= 9;
        s[i] = t + '0';
    }
    //cout << s << endl;
    reverse(s.begin(), s.end());
    cout << s << endl;
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    while (_ -- ) solve();
    return 0;
}