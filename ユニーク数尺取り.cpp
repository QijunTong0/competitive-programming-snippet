
vector<int> unq_sk(vector<int> &a) {
    int n = a.size();
    int p = 0;
    vector<int> sk(n + 1);
    map<int, int> st;
    st[a[1]]++;
    sk[1] = 1;
    for(int i = 2; i <= n; i++) {
        if(st[a[p]]) {
            p = max(p, st[a[i]] + 1);
        }
        st[a[i]] = i;
        sk[i] = p;
    }
    sk.erase(sk.begin());
    return sk;
}