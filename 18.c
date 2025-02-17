/**
 * Return an array ofa arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
 int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int** fourSum(int* num, int n, int target, int* rs, int** rcs) {
    *rcs=NULL;
    int **ret=NULL;
    *rs=0;

    qsort(num, n, sizeof(int), compare);

    for(int i=0;i<n-3;i++){
        if(i>0 && num[i]==num[i-1])
            continue;
        for(int j=i+1;j<n-2;j++){
            if(j>i+1 && num[j]==num[j-1])
                continue;
            int left=j+1;
            int right=n-1;
            
            while(left<right){
              long long int sum=(long long)num[i]+(long long)num[j]+(long long)num[left]+(long long)num[right];
              if(sum==target){
                    ret=(int**)realloc(ret,(++(*rs))*sizeof(int*));
                    *rcs=(int*)realloc(*rcs,(*rs)*sizeof(int));
                    int *a=(int*)malloc(4*sizeof(int));
                    a[0]=num[i];
                    a[1]=num[j];
                    a[2]=num[left];
                    a[3]=num[right];
                    ret[(*rs)-1]=a;
                    (*rcs)[(*rs)-1]=4;
                    
                    while(left<right && num[left]==num[left+1])
                        left++;
                    
                    while(left<right && num[right]==num[right-1])
                        right--;
                    left++;
                    right--;
                }
                else if(sum<target)
                    left++;
                else
                    right--;
            }
        }
    }
    return ret;
}