/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** construct2DArray(int* original, int os, int m, int n, int* rs, int** cs) {
    int **ret=(int **)malloc(m*sizeof(int*));
    *cs=(int*)malloc(m*sizeof(int)); //*cs=(int**)malloc(m*sizeof(int*)); does not make a difference
    *rs=0;
    if(m*n!=os)
        return ret;
    while(*rs<m){
        int * a=(int *)malloc(n*sizeof(int));
        int x=(*rs)*n;
        for(int i=0;i<n;i++)
            a[i]=original[i +x];
        ret[*rs]=a;
        (*cs)[(*rs)++]=n;
    }
    return ret;
}