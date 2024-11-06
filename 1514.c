double dijstra(int **ass, int*size,double **weight,int n,int start,int end){
    int *visited=(int *)calloc(n,sizeof(int));
    visited[start]=1;
    double*prob=(double*)calloc(n,sizeof(double));
    prob[start]=1;
    while(start!=-1){
        if(start==end)
            return prob[end];
        visited[start]=1;
        for(int i=0;i<size[start];i++){
            if(weight[start][i] && prob[ass[start][i]]<prob[start]*weight[start][i] )
                prob[ass[start][i]]=prob[start]*weight[start][i];
        }
        double max=0;
        start=-1;
        for(int i=0;i<n;i++){
            if(!visited[i] && prob[i]>max){
                max=prob[i];
                start=i;
            }
        }
        if(start==-1)
            return 0;

    }
    return 0;
}


double maxProbability(int n, int** edge, int edgesize, int* ecs, double* succ, int succprobsize, int start, int end) {
    double **weight=(double**)calloc(n,sizeof(double*));
    int *size=(int *)calloc(n,sizeof(int));
    int **ass=(int**)calloc(n,sizeof(int*));
    for(int i=0;i<edgesize;i++){
        int x=edge[i][0];
        int y=edge[i][1];
        weight[x]=(double*)realloc(weight[x],(++size[x])*sizeof(double));
        weight[y]=(double*)realloc(weight[y],(++size[y])*sizeof(double));
        ass[x]=(int*)realloc(ass[x],(size[x])*sizeof(int));
        ass[y]=(int*)realloc(ass[y],(size[y])*sizeof(int));
        
        weight[x][size[x]-1]=succ[i];
        weight[y][size[y]-1]=succ[i];
        ass[x][size[x]-1]=y;
        ass[y][size[y]-1]=x;
    }
    return dijstra(ass,size,weight,n,start,end);
}