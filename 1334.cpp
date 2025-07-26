class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int dt) {
        vector<vector<int>>graph(n,vector<int>(n,INT_MAX/2));
        for(int i=0;i<n;i++)
            graph[i][i]=0;
        for(auto it:edges){
            graph[it[0]][it[1]]=it[2];
            graph[it[1]][it[0]]=it[2];
        }
        floydwarshall(graph,n);
        pair<int,int>p={0,0};
        for(int i=0;i<n;i++){
            if(graph[0][i]<=dt)
                p.second++;
        }
        for(int j=1;j<n;j++){
            int x=0;
            for(int i=0;i<n;i++){
                if(graph[j][i]<=dt)
                    x++;
            }   
            if(x<=p.second)
                p={j,x};
        }
        return p.first;
            
    }
    void floydwarshall(vector<vector<int>>&graph,int n){

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                for(int k=0;k<n;k++){
                    if(j!=i && k!=i){
                        graph[j][k]=min(graph[j][k], graph[j][i]+graph[i][k]);
                    }
                }
            }
        }
    }
};


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