vector<ll> Dijkstra_list(int n, int s, vector<vector<pair<ll, ll>>> &Edge) {
    vector<bool> visited(n, false); //確定済み
<<<<<<< HEAD
    vector<ll> d(n, __LONG_LONG_MAX__ / 3);
=======
    vector<ll> d(n, __LONG_LONG_MAX__);
>>>>>>> 6c2d2baf78a7d119dc5cc3c9bfcd5fec4b435c5b
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>>
        que; //頂点とsからの距離
    d[s] = 0;
    que.push(make_pair(0, s));
    while(!que.empty()) {
        auto now = que.top();
        que.pop();
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
<<<<<<< HEAD
/*重みなし=幅優先探索
=======
/*重みなし
>>>>>>> 6c2d2baf78a7d119dc5cc3c9bfcd5fec4b435c5b
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