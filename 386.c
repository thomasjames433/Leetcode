/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
void abc(int *a,int *x, int num, int n){
    if(num>n)
        return;
    a[(*x)++]=num;
    abc(a,x,num*10,n);

    if((num+1)%10){
        abc(a,x,num+1,n);
    }
    return;
}

int* lexicalOrder(int n, int* rs) {
    int *a=(int*)malloc(n*sizeof(int));
    *rs=n;   
    int x=0;
    
    // for(int i=1;i<9;i++){
        abc(a,&x,1,n);
    // }
    return a;
}