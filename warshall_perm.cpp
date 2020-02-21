#include <iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<set>
typedef long long ll;
using namespace std;
ll D[200][200];
ll ans=LLONG_MAX;//9223372036854775807
int R;
void warshall_floyd(int n) { 
  for (int i = 0; i < n; i++) {     // 経由する頂点
    for (int j = 0; j < n; j++){    // 開始頂点
      for (int k = 0; k < n; k++) { // 終端
        D[j][k] = min(D[j][k], D[j][i] + D[i][k]);
      }
    }
  }
}
void Perm(vector<int> vc,vector<int> perm={}){
    if(perm.size()==vc.size()){
        //順列生成後に行いたい処理
        ll tmp=0;
        for(int i=1;i<R;i++){
            tmp+=D[perm[i-1]][perm[i]];
        }
        ans=min(ans,tmp);
    }
    else{
        for(int i=0;i<vc.size();i++){
            if(count(perm.begin(),perm.end(),vc[i])==0){
                perm.push_back(vc[i]);
                Perm(vc,perm);
                perm.pop_back();
            }
        }
    }
}
int main(){
    int N,M;
    cin>>N>>M>>R;
    vector<int> machi(R);
    for(int i=0;i<R;i++){
        cin>>machi[i];
        machi[i]--;
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
        D[i][j]=LLONG_MAX/100;
        }
    }
    int a,b;
    for(int i=0;i<M;i++){
        cin>>a>>b;
        cin>>D[a-1][b-1];
        D[b-1][a-1]=D[a-1][b-1];
    }
    warshall_floyd(N);
    Perm(machi);
    cout<<ans<<endl;
    }
