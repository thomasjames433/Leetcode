int tribonacci(int n) {
    if(n==0)
        return 0;
    else if(n<3)
        return 1;
    int a=0;
    int b=1;
    int c=1;
    int x=0;
    for(int i=3;i<=n;i++){
        x=c+a+b;
        a=b;
        b=c;
        c=x;
    }
    return x;
}