void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

void nextPermutation(int* num, int numsize) {
    int min=numsize-1;
    for(int i=numsize-1;i>0;i--){
        if(num[i]>num[i-1]){
            while(num[i-1]>=num[min]){
                min--;
            }

            swap(&num[i-1],&num[min]);
            int x=i;
            int y=numsize-1;
            while(x<y){
                swap(&num[x],&num[y]);
                x++;y--;
            }
            return;
        } 
        // else{
        //     min=i;
        // }
    }
    int x=0;
    int y=numsize-1;
    while(x<y){
        swap(&num[x],&num[y]);
        x++;y--;
    }
    return;
}