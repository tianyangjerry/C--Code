#include <bits/stdc++.h>
#define endl '\n'
#define int long long

using namespace std;
const int N = 1e5 + 10;

void solve()
{
    vector<pair<int, int>> a(4);
    for (int i = 0; i < 4; i ++ ) cin >> a[i].first >> a[i].second;
    sort(a.begin(), a.end(), [](pair<int, int> a, pair<int, int> b)
    {
        if (a.first != b.first) return a.first < b.first;
        else return a.second < b.second;
    } );

    int x = a[1].second - a[0].second, y = a[3].second - a[2].second;
    cout << x * y << endl;
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _; cin >> _;
    while (_ -- ) solve();
    return 0;
}