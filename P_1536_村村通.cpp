#include <bits/stdc++.h>

using i64 = long long;

const int N = 1010;
int p[N];
int find(int x) { return p[x] == x ? x : p[x] = find(p[x]); }

void solve()
{
    while (true)
    {
        int n, m;
        std::cin >> n; if (n == 0) exit(0);
        std::cin >> m;
        for (int i = 1; i <= n; i++) p[i] = i;
        for (int i = 0, a, b; i < m; i++)
        {
            std::cin >> a >> b;
            p[find(a)] = find(b);
        }
        std::set<int> s;
        for (int i = 1; i <= n; i++) s.insert(find(i));
        std::cout << s.size() - 1 << '\n';
    }
}

int main()
{
    std::ios::sync_with_stdio(0), std::cin.tie(0), std::cout.tie(0);
    int _ = 1;
    while (_ --) solve();
    return 0;
}