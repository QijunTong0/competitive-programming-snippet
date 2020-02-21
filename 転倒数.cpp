// 各項の順序を保ったまま最小値0,最大値size()-1以下にする
template <typename T>
vector<T> simplify(vector<T>& a) {
    int n = a.size();
    vector<T> b = a;
    sort(b.begin(), b.end());
    vector<T> res(n);
    for (int i = 0; i < n; i++)
        res[i] = lower_bound(b.begin(), b.end(), a[i]) - b.begin();
    return res;
}
// 転倒数を計算
// depend:segment_tree
template <typename T>
long long inversion_number(vector<T>& a) {
    using lint = long long int;
    int n = a.size();
    vector<T> b = simplify(a);
    segment_tree<lint> count(
        n, [](lint a, lint b) { return a + b; }, 0);
    lint res = 0;
    for (int i = 0; i < n; i++) {
        res += count.query(b[i] + 1, n);
        count.update(b[i], count[b[i]] + 1);
    }
    return res;
}