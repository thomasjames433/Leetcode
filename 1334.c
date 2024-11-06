int findTheCity(int n, int** edge, int edgesize, int* ecs, int dt) {
    int **a=(int**)malloc(n*sizeof(int*));
    for(int i=0;i<n;i++){
        a[i]=(int*)calloc(n,sizeof(int));
        for(int j=0;j<n;j++)
            a[i][j]=dt+5;    
    }
    for(int i=0;i<edgesize;i++){
        int x=edge[i][0];
        int y=edge[i][1];
        int wt=edge[i][2];

        a[x][y]=wt;
        a[y][x]=wt;
    }
    
    // for(int j=0;j<n;j++){
    //         for(int k=0;k<n;k++)
    //             printf("%d ",a[j][k]);
    //         printf("\n");
        
    // }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<n;k++){
                if(j!=i && k!=i && j!=k && a[j][k]>a[j][i]+a[i][k])
                    a[j][k]=a[j][i]+a[i][k];
            }
        }
    }

     for(int j=0;j<n;j++){
            for(int k=0;k<n;k++)
                printf("%d ",a[j][k]);
            printf("\n");
        
    }
    int ret=0;
    int min=n*n;
    for(int i=0;i<n;i++){
        int x=0;
        for(int j=0;j<n;j++){
            if(a[i][j]<=dt)
                x++;
        }
        // printf("%d ",x);
        if(x<=min){
            min=x;
            ret=i;
        }
    }
    return ret;
}