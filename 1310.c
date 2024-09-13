/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* xorQueries(int* arr, int as, int** q, int qs, int* qcs, int* rs) {
    for(int i=1;i<as;i++){
        arr[i]=arr[i]^arr[i-1];
    }
    *rs=qs;
    int *ret=(int*)malloc(qs*sizeof(int));

    for(int i=0;i<qs;i++){
        if(q[i][0]!=0)
        ret[i]=arr[q[i][0]-1]^arr[q[i][1]];
        else 
        ret[i]=arr[q[i][1]];
    }
    return ret;
}

/*
    *rs=qs;
    int *ret=(int*)malloc(qs*sizeof(int));

    for(int i=0;i<qs;i++){
        
        int a=q[i][0];
        int b=q[i][1];
        int x=arr[a];
        for(int j=a+1;j<=b;j++)
            x=x^arr[j];
        ret[i]=x;
    }
    return ret;
*/