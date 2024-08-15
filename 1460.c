
bool canBeEqual(int* target, int ts, int* arr, int as) {
    int A[1001]; int B[1001];
    for(int i=0;i<1000;i++){
        A[i]=B[i]=0;
    }
    for(int i=0;i<ts;i++){
        A[arr[i]]++;
        B[target[i]]++;
    }
    
    for(int i=1;i<=1000;i++){
        if(A[i]!=B[i])
        return false;
    }
    return true;
}