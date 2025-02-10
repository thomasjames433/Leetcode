int uniquePathsWithObstacles(int** grid, int m, int* rowlen) {
    int n=rowlen[0];
    
    if (grid[0][0]==1 || grid[m-1][n-1]==1)
        return 0;
    grid[0][0]=-1;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j]!=1){
                if(i>0 && grid[i-1][j]!=1) 
                    grid[i][j]+=grid[i-1][j];
                if(j>0 && grid[i][j-1]!=1) 
                    grid[i][j]+=grid[i][j-1];
            }
        }
    }
    return -grid[m-1][n-1];
}