int uniquePaths(int m, int n) {
    int **a=(int **)malloc(m*sizeof(int *));
    for(int i=0;i<m;i++){
        a[i]=(int*)calloc(n,sizeof(int));
    }
    a[0][0]=1;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(i>0) 
                a[i][j]+=a[i-1][j];
            if(j>0) 
                a[i][j]+=a[i][j-1];
                
        }
    }
    return a[m-1][n-1];
}