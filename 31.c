void nextPermutation(int* num, int numsize) {
    int y=0;
    int j;
    for(int i=numsize-1;i>0;i--){
        if(num[i]>num[i-1]){
            for( j=numsize-1;j>=i;j--){
                
                if(num[j]>num[i-1]){
                    int x=num[i-1];
                    num[i-1]=num[j];
                    num[j]=x;
                    y=1;
                }
                if(y==1)
                break;
            }
            
            
        }

        if(y==1){
            while(i<numsize-1){
                int x=num[i];
                num[i]=num[numsize-1];
                num[numsize-1]=x;
                i++;numsize--;
            };
            break;
        }
        
    }
    if(y==0){
    for (int i=0;i<(numsize)/2;i++){
        int x=num[i];
        num[i]=num[numsize-1-i];
        num[numsize-1-i]=x;
    }
    }
}