#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int N = 1e5 + 10;

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    s = ' ' + s;
    string s1 = " DFS", s2 = " dfs";
    vector<vector<int>> dp1(n+1, vector<int>(4, 0)), dp2(n+1, vector<int>(4, 0));
    dp1[0][0] = dp2[0][0] = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= 3; ++j) {
            dp1[i][j] = dp1[i-1][j];
            dp2[i][j] = dp2[i-1][j];
            if (s[i] == s1[j]) dp1[i][j] |= dp1[i-1][j-1];
            if (s[i] == s2[j]) dp2[i][j] |= dp2[i-1][j-1];
        }
    }
    if (dp1[n][3]) cout << "1" << " ";
    else cout << 0 << " ";
    if (dp2[n][3]) cout << "1" << " ";
    else cout << 0;
    cout << "\n";
}
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _; cin >> _;
    while (_ -- ) solve();
    return 0;
}

