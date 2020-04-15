//部分木の個数を数える木DP,count配列は-1で初期化する
ll count_tree(ll now, ll prev, vector<vector<ll>> &edge, vector<ll> &count) {
    if(count[now] != -1) {
        return count[now];
    } else {
        ll tmp = 0;
        for(auto next : edge[now]) {
            if(next != prev) {
                tmp += count_tree(next, now, edge, count) + 1;
            }
        }
        count[now] = tmp;
        return tmp;
    }
}