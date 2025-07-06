DFS
class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int size=graph.size();
        vector<int>colour(size,0);
        for(int i=0;i<size;i++){
            if(!dfs(graph,colour,i,-1))
                return false;
        }
        return true;
    }
    bool dfs(vector<vector<int>>&graph,vector<int>&colour,int cur,int prev){
        if(colour[cur]!=0){
            return true;
        }
        colour[cur]=-prev;
        for(auto it:graph[cur]){
            if(colour[it]==0){
                if(!dfs(graph,colour,it,colour[cur]))
                    return false;
            }
            else if(colour[it]==colour[cur])
                return false;
        }
        return true;
    }
};

int colour(int **graph,int n,int *gcs,int *visited,int i){
    int x=visited[i];
    for(int j=0;j<gcs[i];j++){
        if(!visited[graph[i][j]]){
            visited[graph[i][j]]=-x;
            int p=colour(graph,n,gcs,visited,graph[i][j]);
            if(!p)
                return 0;
        }
        else if(visited[graph[i][j]]==x)
            return 0;
    }
    return 1;
}


BFS
class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int size=graph.size();
        vector<int>colour(size,0);
        queue<int>q;
        for(int i=0;i<size;i++){
            if(colour[i]==0){
                q.push(i);
                colour[i]=1;
                while(!q.empty()){
                    int x=q.front();
                    auto v=graph[x];
                    q.pop();
                    for (auto it:v){
                        if(colour[it]==0){
                            colour[it]=-colour[x];
                            q.push(it);
                        }
                        else{
                            if(colour[x]==colour[it])
                                return false;
                        }
                    }

                }

            }
        }
        return true;
    }
    
};



bool isBipartite(int** graph, int n, int* gcs) {
    int*visited=(int*)calloc(n,sizeof(int));
    
    for(int i=0;i<n;i++){
        if(!visited[i]){
            visited[i]=1;
            int x=colour(graph,n,gcs,visited,i);
            if(!x)
            return 0;
        }
    }

    return 1;
}