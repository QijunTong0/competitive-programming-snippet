template <typename T> bool chmin(T &a, const T &b) {
    if(a > b) {
        a = b; // aをbで更新
        return true;
    }
    return false;
}
vector<vector<ll>> TSP(vector<vector<ll>> &cost) {
    ll n = cost.size();
    ll v_size = (1 << n);
    vector<vector<ll>> dp(v_size, vector<ll>(n, LLONG_MAX / 3));
    dp[1][0] = 0; //グラフの形状によっては初期化する部分が変わるかもしれない
    for(int s = 1; s < v_size; s++) {
        for(int i = 0; i < n; i++) {
            if(((s >> i) & 1) == 0) {
                continue;
            }
            for(int j = 0; j < n; j++) {
                if(cost[i][j] != -1 &&
                   ((s >> j & 1) ==
                    0)) { //ハミルトンパスである必要がない場合はこのif文の条件を変える
                    chmin(dp[s | (1 << j)][j], dp[s][i] + cost[i][j]);
                }
            }
        }
    }
    return dp;
}
// ref:http://tutuz.hateblo.jp/entry/2018/07/17/021422