vector<int> tour;
void dfs(int now, int prev, vector<vector<int>> &edge) {
    tour.push_back(now);
    for(auto next : edge[now]) {
        if(next != prev) {
            dfs(next, now, edge);
            tour.push_back(now);
        }
    }
}
