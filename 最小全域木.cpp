struct UnionFind {
    vector<int> data;

    UnionFind(int sz) { data.assign(sz, -1); }

    bool unite(int x, int y) {
        x = find(x), y = find(y);
        if(x == y)
            return (false);
        if(data[x] > data[y])
            swap(x, y);
        data[x] += data[y];
        data[y] = x;
        return (true);
    }

    int find(int k) {
        if(data[k] < 0)
            return (k);
        return (data[k] = find(data[k]));
    }
    bool isSame(int x, int y) { return find(x) == find(y); }
    ll size(int k) { return (-data[find(k)]); }
};
ll Kruskal(vector<vector<pair<ll, pair<int, int>>>> edge) {
    int n = edge.size();
    priority_queue<pair<ll, pair<int, int>>> que;
    for(int i = 0; i < n; i++) {
        for(auto elem : edge[i]) {
            que.push(elem);
        }
    }
    UnionFind uf(n);
    ll w = 0;
    while(!que.empty()) {
        auto e = que.top();
        que.pop();
        if(!uf.isSame(e.second.first, e.second.second)) {
            uf.unite(e.second.first, e.second.second);
            w -= e.first;
        }
    }
    return w;
}
/*
int main() {
    int n, m;
    cin >> n >> m;
    priority_queue<pair<ll, pair<int, int>>> que;
    for(int i = 0; i < m; i++) {
        int a, b;
        double c;
        cin >> a >> b >> c;
        a--;
        b--;
        que.push(make_pair(-c, make_pair(a, b)));
    }
    UnionFind uf(n);
    ll w = 0;
    while(!que.empty()) {
        auto e = que.top();
        que.pop();
        if(!uf.isSame(e.second.first, e.second.second)) {
            uf.unite(e.second.first, e.second.second);
            w -= e.first;
        }
    }
    cout << w << endl;
}
*/
