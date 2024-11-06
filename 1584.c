int findminkey(int *key,int *visited,int n){
    int max=10000000;
    int ret=-1;
    for(int i=0;i<n;i++){
        if(!visited[i] &&key[i]<max){
            max=key[i];
            ret=i;
        }
    }
    visited[ret]=1;
    return ret;
}

int prims(int **a,int n){
    int ret=0;
    int *key=(int *)calloc(n,sizeof(int));
    for(int i=0;i<n;i++)
        key[i]=10000000;
    int *visited=(int*)calloc(n,sizeof(int));
    key[0]=0;
    for(int i=0;i<n;i++){
        int u=findminkey(key,visited,n);
        printf("%d ",u);
        for(int j=0;j<n;j++){
            if(!visited[j] && key[j]>a[u][j])
                key[j]=a[u][j];
        }
        ret+=key[u];
        // if(i==0){
        //     int k=findminkey(key,visited,n);
        //     for(int j=0;j<n;j++){
        //         if(!visited[j] && key[j]>a[k][j])
        //             key[j]=a[k][j];
        //     }
        //     ret+=a[u][k];
        // }
        // else{

        // }
    }
    return ret;
}

int minCostConnectPoints(int** point, int n, int* pcs) {
    int **a=(int**)malloc(n*sizeof(int*));
    for(int i=0;i<n;i++){
        a[i]=(int*)calloc(n,sizeof(int));
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            a[i][j]=abs(point[i][0]-point[j][0]) +abs(point[i][1]-point[j][1]);
        }
    }


    return prims(a,n);
}