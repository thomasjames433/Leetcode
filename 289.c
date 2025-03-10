int retval(int **a,int m,int n, int i, int j){
    int count =0;
    if(i!=0){
        if(a[i-1][j]>0)
            count++;
        if(j<n-1){
            if(a[i-1][j+1]>0)
                count++;
        }
        if(j>0){
            if(a[i-1][j-1]>0)
                count++;
        }
    }
    
    if(i<m-1){
        if(a[i+1][j]>0)
            count++;
        if(j<n-1){
            if(a[i+1][j+1]>0)
                count++;
        }
        if(j>0){
            if(a[i+1][j-1]>0)
                count++;
        }
    }
    if(j<n-1){
        if(a[i][j+1]>0)
            count++;
    }
    if(j>0){
        if(a[i][j-1]>0)
            count++;
    }

    if(a[i][j]==0){
        if(count==3)
            return -1;
        else
            return 0;
    }
    else{
        if(count ==2 || count ==3)
            return 1;
        else 
            return 2;
    }
}

void gameOfLife(int** board, int m, int* bcs) {
    int n=bcs[0];
    for(int i=0;i<m;i++){

        for(int j=0;j<n;j++){
            board[i][j]=retval(board,m,n,i,j);
        }
    }

    for(int i=0;i<m;i++){

        for(int j=0;j<n;j++){
            printf("%d ",board[i][j]);
        }
        printf("\n");
    }

    for(int i=0;i<m;i++){

        for(int j=0;j<n;j++){
            if(board[i][j]==2)
                board[i][j]=0;
            else if(board[i][j]==-1)
                board[i][j]=1;
        }
    }
    
    return ;
}