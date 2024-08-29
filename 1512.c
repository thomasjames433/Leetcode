int numIdenticalPairs(int* num, int numsize) {
    int A[101];
    for(int i=0;i<101;i++)
        A[i]=0;
    int n=0;
    for(int i=0;i<numsize;i++){
        A[num[i]]++;
        if(A[num[i]]>1){
            n=n+A[num[i]]-1;
        }
    }
    return n;
}