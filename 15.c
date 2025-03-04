/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

 int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}


int** threeSum(int* a, int n, int* rs, int** rcs) {
    qsort(a, n, sizeof(int), compare);
    // int **ret=NULL;
    int **ret=(int**)malloc(20000*sizeof(int*)); //dk why reaclloc is showing a problem
    *rs=0;
    (*rcs)=NULL;
    for(int i=0;i<n-2;i++){
        if(i!=0 && a[i]==a[i-1]) continue;

        int l=i+1;
        int r=n-1;
        while(l<r){
            if(a[i]+a[l]+a[r]==0){
                (*rs)++;
                // ret=(int**)realloc(ret,(*rs)*sizeof(int*));
                ret[(*rs)-1]=(int*)malloc(3*sizeof(int));
                ret[(*rs)-1][0]=a[i];
                ret[(*rs)-1][1]=a[l];
                ret[(*rs)-1][2]=a[r];

                *rcs=(int*)realloc(*rcs,(*rs)*sizeof(int));
                (*rcs)[(*rs)-1]=3;

                while(l<r && a[l]==a[l+1])
                    l++;
                while(l<r && a[r]==a[r-1])
                    r--;
                l++;
                r--;
            }   
            else if(a[i]+a[l]+a[r]>0){
                r--;
            } 
            else{
                l++;
            }
        }
    }
    return ret;
}