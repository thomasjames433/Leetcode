int findJudge(int n, int** trust, int ts, int* trustColSize) {
    if(n==1)
        return 1;
    int **abc=(int*)malloc(1001*sizeof(int*));
    for(int i=0;i<(n+1);i++){
        abc[i]=(int*)malloc(2*sizeof(int));
        abc[i][0]=0;abc[i][1]=0;
    }
    for(int i=0;i<ts;i++){
        abc[trust[i][0]][0]++;
        abc[trust[i][1]][1]++;
    }
    
    for(int i=0;i<n+1;i++){
        if(!abc[i][0] && abc[i][1]==n-1)
            return i;
    }
    return -1;
}