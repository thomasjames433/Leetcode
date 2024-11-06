int recheck(int *edges,int i){
    int x=edges[i];
    int size=1;
    while(x!=i){
        x=edges[x];
        size++;
    }
    return size;
}

int check(int *edges,int *visited,int i){
    if(visited[i]==2)
        return -1;
    else if(visited[i]==1){
        return recheck(edges,i);
    }
    visited[i]=1;
    int ret=-1;
    if(edges[i]>-1)
        ret=check(edges,visited,edges[i]);
    visited[i]=2;
    return ret;
}

int longestCycle(int* edges, int n) {
    int *visited=(int*)calloc(n,sizeof(int));
    int max=-1;
    // for(int i=0;i<n;i++)
    //     printf("%d ",visited[i]);
    for(int i=0;i<n;i++){
        if(!visited[i]){
            int a=check(edges,visited,i);
            if(max<a)
                max=a;
        }
    }
    return max;
}