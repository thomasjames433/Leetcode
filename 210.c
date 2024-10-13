/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int dfs(int i,int **a,int *visited,int n,int *ret,int*pos){
    visited[i]=1;
    for(int j=0;j<n;j++){
        if(a[i][j] && visited[j]==1)
            return 0;
        else if(a[i][j] && !visited[j]){
            int x=dfs(j,a,visited,n,ret,pos);
            if(!x)
                return 0;
        }
    }
    visited[i]=2;
    ret[(*pos)--]=i;
    return 1;
}

int* findOrder(int n, int** p, int ps, int* prerequisitesColSize, int* rs) {
    int *ret=(int*)malloc(n*sizeof(int));
    *(rs)=0;
    int **a=(int**)malloc(n*sizeof(int*));
    for(int i=0;i<n;i++)
        a[i]=(int*)calloc(n,sizeof(int));
    for(int i=0;i<ps;i++){
        int x=p[i][0];
        int y=p[i][1];
        if(a[x][y])
            return ret;
        a[y][x]=1;
    }
    int *visited=(int*)calloc(n,sizeof(int));
    int *pos=n-1;
    for(int i=0;i<n;i++){
        if(!visited[i]){
            int x=dfs(i,a,visited,n,ret,&pos);
            if(!x)
                return ret;
        }
    }
    *rs=n;
    return ret;
}