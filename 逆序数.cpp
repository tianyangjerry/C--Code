#include <bits/stdc++.h>
#define endl '\n'
#define int long long

using namespace std;

const int N = 10100;
int t[N];
int n;
struct node{
	int pos, val;
} a[N];

int lowbit(int x)
{
	return x & -x;
}

void add(int k, int x)
{
	for (int i = k; i <= n; i += lowbit(i)) t[i] += x;
}

int query(int l)
{
	int res = 0;
	for (int i = l; i > 0; i -= lowbit(i)) res += t[i];
	return res;
}

void solve()
{
    cin >> n;
	for (int i = 1; i <= n; ++ i)
	{
		cin >> a[i].val;
		a[i].pos = i;		
	}
	sort(a + 1, a + n + 1, [](node a, node b){
        if (a.val == b.val) return a.pos < b.pos;
        return a.val > b.val;
    });

    int ans = 0;
    for (int i = 1; i <= n; ++ i)
    {
        ans += query(a[i].pos - 1);
        add(a[i].pos, 1);
    }
    cout << ans << endl;
}

signed main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int _ = 1;
	while (_ -- ) solve();
	return 0;
}