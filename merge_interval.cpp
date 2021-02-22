//重なる区間をマージしてdisjointな区間を返す
vector<int> solve(vector<vector<int>> &kukan) {
    int m = kukan.size();
    UnionFind uf(m);
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < m; j++) {
            if(kukan[i][0] > kukan[j][1] || kukan[i][1] < kukan[j][0]) {
                continue;
            }
            uf.unite(i, j);
        }
    }
    map<int, pair<int, int>> grp;
    for(int i = 0; i < m; i++) {
        if(grp.find(uf.find(i)) == grp.end()) {
            grp[uf.find(i)] = {kukan[i][0], kukan[i][1]};
        } else {
            grp[uf.find(i)].first = min(grp[uf.find(i)].first, kukan[i][0]);
            grp[uf.find(i)].second = max(grp[uf.find(i)].second, kukan[i][1]);
        }
    }
    vector<pair<int, int>> ans;
    for(auto e : grp) {
        ans.push_back(e.second);
    }
    sort(ans.begin(), ans.end());
    return ans;
}