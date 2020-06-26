vector<int> tobit(ll n, int keta) {
    vector<int> res(keta, 0);
    for(int i = 0; i < keta; i++) {
        res[i] = n % 2;
        n /= 2;
    }
    return res;
}