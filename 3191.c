int minOperations(int* num, int n) {
    int c=0;
    for(int i=0;i<n-2;i++){
        if(num[i]==0){
            num[i]=1;
            num[i+1]=(num[i+1] +1)%2;
            num[i+2]=(num[i+2] +1)%2;
            c++;
        }
    }
    if(num[n-1]==0 || num[n-2]==0)
        return -1;
    return c;
}