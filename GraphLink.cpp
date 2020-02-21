#include <iostream>
#include <set>
#include <string>
#include <vector>
using namespace std;
vector<set<int>> Links;
int Nodes[100000] = {};
vector<vector<int>> Edgelist;
int N, M;
void DFS(int n, int color) {
    Nodes[n] = color;
    for(auto next : Edgelist[n]) {
        if(Nodes[next] == 0)
            DFS(next, color);
    }
}
int main() {
    cin >> N >> M;
    Edgelist.resize(N);
    for(int i = 0; i < M; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        Edgelist[x - 1].push_back(y - 1);
        Edgelist[y - 1].push_back(x - 1);
    }
    int color = 1, i = 0;
    while(i < N) {
        if(Nodes[i] == 0) {
            DFS(i, color);
            color++;
        }
        i++;
    }
    cout << color - 1 << endl;
}