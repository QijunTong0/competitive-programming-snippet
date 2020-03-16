// d[i][j]をLLONG_MAXで取るとオーバーフローするので注意
ll d[200][200];
ll ans = LLONG_MAX; // 9223372036854775807
void warshall_floyd(int n) {
    for(int i = 0; i < n; i++) {         // 経由する頂点
        for(int j = 0; j < n; j++) {     // 開始頂点
            for(int k = 0; k < n; k++) { // 終端
                d[j][k] = min(d[j][k], d[j][i] + d[i][k]);
            }
        }
    }
}
