#include <bits/stdc++.h>

using i64 = long long;

const int N = 2e5 + 10;
int a[N];
bool vis[N];
bool vis[N];

void solve()
{
    memset(vis, false, sizeof(vis));
    memset(a, 0, sizeof(a));
    int n;
    std::cin >> n;
    std::vector<char> s(n);
    for (int i = 0; i < n; ++ i)
        std::cin >> a[i];
    char c = 'a';
    for (int i = 0; i < n; ++ i)
    {
        if (vis[i] == true) continue;
        int x = a[i];
        s[i] = c;
        for (int j = i + 1; j < n; ++ j)
        {
            if (vis[j] == true) continue;
            if (x + 1 == a[j])
            {
                vis[j] = true;
                s[j] = c;
                x ++;
            }
        }
        c = c + 1;
    }

    for (auto i : s)
    {
        std::cout << i;
    }
    std::cout << "\n";
    // int acnt = 0, bcnt = 0;
    // for (int i = 1; i <= k; ++ i)
    // {
    //     if (acnt > k / 2 || bcnt > k / 2)
    //     {
    //         std::cout << "NO\n";
    //         return;
    //     }
    //     if(a.count(i) && !b.count(i))
    //     {
    //         acnt++;
    //     }
    //     if(!a.count(i) && b.count(i))
    //     {
    //         bcnt++;
    //     }
    //     if (a.count(i) && b.count(i))
    //     {
    //         if (acnt >= bcnt)
    //         {
    //             bcnt++;
    //         }
    //         else
    //         {
    //             acnt++;
    //         }
    //     }
    // }
    // int cnt = acnt + bcnt;
    // if (cnt == k)
    // {
    //     std::cout << "YES\n";
    // }
    // else
    // {
    //     std::cout << "NO\n";
    // }
}

int main()
{
    std::ios::sync_with_stdio(0), std::cin.tie(0), std::cout.tie(0);
    int _; std::cin >> _;
    while (_ -- ) solve();
    return 0;
}