#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
typedef long long ll;
#define MOD 998244353
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    if(*max_element(all(a)) < n) {
        cout << 0 << endl;
        return 0;
    }
    ll l = 0, r = LLONG_MAX / 2;
    while(l + 1 < r) {
        ll m = (l + r) / 2, tmp = 0;
        for(int i = 0; i < n; i++) {
            ll x = a[i] + m;
            tmp += (x + 1) / (n + 1);
        }
        if(tmp <= m) {
            r = m;
        } else {
            l = m;
        }
    }
    cout << r << endl;
}