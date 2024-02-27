#include <bits/stdc++.h>

using i64 = long long;

std::string s;
void solve()
{
    s.clear();
    int n;
    std::cin >> n >> s;
    // if (n == 1)
    // {
    //     std::cout << (s[0] == 'B' ? 1 : 0) << std::endl;
    //     return;
    // }
    int x, y;
    for (int i = 0; i < s.size(); i ++)
    {
        if (s[i] == 'B')
        {
            x = i;
            break;
        }
    }   
    for (int j = s.size() - 1; j >= 0; j --)
    {
        if (s[j] == 'B')
        {
            y = j;
            break;
        }
    }
    std::cout << y - x + 1 << "\n";
}

int main()
{
    std::ios::sync_with_stdio(0), std::cin.tie(0), std::cout.tie(0);
    int _; std::cin >> _;
    while (_ -- ) solve();
    return 0;
}