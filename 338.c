/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* countBits(int n, int* rs) {
    *rs=n+1;
    int *ret=(int*)malloc((n+1)*sizeof(int));
    ret [0]=0;
    for(int i=0;i<=n/2;i++){
        int x=2*i;
        int y=x+1;

        ret[x]=ret[i];
        if(y<n+1)
            ret[y]=ret[i]+1;
    }
    return ret;
}