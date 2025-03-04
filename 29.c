int divide(int dividend, int divisor) {
    if(divisor==-1 && dividend==INT_MIN)
        return INT_MAX;
    if(divisor==1 && dividend==INT_MIN)
        return INT_MIN;
    int ret=0;
    int symbol=1;
    if((dividend<0 && divisor>0) || (dividend>0 && divisor<0) )
        symbol=-1;
    long long int DIVIDEND=llabs((long long) dividend);
    
    long long int DIVISOR=llabs((long long) divisor);

    while(DIVIDEND >=DIVISOR){
        
        long long int c=DIVISOR;
        long long int x=1;
        while(DIVIDEND>=c){
            
            c<<=1;
            x<<=1;
        }
        c>>=1;
        x>>=1;
        ret+=x;
        DIVIDEND-=c;
        
    }
    return symbol *ret;
}