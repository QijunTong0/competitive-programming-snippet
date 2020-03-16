vector<vector<int>> dp(2, vector<int>(n, -1));
dp[0][0] = 1;
void dfs(int now, vector<vector<int>> &edge, vector<vector<int>> &dp) {
    for(auto next : edge[now]) {
        bool flag = false;
        if(dp[0][next] == -1 && dp[1][now] == 1) {
            dp[0][next] = 1;
            flag = true;
        }
        if(dp[1][next] == -1 && dp[0][now] == 1) {
            dp[1][next] = 1;
            flag = true;
        }
        if(flag) {
            dfs(next, edge, dp);
        }
    }
}