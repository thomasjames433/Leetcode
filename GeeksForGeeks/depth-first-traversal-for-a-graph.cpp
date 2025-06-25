class Solution {
  public:
    vector<int> dfs(vector<vector<int>>& adj) {
        // Code here
        vector<int>ret;
        vector<int>visited(adj.size(),0);
        dfs(adj,ret,visited,0);
        return ret;
    }
    void dfs(vector<vector<int>>&adj,vector<int>&ret,vector<int>&visited,int cur){
        auto v=adj[cur];
        ret.push_back(cur);
        visited[cur]=1;
        for(auto it:v){
            if(!visited[it]){
                dfs(adj,ret,visited,it);
            }
        }
        return;
    }
};