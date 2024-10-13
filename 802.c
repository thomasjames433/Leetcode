/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int dfs(int i,int **graph,int *gcs,int *visited,int n){
    printf("%d ",i);
    visited[i]=1;
    int x=gcs[i];
    for(int j=0;j<x;j++){
        int y=graph[i][j];
        if(visited[y]==1)
            return 0;
        else if(!visited[y]){
            int x=dfs(y,graph,gcs,visited,n);
            
            if(!x)
                return 0;
        }
    }
    visited[i]=2;
    return 1;
}

int* eventualSafeNodes(int** graph, int n, int* gcs, int* rs) {
    
    int *visited=(int*)calloc(n,sizeof(int));
    for(int i=0;i<n;i++){
        if(!visited[i])
            dfs(i,graph,gcs,visited,n);
    }
    *rs=0;
    int *ret=(int*)calloc(n,sizeof(int));
    for(int i=0;i<n;i++){
        if(visited[i]==2){
            ret[(*rs)++]=i;
        }
    }
    return ret;
}