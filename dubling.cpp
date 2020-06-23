vector<vector<int>> dub(60, vector<int>(n));
for(int i = 0; i < n; i++) {
    dub[0][i] = a[i];
}
for(int i = 1; i < 60; i++) {
    for(int j = 0; j < n; j++) {
        dub[i][j] = dub[i - 1][dub[i - 1][j]];
    }
}