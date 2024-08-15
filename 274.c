int hIndex(int* num, int numsize) {
    
    int count,x=0;
    for(int i=0;i<numsize;i++){
        count=0;
        for(int j=0;j<numsize;j++){
            if(num[j]>i)
            count++;
            if(count>i)
            break;
        }
        if(x<count)
        x=count;
    }
    return x;
}