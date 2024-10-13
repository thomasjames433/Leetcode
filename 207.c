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