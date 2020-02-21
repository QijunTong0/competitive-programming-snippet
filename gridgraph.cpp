vector<vector<pair<ll, ll>>> gridgraph(int h, int w, vector<vector<char>> s)
{
    vector<vector<pair<ll, ll>>> edge(h * w);
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            if (s[i][j] == '#')
            {
                continue;
            }
            if (i - 1 >= 0 && s[i - 1][j] == '.')
            {
                edge[i * w + j].push_back(make_pair(1, (i - 1) * w + j));
            }
            if (i + 1 < h && s[i + 1][j] == '.')
            {
                edge[i * w + j].push_back(make_pair(1, (i + 1) * w + j));
            }
            if (j + 1 < w && s[i][j + 1] == '.')
            {
                edge[i * w + j].push_back(make_pair(1, i * w + j + 1));
            }
            if (j - 1 >= 0 && s[i][j - 1] == '.')
            {
                edge[i * w + j].push_back(make_pair(1, i * w + j - 1));
            }
        }
    }
    return edge;
}