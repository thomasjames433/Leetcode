void rotate(int* num, int numsize, int k) {

    k=k%numsize;
    if(k==0 || numsize==1)
        return;
    
    int A[k];
    for(int i=0;i<k;i++){
        A[i]=num[numsize+i-k];
    }
    for(int i=numsize-1; i>=k;i--){
        num[i]=num[i-k];
    }
    for(int i=0;i<k;i++){
        num[i]=A[i];
    }

}