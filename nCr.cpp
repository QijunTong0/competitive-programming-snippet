vector<vector<ll>> C(2005,vector<ll>(2005,0));
    C[0][0]=1;C[1][0]=1;
    for(int i=1;i<=2004;i++){
        for(int j=0;j<=i;j++){
            C[i][j]=(C[i-1][j-1]+C[i-1][j])%p;
        }
    }