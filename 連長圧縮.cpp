vector<pair<char, int>> compress(string s) {
    vector<pair<char, int>> res;
    for(int i = 0; i < s.size(); i++) {
        int p = 0;
        while(i + p < s.size() && s[i] == s[i + p]) {
            p++;
        }
        res.push_back(make_pair(s[i], p));
        i += p - 1;
    }
    return res;
}