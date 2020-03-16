//直径:達成する頂点の組の番号
vector<int> TreeDiag(int n, vector<vector<int>> &edge) {
    vector<int> d(n, -1);
    queue<int> que;
    que.push(0);
    d[0] = 0;
    while(!que.empty()) {
        int now = que.front();
        que.pop();
        for(auto next : edge[now]) {
            if(d[next] == -1) {
                d[next] = d[now] + 1;
                que.push(next);
            }
        }
    }
    int eve = max_element(all(d)) - d.begin();
    d.assign(n, -1);
    que.push(eve);
    d[eve] = 0;
    while(!que.empty()) {
        int now = que.front();
        que.pop();
        for(auto next : edge[now]) {
            if(d[next] == -1) {
                d[next] = d[now] + 1;
                que.push(next);
            }
        }
    }
    vector<int> res(3, 0);
    res[0] = *max_element(all(d));
    res[1] = eve;
    res[2] = max_element(all(d)) - d.begin();
    return res;
}