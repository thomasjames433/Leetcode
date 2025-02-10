int jump(int* nums, int n) {
    int *a=(int *)calloc(n,sizeof(int));
    a[0]=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<nums[i];j++){
            if(i+1+j<n && (a[i+1+j]==0 || a[i+1+j]>a[i]+1))
                a[i+1+j]=a[i]+1;
        }
    }
    return a[n-1];
}