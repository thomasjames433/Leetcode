DFS

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>pre(numCourses);
        for (auto it:prerequisites)
            pre[it[0]].push_back(it[1]);
        vector<int>visited(numCourses,0);
        for(int i=0;i<numCourses;i++){
            if(!visited[i]){
                if(!dfs(visited,pre,i))
                    return false;
            }
        }
        return true;
    }
    bool dfs(vector<int>&visited,vector<vector<int>>&pre,int cur){
        
        visited[cur]=1;
        for(auto it :pre[cur]){
            if(visited[it]==1)
                return false;
            if(visited[it]==0)
                if (!dfs(visited,pre, it))
                    return false;
        }
        visited[cur]=2;
        return true;
    }

};

int dfs(int i,int **a,int *visited,int n){
    visited[i]=1;
    for(int j=0;j<n;j++){
        if(a[i][j] && visited[j]==1)
            return 0;
        else if(a[i][j] && !visited[j]){
            int x=dfs(j,a,visited,n);
            if(!x)
                return 0;
        }
    }
    visited[i]=2;
    return 1;
}






BFS

class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& pre) {
        
        vector<vector<int>>of(n);
        vector<int>in(n,0);
        for(auto it:pre){
            int x=it[1];
            of[x].push_back(it[0]);
            in[it[0]]++;
        }
        queue<int>q;
        int c=n;
        for(int i=0;i<n;i++){
            if(in[i]==0){
                q.push(i);
                c--;
            }
        }
        while(!q.empty()){
            if(c==0)
                return true;
            int x=q.front();
            q.pop();
            for(auto it:of[x]){
                in[it]--;
                if(in[it]==0){
                    q.push(it);
                    c--;
                }
            }
        }
        if(c==0)
            return true;
        return false;
    }
};







bool canFinish(int n, int** p, int psize, int* prerequisitesColSize) {
    int **a=(int**)malloc(n*sizeof(int*));;
    for(int i=0;i<n;i++)
        a[i]=(int*)calloc(n,sizeof(int));
    for(int i=0;i<psize;i++){
        int x=p[i][0];
        int y=p[i][1];
        if(a[y][x])
            return 0;
        a[x][y]=1;
    }
    int *visited=(int*)calloc(n,sizeof(int));
    int x=1;
    for(int i=0;i<n;i++){
        if(!visited[i])
            x=dfs(i,a,visited,n);
        if(!x)
            return 0;
    }
    return 1;
}