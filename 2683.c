bool doesValidArrayExist(int* derived, int n) {
    if(n==1){
        if(derived[0]==0)
            return 1;
        else
            return 0;
    }

    int *a=(int*)calloc(n,sizeof(int));
    for(int i=1;i<n-1;i++){
        if(derived[i-1]==1)
            a[i]=(a[i-1]+1)%2;
        else
            a[i]=a[i-1];
    }


    if(derived[n-1]==1)
        a[n-1]=1;
    else
        a[n-1]=0;
    

    if(a[n-1]^a[n-2]!=derived[n-2])
        return 0;
    
    return 1;
}