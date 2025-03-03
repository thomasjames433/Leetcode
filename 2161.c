/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* pivotArray(int* num, int n, int pivot, int* rs) {
    int *a=(int*)malloc(n*sizeof(int*));
    int less=0;
    int equal=0;
    int great=0;
    for(int i=0;i<n;i++){
        if(num[i]==pivot)
            equal++;
        else if(num[i]<pivot)
            less++;
        else
            great++;
    }
    int l=0;
    int m=0;
    int r=0;
    for(int i=0;i<n;i++){
        if(num[i]<pivot)
            a[l++]=num[i];
        else if(num[i]==pivot)
            a[less+ (m++)]=num[i];
        else
            a[less+equal+ (r++)]=num[i];
    }
    *rs=n;
    return a;
}