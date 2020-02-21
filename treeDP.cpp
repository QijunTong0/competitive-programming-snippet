vector<int> d, par;
int dfs(int now, int prev, vector<vector<int>> &edge) {
    par[now] = prev;
    if(d[now] != -1) {
        return d[now];
    }
    int tmp = 0;
    for(auto next : edge[now]) {
        if(next != prev) {
            tmp += dfs(next, now, edge);
        }
    }
    d[now] = tmp + 1;
    return tmp + 1;
}