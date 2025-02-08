int dp(int n,int *a){
    if(a[n])
        return a[n];
    else if(n==1)
        return 1;
    else if(n==2)
        return 2;
    int r=dp(n-1,a)+dp(n-2,a);
    a[n]=r;
    return r;
}

int climbStairs(int n) {
    int *a=(int*)calloc(n+1,sizeof(int));
    return dp(n,a);
}