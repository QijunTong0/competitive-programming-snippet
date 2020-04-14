//数列の区間[a,b)の種類数についてlognで答える
//クエリを先読みしてbでソートする必要がある
int main() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    map<ll, ll> mp;
    segment_tree<int> seg(
        n + 1, [](int a, int b) { return a + b; }, 0);
    for(int j = 0; j <= n; j++) {
        if(mp.find(rui[j]) != mp.end()) {
            seg.update(mp[rui[j]], 0);
        }
        mp[rui[j]] = j;
        seg.update(j, 1);
        int l = -1, r = j;
        while(l + 1 < r) {
            int m = (l + r) / 2;
            if(seg.query(m, j + 1) < j + 1 - m) {
                l = m;
            } else {
                r = m;
            }
        }
    }
}