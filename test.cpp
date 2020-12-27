#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
typedef long long ll;
#define MOD 1000000000
using namespace std;
pair<ll, vector<ll>> inv_num(vector<ll> &v) {
    ll n = v.size();
    vector<ll> bkt(21, 0);
    ll res = 0;
    for(int j = 0; j < n; j++) {
        for(int i = v[j] + 1; i < 21; i++) {
            res += bkt[i];
            res %= MOD;
        }
        bkt[v[j]]++;
    }
    return {res, bkt};
}

int main() {
    vector<ll> v = {1, 3, 2};
    auto res = inv_num(v);
    cout << res.first << endl;
}