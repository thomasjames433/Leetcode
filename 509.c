int dp(int n,int *a){
    if(a[n])
        return a[n];
    if(n==1 || n==2)
        return 1;
    int result= dp(n-1,a)+dp(n-2,a);
    a[n]=result;
    return result;
}

int fib(int n){
    if(n==0)
        return 0;
    int *a=(int*)calloc((n+1),sizeof(int));
    return dp(n,a);
}

other method 


int fib(int n) {
    int a = 0, b = 1, c;

    if (n == 0 || n == 1)
        return n;

    for (int i = 2; i <= n; i++) {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}