class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        int extra=0;
        vector<vector<int>>graph(n);
        for(auto it:connections){
            graph[it[0]].push_back(it[1]);
            graph[it[1]].push_back(it[0]);
        }
        vector<int>visited(n,0);
        int c=0;
        for(int i=0;i<n;i++){
            if(visited[i]>0)
                continue;
            visited[i]=1;
            dfs(graph,visited,extra,i,-1);
            c++;
        }
        cout<< extra<<" "<< c<<" ";
        if(extra<c-1)
            return -1;
        return c-1;
    }
    void dfs(vector<vector<int>>&graph, vector<int>&visited, int &extra, int i,int prev){
        for(auto it:graph[i]){
            if(visited[it]==2)
                continue;
            if(visited[it]==0){
                visited[it]=1;
                dfs(graph,visited,extra,it,i);
            }
            else{
                if(it!=prev){
                    cout<<it<<" "<<prev<<"\n";
                    extra++;
                
                }
            }
        }
        visited[i]=2;
    }
};
