/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findMissingAndRepeatedValues(int** grid, int gridSize, int* gridColSize, int* returnSize) {
    long long int sum=0;
    long long int sqsum=0;
    long long int n=gridSize;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            sqsum+=grid[i][j]*grid[i][j];
            sum+=grid[i][j];
        }
    }
    
    n=n*n;
    
    sqsum=sqsum-n*(n+1)*(2*n+1)/6;
    sum=sum-n*(n+1)/2;
    
    sqsum=sqsum/sum;
    
    int *ret=(int*)malloc(2*sizeof(int));
    ret[0]=abs(sqsum+sum)/2;
    ret[1]=abs(sqsum-sum)/2;
    *returnSize=2;
    return ret;

}