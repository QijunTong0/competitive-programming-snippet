//0-index
//dp[i][j]:i番目以上で荷物を重さがj以下で入れられる最大値
for (int j = 0; j <= t; j++)
{
  dp[n][j] = 0;
}
for (int i = n - 1; i >= 0; i--)
{
  for (int j = 0; j <= t; j++)
  {
    if (j < w[i])
      dp[i][j] = dp[i + 1][j];
    else
      dp[i][j] = max(dp[i + 1][j], dp[i + 1][j - w[i]] + v[i]);
  }
}
//dp[i][j]:i番目までの荷物を重さがj以下で入れられる最大値
for (int j = 0; j <= t; j++)
  {
    if(w[0]>j){
      dp[0][j] = 0;
    }
    else{
    dp[0][j] = v[0];
    }
  }
  for (int i = 0; i < n-1; i++)
  {
    for (int j = 0; j <= t; j++)
    {
      if (j-w[i+1]<0)
        dp[i + 1][j] = dp[i][j];
      else
        dp[i + 1][j] = max(dp[i][j], dp[i][j-w[i+1]] + v[i+1]);
    }
  }