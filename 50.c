double myPow(double x, int n) {
    if(n==0 || x==1 || (x==-1 && n%2==0))
    return 1;
    else if(x==-1)
    return -1;
    else if (n==1)
    return x;
    else if (n==-1)
    return 1/x;

    if(n==-2147483648)
    return 0;
    
    double a=1;
    if(n<-1){
        
        x=1/x;
        n=-n;
    }
    while(n>1){
        if(n%2==1){
            a*=x;
        }
        n=n/2;
        x=x*x;
    }
    return a*x;
    
}