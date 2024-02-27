#include <bits/stdc++.h>

using i64 = long long;

const int N = 2e6 + 10;
std::set<int> a;
std::set<int> b;
std::set<int> s;

void solve()
{
    int n, m, k;
    std::cin >> n >> m >> k;
    a.clear();
    b.clear();
    s.clear();
    for (int i = 0; i < n; ++ i)
    {
        int x;
        std::cin >> x;
        if (x >= 1 && x <= k) a.insert(x), s.insert(x);
    }

    for (int i = 0; i < m; ++ i)
    {
        int x;
        std::cin >> x;
        if (x >= 1 && x <= k) b.insert(x), s.insert(x);
    }
    
    if (a.size() >= k / 2 && b.size() >= k / 2 && s.size() == k)
    {
        std::cout << "YES\n";
    }
    else
    {
        std::cout << "NO\n";
    }
}

int main()
{
    std::ios::sync_with_stdio(0), std::cin.tie(0), std::cout.tie(0);
    int _; std::cin >> _;
    while (_ -- ) solve();
    return 0;
}