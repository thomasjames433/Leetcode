/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** generate(int n, int* returnSize, int** rcs) {
    *returnSize=n;
    int **ret=(int**)malloc(n*sizeof(int*));
    (*rcs)=(int*)malloc(n*sizeof(int));
    for(int i=0;i<n;i++){
        (*rcs)[i]=i+1;
        ret[i]=(int*)malloc((i+1)*sizeof(int));
        ret[i][0]=1;
        ret[i][i]=1;
    }
    if(n<3)
        return ret;
    for(int i=2;i<n;i++){
        for(int j=1;j<i;j++){
            ret[i][j]=ret[i-1][j-1]+ret[i-1][j];
        }
    }
    return ret;
}