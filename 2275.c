int largestCombination(int* c, int n) {
    int max=-1;
    for(int i=0;i<n;i++){
        if(max<c[i])
            max=c[i];
    }
    int div=2;
    int maxno=1;
    while(0<max){
        int x=0;
        for(int i=0;i<n;i++){
            if(c[i]%2==1)
                x++;
            c[i]/=2;
        }
        max/=2;
        if(maxno<x)
            maxno=x;
    }
    return maxno;
}