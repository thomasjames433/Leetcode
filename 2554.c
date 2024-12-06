int maxCount(int* banned, int bannedsize, int n, int maxSum) {
    int *x=(int*)calloc(n+1,sizeof(int));
    for(int i=0;i<bannedsize;i++){
        if(banned[i]<n+1)
            x[banned[i]]=1;
    }
    int c=0;
    for(int i=1;i<=n;i++){
        if(!x[i]){
            c++;
            maxSum-=i;
            if(maxSum<0)
                return c-1;
        }
    }
    return c;
}