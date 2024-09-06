int firstMissingPositive(int* num, int numsize) {
    int A[numsize+1];

    for(int i=0;i<numsize+1;i++)
        A[i]=0;

    for(int i=0;i<numsize;i++){
        if(num[i]>0){
            if( num[i]<numsize+1)
                A[num[i]]=1;
        }
    }
    int i;
    for(i=1;i<numsize+1;i++)
        if(A[i]==0)
            return i; 
    return i;
}