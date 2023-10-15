#define P pair<ll, ll>
vector<ll> Dijkstra_adjacencylist(int n, int s, vector<vector<pair<ll, ll>>> &Edge) {
    vector<bool> visited(n, false); //確定済み
    vector<ll> d(n, __LONG_LONG_MAX__ / 3);
    priority_queue<P, vector<P>, greater<P>> que; //頂点とsからの距離
    d[s] = 0;
    que.push(make_pair(0, s));
    while(!que.empty()) {
        auto now = que.top();
        que.pop();
        if(visited[now.second]) {
            continue;
        }
        visited[now.second] = true;
        for(auto e : Edge[now.second]) {
            if(visited[e.second])
                continue;
            if(d[e.second] > d[now.second] + e.first) {
                d[e.second] = d[now.second] + e.first;
                que.push(make_pair(d[e.second], e.second));
            }
        }
    }
    return d;
}
/*重みなし=幅優先探索
vector<int> d(n, -1);
queue<int> que;
que.push(u);
d[u] = 0;
while(!que.empty()) {
    int now = que.front();
    que.pop();
    for(auto next : edge[now]) {
        if(d[next] == -1) {
            d[next] = d[now] + 1;
            que.push(next);
        }
    }
}
*/
