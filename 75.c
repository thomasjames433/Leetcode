void sortColors(int* num, int numsize) {
    int A[3];
    for(int i=0;i<numsize;i++)
        A[num[i]]++;
    for(int i=0;i<A[0];i++)
        num[i]=0;
    for(int i=0;i<A[1];i++)
        num[A[0]+i]=1;
    for(int i=0;i<A[2];i++)
        num[A[0]+A[1]+i]=2;
    return;
}