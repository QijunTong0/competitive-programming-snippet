vector<int> topo_sort(int n,vector<vector<int>> &Edge){
    stack<int> st;
    vector<int> ans;
    vector<int> h(n,0);
    for(auto v:Edge){
        for(auto u:v){
            h[u]++;
        }
    }
    for(int i=0;i<n;i++){
    if(h[i] == 0) st.push(i);
    }
  //stがなくなるまでループ
  while(st.size()) {
    //stの集合のから一つ取り出す
    int i = st.top(); st.pop();
    ans.push_back(i);
    for(auto j: Edge[i]) {
      //隣接する頂点の入次数をマイナス1
      h[j]--;
      //これによって入次数が0になればstに追加
      if(h[j] == 0) st.push(j);
    }
  }
  return ans;//ans.size()!=nならばDAGでない
}