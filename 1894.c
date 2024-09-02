int chalkReplacer(int* chalk, int chalksize, int k) {
    int sum=0;
    for(int i=0;i<chalksize;i++){        
        sum+=chalk[i];
        if(sum>k)
            return i;
    }
    k%=sum;
    sum=0;
    for(int i=0;i<chalksize;i++){        
        sum+=chalk[i];
        if(sum>k)
            return i;
    }
    return 1;
}