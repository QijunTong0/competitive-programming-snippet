// mp[a[i]]で圧縮後の座標
map<ll, ll> zatu(vector<ll> a) {
    map<ll, ll> mp;
    for(int i = 0; i < a.size(); i++) {
        mp[a[i]] = 0;
    }
    int k = 0;
    for(auto &e : mp) { // autoは&をつけないと代入されない
        e.second = k;
        k++;
    }
    return mp;
}