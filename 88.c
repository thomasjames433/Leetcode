void merge(int* num1, int nums1Size, int m, int* num2, int nums2Size, int n) {
    int k=m+n-1;
    int a1=m-1;
    int a2=n-1;
    // printf("%d %d",a1,a2);
    while(1){
        if(k==-1)
            return;
        if(a1<0 || (a2>-1 && num2[a2]>num1[a1]) ){
            num1[k--]=num2[a2--];
            printf("%d ",num1[k+1]);
        }
        else if(a2<0 || (a1>-1 && num2[a2]<=num1[a1])){
            num1[k--]=num1[a1--];
            printf("%d ",num1[k+1]);
            
        }
    }
}