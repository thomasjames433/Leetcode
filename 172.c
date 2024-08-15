int trailingZeroes(int n) {
    int c=0;
    for(int i=1;i<=n;i++){
        if(i%5==0){
            int j=i;
            while(j%5==0){
                c++;
                j=j/5;
            }
        }
    }
    return c;
}