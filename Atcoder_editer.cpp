#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
typedef long long ll;
#define MOD 998244353
using namespace std;
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
int main() {
    ll n, m;
    cin >> n >> m;
    vector<vector<int>> edge(n);
    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }
    vector<vector<int>> dp(2, vector<int>(n, -1));
    dp[0][0] = 1;
    dfs(0, edge, dp);
    ll ans = 0;
    for(int i = 0; i < n; i++) {
        if(dp[0][i] == 1 && dp[1][i] == 1) {
            cout << n * (n - 1) / 2 - m << endl;
            return 0;
        }
    }
    ll s = count(all(dp[0]), 1);
    ll t = count(all(dp[1]), 1);
    cout << s * t - m << endl;
}