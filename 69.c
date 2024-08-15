int bs(int l,int h,int x){
    if(l>h)
    return h;
    int a=l+(h-l)/2;
    if(a*a==x)
    return a;
    if(a*a<x ){
        return bs(a+1,h,x);
    }
    else if(a*a>x ){
        return bs(l,a-1,x);
    }
    else
    return a;

}
int mySqrt(int x) {
    if(x==0)
    return 0;
    if(x<4)
    return 1;
    if(x<9)
    return 2;
    return bs(1,46340,x);
}