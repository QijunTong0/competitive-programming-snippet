class lca {
  public:
    int n, segn;
    std::vector<int> path, depth, in_order;
    std::vector<std::pair<int, int>> dat;
    const std::pair<int, int> INF = std::make_pair(1000000000, 1000000000);

    lca(vector<vector<int>> &g, int root)
        : n(g.size()), path(n * 2 - 1), depth(n * 2 - 1), in_order(n) {
        int k = 0;
        dfs(g, root, -1, 0, k);
        for(segn = 1; segn < n * 2 - 1; segn <<= 1)
            ;
        dat.assign(segn * 2, INF);
        for(int i = 0; i < (int)depth.size(); ++i)
            dat[segn + i] = std::make_pair(depth[i], i);
        for(int i = segn - 1; i >= 1; --i)
            dat[i] = min(dat[i * 2], dat[i * 2 + 1]);
    }

    int get(int u, int v) const {
        int l = std::min(in_order[u], in_order[v]);
        int r = std::max(in_order[u], in_order[v]) + 1;
        return path[range_min(1, segn, l, r).second];
    }

    void dfs(vector<vector<int>> &g, int v, int p, int d, int &k) {
        in_order[v] = k;
        path[k] = v;
        depth[k++] = d;
        for(auto &e : g[v]) {
            if(e != p) {
                dfs(g, e, v, d + 1, k);
                path[k] = v;
                depth[k++] = d;
            }
        }
    }

    std::pair<int, int> range_min(int v, int w, int l, int r) const {
        if(r <= l || w == 0)
            return INF;
        if(r - l == w)
            return dat[v];
        int m = w / 2;
        auto rmin = range_min(v * 2, m, l, std::min(r, m));
        auto lmin = range_min(v * 2 + 1, m, std::max(0, l - m), r - m);
        return min(rmin, lmin);
    }
};