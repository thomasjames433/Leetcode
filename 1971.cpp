class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<int>visited(n,0);
        vector<vector<int>>graph(n);
        for(int i=0;i<edges.size();i++){
            graph[edges[i][1]].push_back(edges[i][0]);    
            graph[edges[i][0]].push_back(edges[i][1]);
        }
        return dfs(visited,graph,source,destination);
    }

    bool dfs(vector<int>&visited,vector<vector<int>>&edges,int source,int destination){
        if(source ==destination)
            return true;
        vector<int>edge=edges[source];
        visited[source]=1;
        for(auto it:edge){
            if(visited[it]==0){
                if(dfs(visited,edges,it,destination))
                    return true;
            }
        }
        return false;
    }
};