/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* majorityElement(int* num, int n, int* rs) {
    // 2elements can appear more than n/3 times therefore
    int me1,me2,c1,c2;
    me1=me2=c1=c2=0;

    for(int i=0;i<n;i++){
        if(num[i]==me1){
            c1++;
        }
        else if(num[i]==me2){
            c2++;
        }
        else if(c1==0){
            me1=num[i];
            c1=1;
        }
        else if(c2==0){
            me2=num[i];
            c2=1;
        }
        else{
            c1--;
            c2--;
        }        
    }
    c1=0;c2=0;
    for(int i=0;i<n;i++){
        if(num[i]==me1)
            c1++;
        else if(num[i]==me2)
            c2++;
    }
    *rs=0;
    int *a=NULL;
    if(c1>n/3){
        a=(int*)realloc(a,(++(*rs))*sizeof(int));
        a[(*rs)-1]=me1;
    }

    if(c2>n/3){
        a=(int*)realloc(a,(++(*rs))*sizeof(int));
        a[(*rs)-1]=me2;
    }
    return a;
}