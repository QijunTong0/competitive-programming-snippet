#define MAX_V 1000
struct edge {
    int to, cap, rev;
};
vector<edge> G[MAX_V];
vector<bool> used(MAX_V);
void add_edge(int from, int to, int cap) {
    // G[to].size()をrevに保持することでG[edge.to][edge.rev]で逆辺の構造体にアクセスできる
    G[from].push_back((edge){to, cap, (int)G[to].size()});
    G[to].push_back((edge){from, 0, (int)G[from].size() - 1});
}
int dfs(int v, int t, int f) {
    if(v == t) {
        return f;
    }
    used[v] = true;
    for(int i = 0; i < (int)G[v].size(); i++) {
        edge &e = G[v][i];
        if(!used[e.to] && e.cap > 0) {
            int d = dfs(e.to, t, min(f, e.cap));
            // d==0ならtにたどり着かない
            if(d > 0) {
                e.cap -= d;
                G[e.to][e.rev].cap += d;
                return d;
            }
        }
    }
    return 0;
}
int max_flow(int s, int t) {
    int flow = 0;
    for(;;) {
        for(int i = 0; i < MAX_V; i++) {
            used[i] = 0;
        }
        int f = dfs(s, t, MOD);
        if(f == 0) {
            return flow;
        }
        flow += f;
    }
}