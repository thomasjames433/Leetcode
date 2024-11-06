int bfs(int **edges,int n,int *visited,int i){
    visited[i]=1;
    int x=1;int p=1;
    for(int j=0;j<n;j++){
        
        if(j!=i &&  (visited[j]==1 || visited[j]==2) && !edges[i][j]){
            visited[j]=2;
            visited[i]=2;
            p= 0;
        }

        if(edges[i][j] && !visited[j]){
            x=bfs(edges,n,visited,j);
            
        }

    }
    visited[i]=2;
    return x && p;
}

int countCompleteComponents(int n, int** edge, int es, int* ecs) {
    int **edges=(int**)calloc(n,sizeof(int*));
    
    for(int i=0;i<n;i++){
        edges[i]=(int*)calloc(n,sizeof(int));
    }

    for(int i=0;i<es;i++){
        int x=edge[i][0];
        int y=edge[i][1];
        edges[x][y]=1;
        edges[y][x]=1;
    }

    // for(int i=0;i<n;i++){
    //     for(int j=0;j<n;j++){
    //         printf("%d ",edges[i][j]);
    //     }
    //     printf("\n");
    // }

    int *visited=(int*)calloc(n,sizeof(int));
    int c=0;
    for(int i=0;i<n;i++){
        if(!visited[i]){
            
            // for(int j=0;j<n;j++)
            //     printf("%d ",visited[j]);
            // printf("\n");
            c+=bfs(edges,n,visited,i);
            for(int j=0;j<n;j++){
                if(visited[j]==2)
                    visited[j]=10;
            }
        }
    }
    return c;
}