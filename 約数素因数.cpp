vector<ll> divisor(ll n) {
    vector<ll> ret;
    for(ll i = 1; i * i <= n; i++) {
        if(n % i == 0) {
            ret.push_back(i);
            if(i * i != n)
                ret.push_back(n / i);
        }
    }
    sort(begin(ret), end(ret));
    return (ret);
}
map<ll, ll> prime_factor(ll n) {
    map<ll, ll> ret;
    for(ll i = 2; i * i <= n; i++) {
        while(n % i == 0) {
            ret[i]++;
            n /= i;
        }
    }
    if(n != 1)
        ret[n] = 1;
    return ret;
}
ll modpow(ll a, ll n, ll mod = MOD) {
    ll res = 1;
    while(n > 0) {
        if(n & 1)
            res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}