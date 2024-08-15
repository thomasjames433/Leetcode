int removeElement(int* num, int numsize, int val) {
    if(numsize==0)
    return 0;
    if(numsize==1){
        if(*num==val)
        return 0;
        else return 1;
    }
    int count=0;numsize--;
    
    while(count<=numsize){
        if(num[count]==val){
            int x=num[count];
            num[count]=num[numsize];
            num[numsize]=x;
            numsize--;
            if(numsize==0 && num[0]==num[1])
            return 0;
        }
        else{
            count++;
        }
    }
    return count;
    
}