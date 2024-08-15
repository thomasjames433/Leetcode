int canCompleteCircuit(int* gas, int gassize, int* cost, int costsize) {
    int net[gassize];
    for(int i=0;i<gassize;i++){
        net[i]=gas[i]-cost[i];
    }

    int i;
    int count=-1;
    for(i=0;i<gassize;i++){
        if(i<=count)
        break;
        if(net[i]>=0){
            count =i;
            int j=i;
            int sum=0;
            do{
                sum+=net[i];
                i++;
                if(i>=gassize)
                i=i%gassize;
                if(sum<0){
                break;
                }
                if(sum>=0 && i==j)
                return j;
            }while(i!=j);
        }


    }
    i--;
    int j=i;
    int sum=0;
            
    do{
        sum+=net[i];    
        i++;

        if(i>=gassize)
        i=i%gassize;
        if(sum<0){
        break;
        }
        if(sum>=0 && i==j)
        return j;
    }while(i!=j);
    
    return -1;
}

2'nd method
int canCompleteCircuit(int* gas, int gassize, int* cost, int costsize) {
    int i;
    for(i=0;i<=gassize;i++){
        if(i==gassize)
        return -1;
        if(gas[i]>=cost[i])
        break;
    }
    printf("%d",i);
    
    while(i<gassize-1 && gas[i]==gas[i+1]&&cost[i]==cost[i+1]){
        i++;
        if(i=gassize-1)
        break;
    }
    int j=i;
    
    while(j<gassize){
        i=j;
        int x=gas[i];
        do{
            if(x-cost[i%gassize]<0)
            break;
            x=x-cost[i%gassize]+gas[(i+1)%gassize];
            
            i++;
            if(i%gassize==j)
            return j;
        }while(i%gassize!=j);
        j++;

    }
    return -1;

}
