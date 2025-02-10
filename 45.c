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


Other code 

int jump(int* nums, int numsSize) {
    if(numsSize <= 1)return 0;
    int jump = 0;
    int current = 0;
    int next = 0;
    for(int i = 0; i < numsSize; i++){
        if((i + nums[i]) > next){
            next = i + nums[i];
        }
        if(i == current){
            jump++;
            current = next;
            if(current >= (numsSize-1))return jump;
        }
    }
    return jump;
}