int min(int a,int b){
    if(a==-1 && b==-1)
        return 0;
    else if(a==-1)
        return b;
    else if(b==-1)
        return a;
    else if(a<b)
        return a;
    return b;
}

int minPathSum(int** grid, int m, int* gridColSize) {
    int n=gridColSize[0];
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            int x=-1;int y=-1;
            if(i>0) 
                x=grid[i-1][j];
            if(j>0)
                y=grid[i][j-1];
            grid[i][j]+=min(x,y);

        }
    }
    return grid[m-1][n-1];
}