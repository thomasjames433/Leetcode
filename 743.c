int *dijkstra(int **a,int **weight,int *size,int n,int k){
    int *ret=(int*)malloc((n+1)*sizeof(int));
    for(int i=1;i<=n;i++)
        ret[i]=1000000;
    ret[k]=0;
    int *visited=(int*)calloc(n+1,sizeof(int));
    

    for(int i=0;i<n;i++){
        visited[k]=1;
        for(int j=0;j<size[k];j++){
            int nei=a[k][j];
            int len=weight[k][j];

            if(!visited[nei] && ret[nei]>len+ret[k])    
                ret[nei]=len+ret[k];
        }
        k=-1;
        int min=1000000;
        for(int x=1;x<=n;x++){
            if(!visited[x] && ret[x]<min){
                min=ret[x];
                k=x;
            }
        }
        if(k==-1)
            return ret;
    }
    return ret;
}

int networkDelayTime(int** time, int times, int* tcs, int n, int k){
    int **a=(int**)calloc(n+1,sizeof(int*));
    int **weight=(int**)calloc(n+1,sizeof(int*));
    int *size=(int*)calloc(n+1,sizeof(int));

    for(int i=0;i<times;i++){
        int x=time[i][0];
        a[x]=(int*)realloc(a[x],(++size[x])*sizeof(int));
        a[x][size[x]-1]=time[i][1];
        
        weight[x]=(int*)realloc(weight[x],size[x]*sizeof(int));
        weight[x][size[x]-1]=time[i][2];
    }

    int *ret=dijkstra(a,weight,size,n,k);
    int min=ret[1];
    for(int i=1;i<=n;i++){
        if(ret[i]==1000000)
            return -1;
        else if(ret[i]>min)
            min=ret[i];
    }
    return min;
}