#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1005;
const int INF = 0x3f3f3f3f;
typedef pair<int, int> pii;

vector<pii> edges[MAXN]; // 存储边的信息，first是目标节点，second是权重
int dist[MAXN]; // 存储源节点到每个节点的最短距离
bool visited[MAXN]; // 标记节点是否已经访问

void dijkstra(int start) {
    priority_queue<pii, vector<pii>, greater<pii>> pq; // 优先队列，按照距离从小到大排序
    dist[start] = 0;
    pq.push(make_pair(0, start));

    while(!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        if(visited[u]) continue;
        visited[u] = true;
        for(auto edge : edges[u]) {
            int v = edge.first, w = edge.second;
            if(dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push(make_pair(dist[v], v));
            }
        }
    }
}

int main() {
    int n, m, start;
    cin >> n >> m >> start;
    for(int i = 1; i <= n; i++) dist[i] = INF;
    memset(visited, false, sizeof(visited));
    for(int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges[u].push_back(make_pair(v, w));
    }
    dijkstra(start);
    for(int i = 1; i <= n; i++) {
        if(dist[i] == INF) cout << "INF" << endl;
        else cout << dist[i] << endl;
    }
    return 0;
}