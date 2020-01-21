#include <iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<cmath>
#include<set>
#include <iomanip>
typedef long long ll;
using namespace std;
#define MOD 998244353
int main(){
    int numCourses=1;
    vector<vector<int>> prerequisites;
    vector<vector<int>> graph(numCourses);
        vector<int> dig(numCourses,0);
        for(vector<int> edge:prerequisites){
            graph[edge[1]].push_back(edge[0]);
            dig[edge[0]]++;
        }
        vector<bool> done(numCourses,0);
        vector<int> S;
        for(int i=0;i<numCourses;i++){
            if(dig[i]==0)S.push_back(i);
        }
        if(S.empty()){
            cout<<0<<endl;
            return 0;
        }
        while(!S.empty()){
            int tmp=S.back();
            S.pop_back();
            bool flag=false;
            if(graph[tmp].empty())continue;
            for(auto elem:graph[tmp]){
                dig[elem]--;
                if(dig[elem]==0){
                    S.push_back(elem);
                }
            }
        }
        return *max_element(dig.begin(),dig.end())==0
}