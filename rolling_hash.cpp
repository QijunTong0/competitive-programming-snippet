#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
typedef long long ll;
#define MOD 1000000007
using namespace std;
long long extGCD(long long a, long long b, long long &x, long long &y) {
    if(b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    long long d = extGCD(b, a % b, y, x); // 再帰的に解く
    y -= a / b * x;
    return d;
}

// 負の数にも対応した mod (a = -11 とかでも OK)
inline long long mod(long long a, long long m) { return (a % m + m) % m; }

// 逆元計算 (ここでは a と m が互いに素であることが必要)
long long modinv(long long a, long long m) {
    long long x, y;
    extGCD(a, m, x, y);
    return mod(x, m); // 気持ち的には x % m だが、x が負かもしれないので
}
vector<int> rolling_hash(string s, string t) {
    vector<int> res;
    if(s.size() < t.size()) {
        return res;
    }
    int n = s.size();
    int m = t.size();
    ll hash = 0;
    ll master = 0;
    ll k = 1;
    ll base = 114514;
    ll inv = modinv(base, MOD);
    for(int i = 0; i < m; i++) {
        master = (master + (t[i] * k)) % MOD;
        hash = (hash + (s[i] * k)) % MOD;
        k = (k * base) % MOD;
    }
    if(hash == master) {
        res.push_back(0);
    }
    for(int i = 1; i + m - 1 < n; i++) {
        hash = (hash - (s[i - 1]) + MOD) % MOD;
        hash = (hash + s[i + m - 1] * k) % MOD;
        hash = (hash * inv) % MOD;
        if(hash == master) {
            res.push_back(i);
        }
    }
    return res;
}