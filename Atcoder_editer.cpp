#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
typedef long long ll;
#define MOD 1000000007
using namespace std;
int main() {
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(all(a));
    ll l = LLONG_MIN / 2, r = LLONG_MAX / 2;
    while(l + 1 < r) {
        ll tmp = 0, t2 = 0;
        ll x = (l + r) / 2;
        for(int i = 0; i < n; i++) {
            t2 += (a[i] * a[i] <= x);
            if(a[i] > 0) {
                int left = -1, right = n;
                while(left + 1 < right) {
                    int m = (left + right) / 2;
                    if(a[m] * a[i] <= x) {
                        left = m;
                    } else {
                        right = m;
                    }
                }
                tmp += right;
            }
            if(a[i] == 0) {
                if(0 <= x) {
                    tmp += n;
                }
            }
            if(a[i] < 0) {
                int left = -1, right = n;
                while(left + 1 < right) {
                    int m = (left + right) / 2;
                    if(a[m] * a[i] <= x) {
                        right = m;
                    } else {
                        left = m;
                    }
                }
                tmp += n - right;
            }
        }
        tmp -= t2;
        tmp /= 2;
        if(tmp < k) {
            l = x;
        } else {
            r = x;
        }
    }
    cout << r << endl;
}