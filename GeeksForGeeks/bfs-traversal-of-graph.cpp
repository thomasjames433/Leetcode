#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfs(vector<vector<int>> &adj) {
        // Code here
        vector<int>ret;
        vector<int>visited(adj.size(),0);
        queue<int>q;
        q.push(0);
        visited[0]=1;
        
        while(!q.empty()){
            int x=q.front();
            ret.push_back(x);
            q.pop();
            auto v=adj[x];
            for(auto it :v){
                if(!visited[it]){
                    q.push(it);
                    visited[it]=1;
                }
            }
        }
        return ret;
    }
};

int main(){
    int n;
    cin >>n;
    vector<vector<int>>first(n);

    for (int i=0;i<n;i++){
        int x;
        cin>>x;
        while(x!=-1){
            first[i].push_back(x);
            cin>>x;
        }
    }
    Solution sol;

    auto ret=sol.bfs(first);
    for(auto it:ret)
        cout<<it<<" ";

}