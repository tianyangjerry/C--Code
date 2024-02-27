#include <bits/stdc++.h>
#define endl '\n'
#define int long long

using namespace std;
const int N = 1e5 + 10;

int d[] = {-1, 0, 1};

int n;
void solve()
{
    cin >> n;
    vector<pair<int, int>> lp, rp;
    map<pair<int, int>, bool> st;
    int l = 2;
    int r = 2;
    for (int i = 1; i <= n; ++ i)
    {
        int r, c; cin >> r >> c;
        st[{c, r}] = true;
        if (c <= 0) lp.push_back({c, r});
        else rp.push_back({c, r});
    }

    if (lp.size())
    {
        for (int i = 0; i < lp.size(); ++ i)
        {
            if (lp[i].first == 0 && lp[i].second == 2)
            {
                if (!st[{-1, 1}])
                    l = min(l, 1ll);
                else
                    l = 0;
                continue;
            }
        }

        for (int i = 0; i < 3; ++ i)
        {
            int nx = lp[i].first + d[i];
            int ny = 3 - lp[i].second;
            if (st[{nx, ny}])
            {
                l = 0;
            }
            else l = min(l, 1ll);
        }
    }
    if (l == 2)
    {
        st[{0, 2}] = true;
    }
    if(st[{-1, 1}] == true && l == 1)
    {
		st[{0, 2}] = true;
	}

    if(rp.size()){
		for(int i = 0; i < rp.size(); i ++)
        {
			for(int j = 0; j < 3; j ++)
            {
				int nc = rp[i].first + d[j];
				int nr = 3 - rp[i].second;
				if(st[{nc, nr}])
                {
					r = 0;
				}
                else
                {
					r = min(r, 1ll);
				}
			}
		}
	}
    else
    {
		if(st[{0, 2}])
        {
			r = 1;
		}
	}
    int ans = l + r;
    cout << ans << endl;
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _; cin >> _;
    while (_ -- ) solve();
    return 0;
}