int maxProfit(int* num, int numsize) {
    // int lowest=0;
    // int highest=0;
    // for(int i=1;i<pricesize-1;i++){
    //     if(num[i]<num[lowest])
    //     lowest=i;
    //     else if(num[i]>num[highest])
    //     highest=i;
    // }
    // int sum=0;
    // i=0;
    if(numsize==1)
    return 0;
    int sum=0;
    if(numsize==2){
        if(num[0]<num[1])
        return num[1]-num[0];
        else return 0;
    }
    int i;
    for(i=0;i<numsize-2;i++){
        
        
        if(num[i]<num[i+1]){
            i++;
            int c=num[i-1];
            while(num[i+1]>=num[i]){
            i++;
            if(i>=numsize-1)
            break;
            }

            sum+=num[i]-c;
            
        }
        
    }
    if(i==numsize-2){
        if(num[numsize-2]<num[numsize-1])
        return sum- num[numsize-2]+num[numsize-1];
        else return sum;
    }
    return sum;
}