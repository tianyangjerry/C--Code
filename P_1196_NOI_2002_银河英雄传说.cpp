#include <iostream>
#include <cstring>
#include <algorithm>

#define endl "\n"

using namespace std;
int n;
const int N = 30010;
int p[N], s[N], d[N];

int find(int x)
{
    if (x != p[x]) 
    {
        int root = find(p[x]);
        d[x] += d[p[x]];
        p[x] = root;
    }
    return p[x];
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    cin >> n;
    for (int i = 1; i <= N; ++ i)
    {
        p[i] = i;
        s[i] = 1;
    }

    for (int i = 1; i <= n; ++ i)
    {
        char op;
        int a, b;
        cin >> op >> a >> b;
        if (op == 'M')
        {
            int pa = find(a), pb = find(b);
            if (pa != pb)
            {
                d[pa] = s[pb];
                s[pb] += s[pa];
                p[pa] = pb;
            }
        }
        else if (op == 'C')
        {
            int pa = find(a), pb = find(b);
            if (pa != pb)
            {
                cout << -1 << endl;
                continue;
            }
            else
            {
                int res = abs(d[a] - d[b]) - 1;
                cout << (res == -1 ? 0 : res) << endl;
            }
        }
    }
    return 0;
}
