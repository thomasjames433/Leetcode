bool lemonadeChange(int* bill, int bs) {
    int count[2];
    count[0]=0;count[1]=0;

    for(int i=0;i<bs;i++){
        
        if(bill[i]==5)
            count[0]++;
        
        else if(bill[i]==10){
            if(count[0]==0)
                return false;
            else{
                count[0]--;
                count[1]++;
            }
        }
        
        else{
            if(count[0]==0)
                return false;
            else if(count[1]!=0){
                count[1]--;count[0]--;
            }
            else if(count[0]>=3)
                count[0]-=3;
            else{
                return false;
            }
        }
    }
return true;
}