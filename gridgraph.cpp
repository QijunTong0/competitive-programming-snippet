//全部つなぐパターン重みなし
vector<vector<int>> gridgraph(int h, int w, vector<string> s) {
    vector<vector<int>> edge(h * w);
    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++) {
            if(i - 1 >= 0) {
                edge[i * w + j].push_back((i - 1) * w + j);
            }
            if(i + 1 < h) {
                edge[i * w + j].push_back((i + 1) * w + j);
            }
            if(j + 1 < w) {
                edge[i * w + j].push_back(i * w + j + 1);
            }
            if(j - 1 >= 0) {
                edge[i * w + j].push_back(i * w + j - 1);
            }
        }
    }
    return edge;
}
//.の点のみを長さ1の辺でつなぐパターン
vector<vector<pair<ll, ll>>> gridgraph1(int h, int w, vector<string> s) {
    vector<vector<pair<ll, ll>>> edge(h * w);
    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++) {
            if(s[i][j] == '#') {
                continue;
            }
            if(i - 1 >= 0 && s[i - 1][j] == '.') {
                edge[i * w + j].push_back(make_pair(1, (i - 1) * w + j));
            }
            if(i + 1 < h && s[i + 1][j] == '.') {
                edge[i * w + j].push_back(make_pair(1, (i + 1) * w + j));
            }
            if(j + 1 < w && s[i][j + 1] == '.') {
                edge[i * w + j].push_back(make_pair(1, i * w + j + 1));
            }
            if(j - 1 >= 0 && s[i][j - 1] == '.') {
                edge[i * w + j].push_back(make_pair(1, i * w + j - 1));
            }
        }
    }
    return edge;
}
//異なるグリッドを長さ1で繋ぎ、それ以外を0でつなぐパターン
vector<vector<pair<ll, ll>>> gridgraph2(int h, int w, vector<string> s) {
    vector<vector<pair<ll, ll>>> edge(h * w);
    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++) {
            if(i + 1 < h) {
                edge[i * w + j].push_back(
                    make_pair(s[i][j] != s[i + 1][j], (i + 1) * w + j));
            }
            if(j + 1 < w) {
                edge[i * w + j].push_back(
                    make_pair(s[i][j] != s[i][j + 1], i * w + j + 1));
            }
        }
    }
    return edge;
}
//重みなしver
vector<vector<int>> gridgraph(int h, int w, vector<string> s) {
    vector<vector<int>> edge(h * w);
    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++) {
            if(s[i][j] == '#') {
                continue;
            }
            if(i - 1 >= 0 && s[i - 1][j] == '.') {
                edge[i * w + j].push_back((i - 1) * w + j);
            }
            if(i + 1 < h && s[i + 1][j] == '.') {
                edge[i * w + j].push_back((i + 1) * w + j);
            }
            if(j + 1 < w && s[i][j + 1] == '.') {
                edge[i * w + j].push_back(i * w + j + 1);
            }
            if(j - 1 >= 0 && s[i][j - 1] == '.') {
                edge[i * w + j].push_back(i * w + j - 1);
            }
        }
    }
    return edge;
}