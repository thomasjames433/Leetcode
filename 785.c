int colour(int **graph,int n,int *gcs,int *visited,int i){
    int x=visited[i];
    for(int j=0;j<gcs[i];j++){
        if(!visited[graph[i][j]]){
            visited[graph[i][j]]=-x;
            int p=colour(graph,n,gcs,visited,graph[i][j]);
            if(!p)
                return 0;
        }
        else if(visited[graph[i][j]]==x)
            return 0;
    }
    return 1;
}

bool isBipartite(int** graph, int n, int* gcs) {
    int*visited=(int*)calloc(n,sizeof(int));
    
    for(int i=0;i<n;i++){
        if(!visited[i]){
            visited[i]=1;
            int x=colour(graph,n,gcs,visited,i);
            if(!x)
            return 0;
        }
    }

    return 1;
}