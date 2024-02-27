#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1010;
int V[N]; //能量
int M[N]; //黑暗力量
int W[N]; //狂暴因子
int f[N][N];

int main()
{
    int v, g, n; cin >> v >> g >> n;
    for (int i = 1; i <= n; ++ i)
    {
        cin >> V[i] >> M[i] >> W[i]; 
    }
    
    for (int i = 1; i <= n; ++ i)
    {
        for (int j = v; j >= M[i]; -- j)
        {
            for (int z = g; z >= W[i]; -- z)
            {
                f[j][z] = max(f[j][z], f[j - M[i]][z - W[i]] + V[i]);
            }
        }
    }
    
    cout << f[v][g] << endl;
    return 0;
}