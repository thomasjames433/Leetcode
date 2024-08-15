int maximum(int *price, int i,int pricesize){
    int max=i;
    while(i<pricesize){
        if(price[i]>price[max])
        max=i;
        i++;
    }
    return max;
}

int maxProfit(int* price, int pricesize) {
    int dif=0;
    int i=0;
    int min=0;int max=-1;
    while(i<pricesize){
        while(i < pricesize - 1 && price[i]>=price[i+1]){
            i++;
        //     if(i==pricesize-1)
        // break;
        }
        if(i>=pricesize-1)
        break;
        min=i;
        if(max<=i)
        max=maximum(price,i,pricesize);
        if(max==i){

        }
        else{
            if(dif<(price[max]-price[min]))
            dif=price[max]-price[min];
        }
        i++;
    }
    return dif;
}

Other method


int dif=0;
    int i=0;
    int min=price[0];
    for(int i=0;i<pricesize;i++){
        if(min>price[i]){
            min=price[i];
        }
        else{
            if(price[i]-min>dif)
            dif=price[i]-min;
        }
    }
    return dif;