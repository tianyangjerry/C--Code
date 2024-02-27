#include <bits/stdc++.h>
#define endl '\n'
#define int long long

using namespace std;
const int N = 2e5 + 10;
priority_queue<int, vector<int>, greater<int>> q;

int n, f, a, b;
int arr[N];
void solve()
{
    memset(arr, 0, sizeof arr);
    cin >> n >> f >> a >> b;
    for (int i = 1; i <= n; ++ i)
        cin >> arr[i];
    int t = 0;
    for (int i = 1; i <= n; ++ i)
    {
        if (a * (arr[i] - t) < b) f -= a * (arr[i] - t);
        else f -= b;
        t = arr[i];
    }
    if (f < 1) cout << "No" << endl;
    else cout << "Yes" << endl;
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _; cin >> _;
    while (_ -- ) solve();
    return 0;
}