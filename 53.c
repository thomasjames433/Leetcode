int maxSubArray(int* num, int numsize) {
    int i=0;int max=num[0];
    while(i<numsize){
        int temp=0;
        while(i<numsize && num[i]<1){
            if(num[i]>max)
            max=num[i];
            i++;

        }
        if(i==numsize)
            return max;
        while(i<numsize && temp>=0){
            temp+=num[i];
            i++;
            if(temp>max)
            max=temp;
        }
        if(i==numsize)
            return max;

    }
    return max;
}