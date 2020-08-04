vector<int> d;
int dfs(int now, int prev, vector<vector<int>> &edge) {
    if(d[now] != -1) {
        return d[now];
    }
    int tmp = 0;
    for(auto next : edge[now]) {
        if(next != prev) {
            tmp += dfs(next, now, edge);
        }
    }
    return d[now] = tmp + 1;
}