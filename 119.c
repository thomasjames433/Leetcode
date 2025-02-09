/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

 int* getRow(int n, int* rs) {
    int *a=(int*)malloc(1*sizeof(int));
    a[0]=1;
    *rs=n+1;
    for(int i=1;i<=n;i++){
        a=(int*)realloc(a,(i+1)*sizeof(int));
        a[i]=0;
        for(int j=i;j>0;j--){
            a[j]=a[j]+a[j-1];
            
        }
    }
    return a;
}