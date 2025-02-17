int bs(int *a,int i,int j,int target){
    
    if(i>j)
        return 0;
    int mid=(i+j)/2;
    printf("%d ",mid);
    if(a[mid]==target)
        return 1;
    else if(a[mid]>target){
        return bs(a,i,mid-1,target);
    }

    else if(a[mid]<target){
        return bs(a,mid+1,j,target);
    }
    return 0;
}

bool searchMatrix(int** matrix, int m, int* mcs, int target) {
    int n=mcs[0]-1;
    int i=0;
    while(target>matrix[i][n]){
        i++;
        if(i==m)
            return 0;
    }
    if(target<matrix[i][0])
        return 0;
    return bs(matrix[i],0,n,target);
}