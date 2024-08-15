int Max(int A[],int n){
    int i=0;
    int max=A[i];
    for(i=1;i<n;i++){
        if(A[i]>max)
        max=A[i];
    }
    return max;
}

void Countsort(int A[],int n, int pos){
    int count[10]={0};
    for(int i=0;i<n;i++){
        count[(A[i]/pos)%10]++;
    }

    for(int i=1;i<10;i++){
        count[i]=count[i]+count[i-1];
    }
    int B[n];

    for(int i=n-1;i>=0;i--){
       B[--count[A[i]/pos%10]]=A[i];
    }
    for(int i=0;i<n;i++){
        A[i]=B[i];
    }
}

void Radixsort(int A[], int n){
    int max=Max(A,n);
    for(int pos=1;max/pos>0;pos=pos*10){
        Countsort(A,n,pos);
    }
   
}
int minIncrementForUnique(int* num, int numsize) {
    if(numsize==1)
    return 0;
    else if(numsize==2){
        if(num[0]!=num[1])
        return 0;
        else return 1;
    };
    
    Radixsort(num,numsize);
    int A[numsize];
    int count=0;
    for(int i=1;i<numsize;i++){
        if(num[i]<=num[i-1]){
            while(num[i]<=num[i-1]){
                num[i]++;
                count++;
            }
        }
    }
    return count;
    // for(int i=0;i<numsize;i++)
    //     printf("%d ",num[i]);
    // return 1;
}