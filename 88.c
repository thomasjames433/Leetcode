void merge(int* num1, int num1Size, int m, int* num2, int num2Size, int n) {
    
    if(m==0 && n!=0){
        for(int i=0;i<n;i++)
        *(num1+i)=*(num2+i);
    }
    
    else if(m!=0 && n!=0){
        int A[m+n];
        int i=0; int j=0; int k=0;
        while(i<m && j<n){
            if(num1[i]<=num2[j]){
                A[k]=num1[i];
                i++;
            }
            else{
                A[k]=num2[j];
                j++;
            }
            k++;
        }
        if(i==m &&j<n){
            while(k<m+n){
                A[k]=num2[j];
                j++;
                k++;
            }
        }
        else if(j==n &&i<m){
            while(k<m+n){
                A[k]=num1[i];
                i++;
                k++;
            }
        }
        for(i=0;i<m+n;i++)
        num1[i]=A[i];    
    }
}