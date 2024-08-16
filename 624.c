int maxDistance(int** array, int arraysize, int* colsize) {
    int min1,min2,max1,max2;
    min1=0;min2=1;
    max1=0;max2=1;
    for(int i=1;i<arraysize;i++){
        if(array[i][0]<array[min1][0]){
            min2=min1;
            min1=i;
        }
        else if(array[i][0]<array[min2][0]){
            min2=i;
        }


        if(array[i][colsize[i]-1]>array[max1][colsize[max1]-1]){
            max2=max1;
            max1=i;
        }
        else if(array[i][colsize[i]-1]>array[max2][colsize[max2]-1]){
            max2=i;
        }

    }
    if(max1!=min1)
        return array[max1][colsize[max1]-1]-array[min1][0];
    else{
        if(array[max1][colsize[max1]-1]-array[min2][0]>array[max2][colsize[max2]-1]-array[min1][0])
            return array[max1][colsize[max1]-1]-array[min2][0]; 
        return array[max2][colsize[max2]-1]-array[min1][0];
    }
}