#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <set>
#include <stack>
#include <string>
#include <vector>
typedef long long ll;
using namespace std;
#define MOD 998244353
int main() {
    int N, M;
    cin >> N >> M;
    vector<ll> a(M);
    vector<ll> C(M, 0);
    for(int i = 0; i < M; i++) {
        cin >> a[i];
        int b;
        cin >> b;
        for(int j = 0; j < b; j++) {
            ll tmp;
            cin >> tmp;
            tmp--;
            C[i] += 1 << tmp;
        }
    }
    vector<vector<ll>> dp(M + 1, vector<ll>(5000, 999999999));
    dp[0][0] = 0;
    for(int i = 0; i < M; i++) {
        for(int j = 0; j < (1 << N); j++) {
            dp[i + 1][j | C[i]] = min(dp[i][j | C[i]], dp[i][j] + a[i]);
        }
    }
    cout << dp[M][1 << N - 1] << endl;
}