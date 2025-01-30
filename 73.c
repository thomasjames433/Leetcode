void setZeroes(int** matrix, int m, int* matrixColSize) {
    int n=matrixColSize[0];
    int* row=(int *)calloc(m,sizeof(int));
    int* col=(int *)calloc(n,sizeof(int));

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(matrix[i][j]==0){
                row[i]=1;
                col[j]=1;
            }
        }
    }
    for(int i=0;i<m;i++){
        if(row[i]==1)
            matrix[i]=(int *)calloc(n,sizeof(int));
    }
    
    for(int j=0;j<n;j++){
        if(col[j]==1){
            
            for(int i=0;i<m;i++){
                    matrix[i][j]=0;
            }
        }
    }
    return;
}