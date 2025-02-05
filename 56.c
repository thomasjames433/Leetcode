/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */


int compareIntervals(const void *a, const void *b) {
    const int *intervalA = *(const int **)a;
    const int *intervalB = *(const int **)b;
    
    // Compare first elements
    if (intervalA[0] != intervalB[0]) {
        return intervalA[0] - intervalB[0];
    }
    // If first elements are equal, compare second elements
    return intervalA[1] - intervalB[1];
}

int max(int a,int b){
    if(a>b)
        return a;
    return b;
}

int** merge(int** intervals, int n, int* intervalsColSize, int* rs, int** rcs) {
    // Sort the intervals based on their first element.
    qsort(intervals, n, sizeof(intervals[0]), compareIntervals);
    
    // for (int i = 0; i < n; i++) {
    //     printf("%d %d\n", intervals[i][0], intervals[i][1]);
    // }
    *rs=0;
    *(rcs)=(int*)calloc(n,sizeof(int));

    for(int i=0;i<n-1;i++){
        if(intervals[i][0]<=intervals[i+1][1] && intervals[i][1]>=intervals[i+1][0]){
            intervals[i+1][0]=intervals[i][0];
            intervals[i+1][1]=max(intervals[i+1][1],intervals[i][1]); 
        }
        else{
            (*rcs)[*rs]=2;
            intervals[(*rs)++]=intervals[i];
        }
    }
    (*rcs)[*rs]=2;        
    intervals[(*rs)++]=intervals[n-1];
    return intervals;
}
